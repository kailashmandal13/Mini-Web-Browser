%{
#include "AST.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cstdio>

int yylex();
void yyerror(const char *s);

ASTNode* root;
extern FILE *yyin;
%}

%union {
    char* str;
    ASTNode* node;
}

%token TEXT
%token OPEN_TAG CLOSE_TAG

%type <node> document element content elements
%type <str> TEXT OPEN_TAG CLOSE_TAG

%%

// Start of parsing
document:
    elements { 
        root = new ElementNode("root");  // Using a generic root node
        if ($1 != nullptr) {
            root->addChild($1);
        }
        std::cout << "Created root ElementNode.\n";
    }
    ;

elements:
    element elements { 
        if ($2 == nullptr) {
            $$ = $1;
        } else {
            $1->addChild($2);
            $$ = $1;
        }
    }
    | element { 
        $$ = $1; 
    }
    | /* empty */ { 
        $$ = nullptr; 
    }
    ;

element:
    OPEN_TAG content CLOSE_TAG {
        std::string openTag = std::string($1).substr(1, strlen($1) - 2);
        std::string closeTag = std::string($3).substr(2, strlen($3) - 3);

        std::cout << "Processed OPEN_TAG: " << $1 << "\n";
        std::cout << "Processed CLOSE_TAG: " << $3 << "\n";

        if (openTag == closeTag) {
            ElementNode* elem = new ElementNode($1);
            if ($2 != nullptr) {
                elem->addChild($2);
            }
            $$ = elem;
            std::cout << "Created ElementNode: " << $1 << "\n";
        } else {
            yyerror("Mismatched opening and closing tags");
            $$ = nullptr;
        }
        free($1);
        free($3);
    }
    | OPEN_TAG CLOSE_TAG {
        std::string openTag = std::string($1).substr(1, strlen($1) - 2);
        std::string closeTag = std::string($2).substr(2, strlen($2) - 3);

        std::cout << "Processed standalone OPEN_TAG: " << $1 << "\n";
        std::cout << "Processed standalone CLOSE_TAG: " << $2 << "\n";

        if (openTag == closeTag) {
            ElementNode* elem = new ElementNode($1);
            $$ = elem;
            std::cout << "Created standalone ElementNode: " << $1 << "\n";
        } else {
            yyerror("Mismatched opening and closing tags");
            $$ = nullptr;
        }
        free($1);
        free($2);
    }
    ;

content:
    content TEXT {
        std::cout << "Processed TEXT: " << $2 << "\n";
        if ($1 == nullptr) {
            $$ = new TextNode($2);
        } else {
            $1->addChild(new TextNode($2));
            $$ = $1;
        }
        free($2);
    }
    | content element {
        if ($1 == nullptr) {
            $$ = $2;
        } else {
            $1->addChild($2);
            $$ = $1;
        }
    }
    | TEXT {
        std::cout << "Processed single TEXT node: " << $1 << "\n";
        $$ = new TextNode($1);
        free($1);
    }
    | element {
        std::cout << "Processed single element inside content.\n";
        $$ = $1;
    }
    | /* empty */ {
        $$ = nullptr;
    }
    ;

%%

// Error handling function
void yyerror(const char *s) {
    std::cerr << "Error: " << s << std::endl;
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <html-file>\n";
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        std::cerr << "Error opening file: " << argv[1] << std::endl;
        return 1;
    }

    yyparse();
    printAST(root, 0);
    fclose(yyin);
    return 0;
}

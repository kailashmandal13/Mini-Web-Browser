%{
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include "ast.hpp"

extern FILE* yyin;
extern int yylex(void);
void yyerror(const char* s);
extern int yylineno;

ASTNode* root = nullptr;

#define YYDEBUG 1
%}

%union {
    char* text;
    int number;
    ASTNode* node;
}

%token HTML_START HTML_END HEAD_START HEAD_END TITLE_START TITLE_END
%token BODY_START BODY_END NAV_START NAV_END HEADER_START HEADER_END
%token <number> H_START H_END
%token P_START P_END SECTION_START SECTION_END
%token ARTICLE_START ARTICLE_END ASIDE_START ASIDE_END
%token FOOTER_START FOOTER_END UL_START UL_END OL_START OL_END
%token LI_START LI_END STRONG_START STRONG_END EM_START EM_END
%token PRE_START PRE_END BLOCKQUOTE_START BLOCKQUOTE_END
%token <text> A_START A_END IMG TEXT
%token DOCTYPE

%type <node> document html html_content head_content body_content body_elements body_element
%type <node> nav_element header_element section_element article_element
%type <node> aside_element footer_element p_element heading list list_items
%type <node> list_item link img_element formatted_element mixed_content text_content
%type <node> header_content header_item section_content article_content aside_content
%type <node> footer_content footer_item article_item
%type <node> aside_item
%type <node> title

%%

document:
    DOCTYPE html
    {
        auto* node = new ASTNode(NodeType::ROOT);
        if ($2) node->add_child($2);
        root = node;
        $$ = node;
    }
    ;

html:
    HTML_START html_content HTML_END
    {
        auto* node = new ASTNode(NodeType::HTML);
        if ($2) {
            for (auto* child : $2->children) {
                node->add_child(child);
            }
            $2->children.clear();
            delete $2;
        }
        $$ = node;
    }
    ;

html_content:
    head_content body_content
    {
        auto* node = new ASTNode(NodeType::CONTAINER);
        if ($1) node->add_child($1);
        if ($2) node->add_child($2);
        $$ = node;
    }
    ;

head_content:
    HEAD_START title HEAD_END
    {
        auto* node = new ASTNode(NodeType::HEAD);
        if ($2) node->add_child($2);
        $$ = node;
    }
    ;

title:
    TITLE_START TEXT TITLE_END
    {
        auto* node = new ASTNode(NodeType::TITLE);
        auto* text_node = new ASTNode(NodeType::TEXT);
        text_node->content = std::string($2);
        free($2);
        node->add_child(text_node);
        $$ = node;
    }
    ;

text_content:
    TEXT
    {
        auto* node = new ASTNode(NodeType::TEXT);
        node->content = std::string($1);
        free($1);
        $$ = node;
    }
    ;

mixed_content:
    text_content
    {
        $$ = $1;
    }
    | formatted_element
    {
        $$ = $1;
    }
    | link
    {
        $$ = $1;
    }
    | mixed_content text_content
    {
        if ($1->type == NodeType::PARAGRAPH) {
            $1->add_child($2);
            $$ = $1;
        } else {
            auto* node = new ASTNode(NodeType::PARAGRAPH);
            node->add_child($1);
            node->add_child($2);
            $$ = node;
        }
    }
    | mixed_content formatted_element
    {
        if ($1->type == NodeType::PARAGRAPH) {
            $1->add_child($2);
            $$ = $1;
        } else {
            auto* node = new ASTNode(NodeType::PARAGRAPH);
            node->add_child($1);
            node->add_child($2);
            $$ = node;
        }
    }
    | mixed_content link
    {
        auto* node = new ASTNode(NodeType::PARAGRAPH);
        if ($1) node->add_child($1);
        if ($2) node->add_child($2);
        $$ = node;
    }
    ;

body_content:
    BODY_START body_elements BODY_END
    {
        auto* node = new ASTNode(NodeType::BODY);
        if ($2) {
            if ($2->type == NodeType::BODY) {
                // Transfer children from existing BODY node
                for (auto* child : $2->children) {
                    node->add_child(child);
                }
                $2->children.clear();
                delete $2;
            } else {
                node->add_child($2);
            }
        }
        $$ = node;
    }
    ;

body_elements:
    body_element
    {
        auto* node = new ASTNode(NodeType::BODY);
        node->add_child($1);
        $$ = node;
    }
    | body_elements body_element
    {
        $1->add_child($2);
        $$ = $1;
    }
    ;

body_element:
    nav_element
    {
        $$ = $1;
    }
    | header_element
    {
        $$ = $1;
    }
    | section_element
    {
        $$ = $1;
    }
    | aside_element
    {
        $$ = $1;
    }
    | footer_element
    {
        $$ = $1;
    }
    ;

nav_element:
    NAV_START list NAV_END
    {
        auto* node = new ASTNode(NodeType::NAV);
        if ($2) node->add_child($2);
        $$ = node;
    }
    | NAV_START mixed_content NAV_END
    {
        auto* node = new ASTNode(NodeType::NAV);
        if ($2) node->add_child($2);
        $$ = node;
    }
    ;

header_element:
    HEADER_START header_content HEADER_END
    {
        auto* node = new ASTNode(NodeType::HEADER);
        if ($2) {
            // Transfer all children from header_content to header node
            for (auto* child : $2->children) {
                node->add_child(child);
            }
            $2->children.clear();  // Prevent double deletion
            delete $2;
        }
        $$ = node;
    }
    ;

header_content:
    header_item
    {
        auto* node = new ASTNode(NodeType::HEADER);
        node->add_child($1);
        $$ = node;
    }
    | header_content header_item
    {
        $1->add_child($2);
        $$ = $1;
    }
    ;

header_item:
    heading { $$ = $1; }
    | p_element { $$ = $1; }
    ;

section_element:
    SECTION_START section_content SECTION_END
    {
        auto* node = new ASTNode(NodeType::SECTION);
        if ($2) node->add_child($2);
        $$ = node;
    }
    ;

section_content:
    article_element
    {
        $$ = $1;
    }
    | section_content article_element
    {
        if (!$1) {
            $$ = $2;
        } else {
            $1->add_child($2);
            $$ = $1;
        }
    }
    ;

article_element:
    ARTICLE_START article_content ARTICLE_END
    {
        auto* node = new ASTNode(NodeType::ARTICLE);
        if ($2) {
            // Transfer all children from article_content to article node
            for (auto* child : $2->children) {
                node->add_child(child);
            }
            $2->children.clear();  // Prevent double deletion
            delete $2;
        }
        $$ = node;
    }
    ;

article_content:
    article_item
    {
        auto* node = new ASTNode(NodeType::ARTICLE);
        node->add_child($1);
        $$ = node;
    }
    | article_content article_item
    {
        $1->add_child($2);
        $$ = $1;
    }
    ;

aside_element:
    ASIDE_START aside_content ASIDE_END
    {
        $$ = $2;  // aside_content already creates ASIDE node
    }
    ;

aside_content:
    aside_item
    {
        auto* node = new ASTNode(NodeType::ASIDE);
        node->add_child($1);
        $$ = node;
    }
    | aside_content aside_item
    {
        $1->add_child($2);
        $$ = $1;
    }
    ;

footer_element:
    FOOTER_START footer_content FOOTER_END
    {
        $$ = $2;  // footer_content already creates FOOTER node
    }
    ;

footer_content:
    footer_item
    {
        auto* node = new ASTNode(NodeType::FOOTER);
        node->add_child($1);
        $$ = node;
    }
    | footer_content footer_item
    {
        $1->add_child($2);
        $$ = $1;
    }
    ;

footer_item:
    p_element { $$ = $1; }
    | img_element { $$ = $1; }
    ;

p_element:
    P_START mixed_content P_END
    {
        auto* node = new ASTNode(NodeType::PARAGRAPH);
        if ($2) {
            if ($2->type == NodeType::PARAGRAPH) {
                // Transfer children if mixed_content created a paragraph
                for (auto* child : $2->children) {
                    node->add_child(child);
                }
                $2->children.clear();
                delete $2;
            } else {
                node->add_child($2);
            }
        }
        $$ = node;
    }
    ;

heading:
    H_START mixed_content H_END
    {
        auto* node = new ASTNode(NodeType::HEADING);
        node->heading_level = $1;
        if ($2) {
            if ($2->type == NodeType::PARAGRAPH) {
                // Transfer children if mixed_content created a paragraph
                for (auto* child : $2->children) {
                    node->add_child(child);
                }
                $2->children.clear();
                delete $2;
            } else {
                node->add_child($2);
            }
        }
        $$ = node;
    }
    ;

list:
    UL_START list_items UL_END
    {
        $$ = $2;  // list_items already creates a LIST node
    }
    ;

list_items:
    list_item
    {
        auto* node = new ASTNode(NodeType::LIST);
        node->add_child($1);
        $$ = node;
    }
    | list_items list_item
    {
        $1->add_child($2);
        $$ = $1;
    }
    ;

list_item:
    LI_START mixed_content LI_END
    {
        auto* node = new ASTNode(NodeType::LIST_ITEM);
        if ($2) {
            if ($2->type == NodeType::PARAGRAPH) {
                // Transfer children if mixed_content created a paragraph
                for (auto* child : $2->children) {
                    node->add_child(child);
                }
                $2->children.clear();
                delete $2;
            } else {
                node->add_child($2);
            }
        }
        $$ = node;
    }
    ;

link:
    A_START mixed_content A_END
    {
        auto* node = new ASTNode(NodeType::LINK);
        node->attributes = std::string($1);
        if ($2) node->add_child($2);
        free($1);
        $$ = node;
    }
    ;

img_element:
    IMG
    {
        auto* node = new ASTNode(NodeType::IMAGE);
        node->attributes = std::string($1);
        free($1);
        $$ = node;
    }
    ;

formatted_element:
    STRONG_START mixed_content STRONG_END
    {
        auto* node = new ASTNode(NodeType::FORMATTED_TEXT);
        node->attributes = "type=\"strong\"";
        if ($2) {
            if ($2->type == NodeType::PARAGRAPH) {
                // Transfer children if mixed_content created a paragraph
                for (auto* child : $2->children) {
                    node->add_child(child);
                }
                $2->children.clear();
                delete $2;
            } else {
                node->add_child($2);
            }
        }
        $$ = node;
    }
    | EM_START mixed_content EM_END
    {
        auto* node = new ASTNode(NodeType::FORMATTED_TEXT);
        node->attributes = "type=\"emphasis\"";
        if ($2) {
            if ($2->type == NodeType::PARAGRAPH) {
                // Transfer children if mixed_content created a paragraph
                for (auto* child : $2->children) {
                    node->add_child(child);
                }
                $2->children.clear();
                delete $2;
            } else {
                node->add_child($2);
            }
        }
        $$ = node;
    }
    | PRE_START mixed_content PRE_END
    {
        auto* node = new ASTNode(NodeType::FORMATTED_TEXT);
        node->attributes = "type=\"preformatted\"";
        if ($2) {
            if ($2->type == NodeType::PARAGRAPH) {
                // Transfer children if mixed_content created a paragraph
                for (auto* child : $2->children) {
                    node->add_child(child);
                }
                $2->children.clear();
                delete $2;
            } else {
                node->add_child($2);
            }
        }
        $$ = node;
    }
    | BLOCKQUOTE_START mixed_content BLOCKQUOTE_END
    {
        auto* node = new ASTNode(NodeType::FORMATTED_TEXT);
        node->attributes = "type=\"blockquote\"";
        if ($2) {
            if ($2->type == NodeType::PARAGRAPH) {
                // Transfer children if mixed_content created a paragraph
                for (auto* child : $2->children) {
                    node->add_child(child);
                }
                $2->children.clear();
                delete $2;
            } else {
                node->add_child($2);
            }
        }
        $$ = node;
    }
    ;

article_item:
    heading
    {
        $$ = $1;
    }
    | p_element
    {
        $$ = $1;
    }
    | formatted_element
    {
        $$ = $1;
    }
    ;

aside_item:
    p_element
    {
        $$ = $1;
    }
    | list
    {
        $$ = $1;
    }
    ;

%%

void yyerror(const char* s) {
    extern int yylineno;
    extern char* yytext;
    std::cerr << "Parser error near line " << yylineno 
              << ": " << s << " at token '" << yytext << "'\n";
}

int main(int argc, char** argv) {
    if (argc > 1) {
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return 1;
        }
    }

    yyparse();

    if (root) {
        // Write AST to DOM.ast file
        std::ofstream dom_out("DOM.ast");
        if (!dom_out) {
            std::cerr << "Failed to open DOM.ast file" << std::endl;
            return 1;
        }

        root->print_ast_to_file(dom_out);
        dom_out.close();
        std::cout << "AST has been written to DOM.ast file" << std::endl;

        // Debug output to console
        std::cout << "\nDebug output to console:" << std::endl;
        root->print_ast();

        delete root;
    } else {
        std::cerr << "No AST was created (root is null)" << std::endl;
    }
    
    if (yyin != stdin) {
        fclose(yyin);
    }
    
    return 0;
}

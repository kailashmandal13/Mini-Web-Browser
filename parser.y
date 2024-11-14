%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern FILE* yyin;
extern int yylex(void);
void yyerror(const char* s);

ASTNode* root = NULL;

#define YYDEBUG 1
%}

%union {
    char* sval;
    int ival;
    struct ASTNode* node;
}

%token HTML_START HTML_END HEAD_START HEAD_END TITLE_START TITLE_END
%token BODY_START BODY_END NAV_START NAV_END HEADER_START HEADER_END
%token <ival> H_START H_END
%token P_START P_END SECTION_START SECTION_END
%token ARTICLE_START ARTICLE_END ASIDE_START ASIDE_END
%token FOOTER_START FOOTER_END UL_START UL_END OL_START OL_END
%token LI_START LI_END STRONG_START STRONG_END EM_START EM_END
%token PRE_START PRE_END BLOCKQUOTE_START BLOCKQUOTE_END
%token <sval> A_START A_END IMG TEXT

%type <node> document html_content head_content body_content body_elements body_element
%type <node> nav_element header_element section_element article_element aside_element
%type <node> footer_element p_element heading list list_items list_item link
%type <node> img_element formatted_text mixed_content text_content

%%

document:
    HTML_START html_content HTML_END
    {
        root = create_node(NODE_ROOT);
        add_child(root, $2);
        $$ = root;
    }
    ;

html_content:
    HEAD_START head_content HEAD_END BODY_START body_content BODY_END
    {
        $$ = create_node(NODE_HTML);
        if ($2) add_child($$, $2);
        if ($5) add_child($$, $5);
    }
    ;

head_content:
    TITLE_START mixed_content TITLE_END
    {
        $$ = create_node(NODE_HEAD);
        ASTNode* title = create_node(NODE_TITLE);
        add_child(title, $2);
        add_child($$, title);
    }
    | /* empty */ { $$ = NULL; }
    ;

text_content:
    TEXT
    {
        $$ = create_node(NODE_TEXT);
        $$->content = $1;
    }
    ;

mixed_content:
    text_content
    {
        $$ = $1;
    }
    | mixed_content text_content
    {
        if ($1 == NULL) {
            $$ = $2;
        } else {
            $$ = $1;
            if ($2) add_child($$, $2);
        }
    }
    | formatted_text
    {
        $$ = $1;
    }
    | mixed_content formatted_text
    {
        if ($1 == NULL) {
            $$ = $2;
        } else {
            $$ = $1;
            if ($2) add_child($$, $2);
        }
    }
    | link
    {
        $$ = $1;
    }
    | mixed_content link
    {
        if ($1 == NULL) {
            $$ = $2;
        } else {
            $$ = $1;
            if ($2) add_child($$, $2);
        }
    }
    ;

body_content:
    body_elements
    {
        $$ = create_node(NODE_BODY);
        if ($1) add_child($$, $1);
    }
    ;

body_elements:
    body_element
    {
        $$ = $1;
    }
    | body_elements body_element
    {
        if ($1 == NULL) {
            $$ = $2;
        } else {
            $$ = $1;
            if ($2) add_child($$, $2);
        }
    }
    ;

body_element:
    nav_element { $$ = $1; }
    | header_element { $$ = $1; }
    | section_element { $$ = $1; }
    | article_element { $$ = $1; }
    | aside_element { $$ = $1; }
    | footer_element { $$ = $1; }
    | p_element { $$ = $1; }
    | heading { $$ = $1; }
    | list { $$ = $1; }
    | link { $$ = $1; }
    | img_element { $$ = $1; }
    | formatted_text { $$ = $1; }
    | text_content { $$ = $1; }
    ;

nav_element:
    NAV_START body_elements NAV_END
    {
        $$ = create_node(NODE_NAV);
        if ($2) add_child($$, $2);
    }
    ;

header_element:
    HEADER_START body_elements HEADER_END
    {
        $$ = create_node(NODE_HEADER);
        if ($2) add_child($$, $2);
    }
    ;

section_element:
    SECTION_START body_elements SECTION_END
    {
        $$ = create_node(NODE_SECTION);
        if ($2) add_child($$, $2);
    }
    ;

article_element:
    ARTICLE_START body_elements ARTICLE_END
    {
        $$ = create_node(NODE_ARTICLE);
        if ($2) add_child($$, $2);
    }
    ;

aside_element:
    ASIDE_START body_elements ASIDE_END
    {
        $$ = create_node(NODE_ASIDE);
        if ($2) add_child($$, $2);
    }
    ;

footer_element:
    FOOTER_START body_elements FOOTER_END
    {
        $$ = create_node(NODE_FOOTER);
        if ($2) add_child($$, $2);
    }
    ;

p_element:
    P_START mixed_content P_END
    {
        $$ = create_node(NODE_PARAGRAPH);
        if ($2) add_child($$, $2);
    }
    ;

heading:
    H_START mixed_content H_END
    {
        $$ = create_node(NODE_HEADING);
        $$->heading_level = $1;
        if ($2) add_child($$, $2);
    }
    ;

list:
    UL_START list_items UL_END
    {
        $$ = create_node(NODE_LIST);
        if ($2) add_child($$, $2);
    }
    | OL_START list_items OL_END
    {
        $$ = create_node(NODE_LIST);
        if ($2) add_child($$, $2);
    }
    ;

list_items:
    list_item
    {
        $$ = $1;
    }
    | list_items list_item
    {
        if ($1 == NULL) {
            $$ = $2;
        } else {
            $$ = $1;
            if ($2) add_child($$, $2);
        }
    }
    ;

list_item:
    LI_START mixed_content LI_END
    {
        $$ = create_node(NODE_LIST_ITEM);
        if ($2) add_child($$, $2);
    }
    ;

link:
    A_START mixed_content A_END
    {
        $$ = create_node(NODE_LINK);
        $$->attributes = $1;
        if ($2) add_child($$, $2);
    }
    ;

img_element:
    IMG
    {
        $$ = create_node(NODE_IMAGE);
        $$->attributes = $1;
    }
    ;

formatted_text:
    STRONG_START mixed_content STRONG_END
    {
        $$ = create_node(NODE_FORMATTED_TEXT);
        if ($2) add_child($$, $2);
    }
    | EM_START mixed_content EM_END
    {
        $$ = create_node(NODE_FORMATTED_TEXT);
        if ($2) add_child($$, $2);
    }
    | PRE_START mixed_content PRE_END
    {
        $$ = create_node(NODE_FORMATTED_TEXT);
        if ($2) add_child($$, $2);
    }
    | BLOCKQUOTE_START mixed_content BLOCKQUOTE_END
    {
        $$ = create_node(NODE_FORMATTED_TEXT);
        if ($2) add_child($$, $2);
    }
    ;

%%

void yyerror(const char* s) {
    extern int yylineno;
    extern char* yytext;
    fprintf(stderr, "Parser error near line %d: %s at token '%s'\n", 
            yylineno, s, yytext);
}

int main(int argc, char** argv) {
    if (argc > 1) {
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return 1;
        }
    }

    // Parse the input
    yyparse();

    if (root) {
        // Open output file
        char output_file[256];
        snprintf(output_file, sizeof(output_file), "%s.ast", argv[1]);
        FILE* fp = fopen(output_file, "w");
        if (!fp) {
            perror("Failed to open output file");
            free_node(root);
            return 1;
        }

        // Print AST to file
        print_ast_to_file(fp, root, 0);
        fclose(fp);

        // Print to console for debugging
        printf("AST has been written to %s\n", output_file);
        printf("Debug output to console:\n");
        print_ast(root, 0);

        free_node(root);
    }
    return 0;
}
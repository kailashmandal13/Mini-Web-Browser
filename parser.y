%{
#include <cstdio>
#include <string>
#include "AST.h"

std::shared_ptr<HTMLNode> root;

void yyerror(const char* s) {
    fprintf(stderr, "Parse error: %s\n", s);
}

#define YYSTYPE std::shared_ptr<HTMLNode>
%}

// Define tokens
%token HTML_TAG HTML_TAG_CLOSE
%token HEAD_TAG HEAD_TAG_CLOSE
%token TITLE_TAG TITLE_TAG_CLOSE
%token BODY_TAG BODY_TAG_CLOSE
%token NAV_TAG NAV_TAG_CLOSE
%token UL_TAG UL_TAG_CLOSE
%token LI_TAG LI_TAG_CLOSE
%token A_TAG A_TAG_CLOSE
%token HEADER_TAG HEADER_TAG_CLOSE
%token H1_TAG H1_TAG_CLOSE
%token H2_TAG H2_TAG_CLOSE
%token H3_TAG H3_TAG_CLOSE
%token H4_TAG H4_TAG_CLOSE
%token H5_TAG H5_TAG_CLOSE
%token SECTION_TAG SECTION_TAG_CLOSE
%token ARTICLE_TAG ARTICLE_TAG_CLOSE
%token P_TAG P_TAG_CLOSE
%token STRONG_TAG STRONG_TAG_CLOSE
%token EM_TAG EM_TAG_CLOSE
%token PRE_TAG PRE_TAG_CLOSE
%token BLOCKQUOTE_TAG BLOCKQUOTE_TAG_CLOSE
%token ASIDE_TAG ASIDE_TAG_CLOSE
%token FOOTER_TAG FOOTER_TAG_CLOSE
%token IMG_TAG
%token TEXT_CONTENT

%start html

%%

// Grammar rules for the DOM structure

html:
    HTML_TAG head body HTML_TAG_CLOSE
    {
        root = std::make_shared<ElementNode>("html");
        root->addChild($2);
        root->addChild($3);
    }
;

head:
    HEAD_TAG title HEAD_TAG_CLOSE
    {
        auto headNode = std::make_shared<ElementNode>("head");
        headNode->addChild($2);
        $$ = headNode;
    }
;

title:
    TITLE_TAG TEXT_CONTENT TITLE_TAG_CLOSE
    {
        auto titleNode = std::make_shared<ElementNode>("title");
        titleNode->addChild(std::make_shared<TextNode>($2));
        $$ = titleNode;
    }
;

body:
    BODY_TAG elements BODY_TAG_CLOSE
    {
        auto bodyNode = std::make_shared<ElementNode>("body");
        bodyNode->addChild($2);
        $$ = bodyNode;
    }
;

elements:
    element elements
    {
        $$ = $2;
        $$->addChild($1);
    }
    |
    /* empty */
;

element:
    NAV_TAG nav_content NAV_TAG_CLOSE
    {
        auto navNode = std::make_shared<ElementNode>("nav");
        navNode->addChild($2);
        $$ = navNode;
    }
    | HEADER_TAG header_content HEADER_TAG_CLOSE
    {
        auto headerNode = std::make_shared<ElementNode>("header");
        headerNode->addChild($2);
        $$ = headerNode;
    }
    | P_TAG TEXT_CONTENT P_TAG_CLOSE
    {
        auto pNode = std::make_shared<ElementNode>("p");
        pNode->addChild(std::make_shared<TextNode>($2));
        $$ = pNode;
    }
;

nav_content:
    UL_TAG ul_content UL_TAG_CLOSE { $$ = $2; }
;

ul_content:
    LI_TAG a_content LI_TAG_CLOSE ul_content { $$ = $4; $$->addChild($2); }
    | /* empty */
;

a_content:
    A_TAG TEXT_CONTENT A_TAG_CLOSE
    {
        auto aNode = std::make_shared<ElementNode>("a");
        aNode->addChild(std::make_shared<TextNode>($2));
        $$ = aNode;
    }
;

header_content:
    H1_TAG TEXT_CONTENT H1_TAG_CLOSE
    {
        auto h1Node = std::make_shared<ElementNode>("h1");
        h1Node->addChild(std::make_shared<TextNode>($2));
        $$ = h1Node;
    }
;

%%

int main(int argc, char** argv) {
    yyparse();
    return 0;
}

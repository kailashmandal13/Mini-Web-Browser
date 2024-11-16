%{
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include "ast.hpp"

extern FILE* yyin;
extern int yylex(void);
extern char* yytext;
void yyerror(const char* s);
extern int yylineno;
ASTNode* root = nullptr;
#define YYDEBUG 1
%}

%union { char* text; int number; ASTNode* node; }

%token HTML_START HTML_END HEAD_START HEAD_END TITLE_START TITLE_END
%token BODY_START BODY_END NAV_START NAV_END HEADER_START HEADER_END
%token <number> H_START H_END
%token P_START P_END SECTION_START SECTION_END ARTICLE_START ARTICLE_END 
%token ASIDE_START ASIDE_END FOOTER_START FOOTER_END UL_START UL_END
%token OL_START OL_END
%token LI_START LI_END STRONG_START STRONG_END EM_START EM_END
%token PRE_START PRE_END BLOCKQUOTE_START BLOCKQUOTE_END
%token <text> A_START A_END IMG TEXT DOCTYPE
%token CODE_START CODE_END SMALL_START SMALL_END U_START U_END

%type <node> document html html_content head_content body_content body_elements body_element
%type <node> nav_element header_element section_element article_element aside_element footer_element
%type <node> p_element heading list list_items list_item link img_element formatted_element mixed_content
%type <node> text_content header_content header_item section_content article_content aside_content
%type <node> footer_content footer_item article_item aside_item title
%type <node> code_element small_element

%%

document: DOCTYPE html { auto* node = new ASTNode(NodeType::ROOT); if ($2) node->add_child($2); root = node; $$ = node; };

html: HTML_START html_content HTML_END {
    auto* node = new ASTNode(NodeType::HTML);
    if ($2) { for (auto* child : $2->children) node->add_child(child); $2->children.clear(); delete $2; }
    $$ = node;
};

html_content: head_content body_content {
    auto* node = new ASTNode(NodeType::CONTAINER);
    if ($1) node->add_child($1); if ($2) node->add_child($2); $$ = node;
};

head_content: HEAD_START title HEAD_END { auto* node = new ASTNode(NodeType::HEAD); if ($2) node->add_child($2); $$ = node; };

title: TITLE_START TEXT TITLE_END {
    auto* node = new ASTNode(NodeType::TITLE); auto* text_node = new ASTNode(NodeType::TEXT);
    text_node->content = std::string($2); free($2); node->add_child(text_node); $$ = node;
};

text_content: TEXT { auto* node = new ASTNode(NodeType::TEXT); node->content = std::string($1); free($1); $$ = node; };

mixed_content: text_content { $$ = $1; } 
    | formatted_element { $$ = $1; }
    | link { $$ = $1; }
    | mixed_content text_content {
        if ($1->type == NodeType::PARAGRAPH) { $1->add_child($2); $$ = $1; }
        else { auto* node = new ASTNode(NodeType::PARAGRAPH); node->add_child($1); node->add_child($2); $$ = node; }
    }
    | mixed_content formatted_element {
        if ($1->type == NodeType::PARAGRAPH) { $1->add_child($2); $$ = $1; }
        else { auto* node = new ASTNode(NodeType::PARAGRAPH); node->add_child($1); node->add_child($2); $$ = node; }
    }
    | mixed_content link {
        auto* node = new ASTNode(NodeType::PARAGRAPH);
        if ($1) node->add_child($1); if ($2) node->add_child($2); $$ = node;
    };

body_content: BODY_START body_elements BODY_END {
    auto* node = new ASTNode(NodeType::BODY);
    if ($2) {
        if ($2->type == NodeType::BODY) {
            for (auto* child : $2->children) node->add_child(child);
            $2->children.clear(); delete $2;
        } else node->add_child($2);
    }
    $$ = node;
};

body_elements: body_element { auto* node = new ASTNode(NodeType::BODY); node->add_child($1); $$ = node; } 
    | body_elements body_element { $1->add_child($2); $$ = $1; };

body_element: nav_element { $$ = $1; } | header_element { $$ = $1; } | section_element { $$ = $1; } 
    | aside_element { $$ = $1; } | footer_element { $$ = $1; } | list { $$ = $1; } | p_element { $$ = $1; } | code_element { $$ = $1; } | small_element { $$ = $1; };

nav_element: NAV_START list NAV_END { auto* node = new ASTNode(NodeType::NAV); if ($2) node->add_child($2); $$ = node; } 
    | NAV_START mixed_content NAV_END { auto* node = new ASTNode(NodeType::NAV); if ($2) node->add_child($2); $$ = node; };

header_element: HEADER_START header_content HEADER_END {
    auto* node = new ASTNode(NodeType::HEADER);
    if ($2) { for (auto* child : $2->children) node->add_child(child); $2->children.clear(); delete $2; }
    $$ = node;
};

header_content: header_item { auto* node = new ASTNode(NodeType::HEADER); node->add_child($1); $$ = node; } 
    | header_content header_item { $1->add_child($2); $$ = $1; };

header_item: heading { $$ = $1; } | p_element { $$ = $1; };

section_element: SECTION_START section_content SECTION_END { 
    auto* node = new ASTNode(NodeType::SECTION); if ($2) node->add_child($2); $$ = node; 
};

section_content: article_element { $$ = $1; } 
    | section_content article_element { if (!$1) $$ = $2; else { $1->add_child($2); $$ = $1; } };

article_element: ARTICLE_START article_content ARTICLE_END {
    auto* node = new ASTNode(NodeType::ARTICLE);
    if ($2) { for (auto* child : $2->children) node->add_child(child); $2->children.clear(); delete $2; }
    $$ = node;
};

article_content: article_item { auto* node = new ASTNode(NodeType::ARTICLE); node->add_child($1); $$ = node; } 
    | article_content article_item { $1->add_child($2); $$ = $1; };

aside_element: ASIDE_START aside_content ASIDE_END { $$ = $2; };

aside_content: aside_item { auto* node = new ASTNode(NodeType::ASIDE); node->add_child($1); $$ = node; } 
    | aside_content aside_item { $1->add_child($2); $$ = $1; };

footer_element: FOOTER_START footer_content FOOTER_END { $$ = $2; };

footer_content: footer_item { auto* node = new ASTNode(NodeType::FOOTER); node->add_child($1); $$ = node; } 
    | footer_content footer_item { $1->add_child($2); $$ = $1; };

footer_item: p_element { $$ = $1; } | img_element { $$ = $1; };

p_element: P_START mixed_content P_END {
    auto* node = new ASTNode(NodeType::PARAGRAPH);
    if ($2) {
        if ($2->type == NodeType::PARAGRAPH) {
            for (auto* child : $2->children) node->add_child(child);
            $2->children.clear(); delete $2;
        } else node->add_child($2);
    }
    $$ = node;
};

heading: H_START mixed_content H_END {
    auto* node = new ASTNode(NodeType::HEADING); node->heading_level = $1;
    if ($2) {
        if ($2->type == NodeType::PARAGRAPH) {
            for (auto* child : $2->children) node->add_child(child);
            $2->children.clear(); delete $2;
        } else node->add_child($2);
    }
    $$ = node;
};

list: UL_START list_items UL_END { 
    auto* node = new ASTNode(NodeType::LIST); 
    if ($2) {
        for (auto* child : $2->children) node->add_child(child);
        $2->children.clear(); delete $2;
    }
    node->attributes = "type=\"unordered\""; 
    $$ = node; 
} | OL_START list_items OL_END { 
    auto* node = new ASTNode(NodeType::LIST); 
    if ($2) {
        for (auto* child : $2->children) node->add_child(child);
        $2->children.clear(); delete $2;
    }
    node->attributes = "type=\"ordered\""; 
    $$ = node; 
};

list_items: list_item { 
    auto* node = new ASTNode(NodeType::CONTAINER); 
    if ($1) node->add_child($1); 
    $$ = node; 
} | list_items list_item { 
    if ($1 && $2) $1->add_child($2); 
    $$ = $1; 
};

list_item: LI_START mixed_content LI_END {
    auto* node = new ASTNode(NodeType::LIST_ITEM);
    if ($2) {
        if ($2->type == NodeType::PARAGRAPH) {
            for (auto* child : $2->children) node->add_child(child);
            $2->children.clear(); delete $2;
        } else node->add_child($2);
    }
    $$ = node;
};

link: A_START mixed_content A_END {
    auto* node = new ASTNode(NodeType::LINK); node->attributes = std::string($1);
    if ($2) node->add_child($2); free($1); $$ = node;
};

img_element: IMG { auto* node = new ASTNode(NodeType::IMAGE); node->attributes = std::string($1); free($1); $$ = node; };

formatted_element: STRONG_START mixed_content STRONG_END {
    auto* node = new ASTNode(NodeType::FORMATTED_TEXT); node->attributes = "type=\"strong\"";
    if ($2) {
        if ($2->type == NodeType::PARAGRAPH) {
            for (auto* child : $2->children) node->add_child(child);
            $2->children.clear(); delete $2;
        } else node->add_child($2);
    }
    $$ = node;
} | EM_START mixed_content EM_END {
    auto* node = new ASTNode(NodeType::FORMATTED_TEXT); node->attributes = "type=\"emphasis\"";
    if ($2) {
        if ($2->type == NodeType::PARAGRAPH) {
            for (auto* child : $2->children) node->add_child(child);
            $2->children.clear(); delete $2;
        } else node->add_child($2);
    }
    $$ = node;
} | PRE_START mixed_content PRE_END {
    auto* node = new ASTNode(NodeType::FORMATTED_TEXT); node->attributes = "type=\"preformatted\"";
    if ($2) {
        if ($2->type == NodeType::PARAGRAPH) {
            for (auto* child : $2->children) node->add_child(child);
            $2->children.clear(); delete $2;
        } else node->add_child($2);
    }
    $$ = node;
} | BLOCKQUOTE_START mixed_content BLOCKQUOTE_END {
    auto* node = new ASTNode(NodeType::FORMATTED_TEXT); node->attributes = "type=\"blockquote\"";
    if ($2) {
        if ($2->type == NodeType::PARAGRAPH) {
            for (auto* child : $2->children) node->add_child(child);
            $2->children.clear(); delete $2;
        } else node->add_child($2);
    }
    $$ = node;
} | SMALL_START mixed_content SMALL_END {
    auto* node = new ASTNode(NodeType::FORMATTED_TEXT);
    node->attributes = "type=\"small\"";
    if ($2) {
        if ($2->type == NodeType::PARAGRAPH) {
            for (auto* child : $2->children) node->add_child(child);
            $2->children.clear(); delete $2;
        } else node->add_child($2);
    }
    $$ = node;
} | CODE_START mixed_content CODE_END {
    auto* node = new ASTNode(NodeType::FORMATTED_TEXT); 
    node->attributes = "type=\"code\"";
    if ($2) {
        if ($2->type == NodeType::PARAGRAPH) {
            for (auto* child : $2->children) node->add_child(child);
            $2->children.clear(); delete $2;
        } else node->add_child($2);
    }
    $$ = node;
} | U_START mixed_content U_END {
    auto* node = new ASTNode(NodeType::FORMATTED_TEXT); 
    node->attributes = "type=\"underline\"";
    if ($2) {
        if ($2->type == NodeType::PARAGRAPH) {
            for (auto* child : $2->children) node->add_child(child);
            $2->children.clear(); delete $2;
        } else node->add_child($2);
    }
    $$ = node;
};

article_item: heading { $$ = $1; } | p_element { $$ = $1; } | formatted_element { $$ = $1; };

aside_item: p_element { $$ = $1; } | list { $$ = $1; };

code_element: CODE_START mixed_content CODE_END {
    auto* node = new ASTNode(NodeType::FORMATTED_TEXT);
    node->attributes = "type=\"code\"";
    if ($2) {
        if ($2->type == NodeType::PARAGRAPH) {
            for (auto* child : $2->children) node->add_child(child);
            $2->children.clear(); delete $2;
        } else node->add_child($2);
    }
    $$ = node;
} | CODE_START TEXT CODE_END {
    auto* node = new ASTNode(NodeType::FORMATTED_TEXT);
    node->attributes = "type=\"code\"";
    auto* text_node = new ASTNode(NodeType::TEXT);
    text_node->content = std::string($2);
    free($2);
    node->add_child(text_node);
    $$ = node;
};

small_element: SMALL_START mixed_content SMALL_END {
    auto* node = new ASTNode(NodeType::FORMATTED_TEXT);
    node->attributes = "type=\"small\"";
    if ($2) {
        if ($2->type == NodeType::PARAGRAPH) {
            for (auto* child : $2->children) node->add_child(child);
            $2->children.clear(); delete $2;
        } else node->add_child($2);
    }
    $$ = node;
} | SMALL_START TEXT SMALL_END {
    auto* node = new ASTNode(NodeType::FORMATTED_TEXT);
    node->attributes = "type=\"small\"";
    auto* text_node = new ASTNode(NodeType::TEXT);
    text_node->content = std::string($2);
    free($2);
    node->add_child(text_node);
    $$ = node;
};

%%

void yyerror(const char* s) {
    std::cerr << "Parser error near line " << yylineno << ": " << s << " at token '" << yytext << "'\n";
}

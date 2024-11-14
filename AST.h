#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    NODE_ROOT,
    NODE_HTML,
    NODE_HEAD,
    NODE_TITLE,
    NODE_BODY,
    NODE_NAV,
    NODE_HEADER,
    NODE_SECTION,
    NODE_ARTICLE,
    NODE_ASIDE,
    NODE_FOOTER,
    NODE_HEADING,
    NODE_PARAGRAPH,
    NODE_LIST,
    NODE_LIST_ITEM,
    NODE_LINK,
    NODE_IMAGE,
    NODE_TEXT,
    NODE_FORMATTED_TEXT
} NodeType;

typedef struct ASTNode {
    NodeType type;
    char* content;
    char* attributes;
    int heading_level;
    struct ASTNode** children;
    int num_children;
    int max_children;
} ASTNode;

ASTNode* create_node(NodeType type);
void add_child(ASTNode* parent, ASTNode* child);
void free_node(ASTNode* node);
void print_ast(ASTNode* node, int depth);
void print_ast_to_file(FILE* fp, ASTNode* node, int depth);

#endif
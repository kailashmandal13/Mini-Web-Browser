#include "ast.h"
#include <stdio.h>

// Helper function to get node type as string
const char* get_node_type_str(NodeType type) {
    switch(type) {
        case NODE_ROOT: return "ROOT";
        case NODE_HTML: return "HTML";
        case NODE_HEAD: return "HEAD";
        case NODE_TITLE: return "TITLE";
        case NODE_BODY: return "BODY";
        case NODE_NAV: return "NAV";
        case NODE_HEADER: return "HEADER";
        case NODE_SECTION: return "SECTION";
        case NODE_ARTICLE: return "ARTICLE";
        case NODE_ASIDE: return "ASIDE";
        case NODE_FOOTER: return "FOOTER";
        case NODE_HEADING: return "HEADING";
        case NODE_PARAGRAPH: return "PARAGRAPH";
        case NODE_LIST: return "LIST";
        case NODE_LIST_ITEM: return "LIST_ITEM";
        case NODE_LINK: return "LINK";
        case NODE_IMAGE: return "IMAGE";
        case NODE_TEXT: return "TEXT";
        case NODE_FORMATTED_TEXT: return "FORMATTED_TEXT";
        default: return "UNKNOWN";
    }
}

// Print AST to file with proper indentation
void print_ast_to_file(FILE* fp, ASTNode* node, int depth) {
    if (!node) return;

    // Print indentation
    for (int i = 0; i < depth; i++) {
        fprintf(fp, "  ");
    }

    // Print node type
    fprintf(fp, "%s", get_node_type_str(node->type));

    // Print additional node information
    if (node->heading_level > 0) {
        fprintf(fp, " (h%d)", node->heading_level);
    }
    if (node->content) {
        fprintf(fp, ": \"%s\"", node->content);
    }
    if (node->attributes) {
        fprintf(fp, " [%s]", node->attributes);
    }
    fprintf(fp, "\n");

    // Print children
    for (int i = 0; i < node->num_children; i++) {
        print_ast_to_file(fp, node->children[i], depth + 1);
    }
}

// Original functions remain the same
ASTNode* create_node(NodeType type) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->content = NULL;
    node->attributes = NULL;
    node->heading_level = 0;
    node->children = NULL;
    node->num_children = 0;
    node->max_children = 0;
    return node;
}

void add_child(ASTNode* parent, ASTNode* child) {
    if (!parent || !child) return;
    
    if (parent->num_children >= parent->max_children) {
        int new_size = parent->max_children == 0 ? 4 : parent->max_children * 2;
        parent->children = realloc(parent->children, new_size * sizeof(ASTNode*));
        parent->max_children = new_size;
    }
    parent->children[parent->num_children++] = child;
}

void free_node(ASTNode* node) {
    if (!node) return;
    
    free(node->content);
    free(node->attributes);
    
    for (int i = 0; i < node->num_children; i++) {
        free_node(node->children[i]);
    }
    free(node->children);
    free(node);
}

// Keep the original print_ast for debugging
void print_ast(ASTNode* node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; i++) printf("  ");
    printf("%s", get_node_type_str(node->type));
    if (node->heading_level > 0) printf(" (h%d)", node->heading_level);
    if (node->content) printf(": \"%s\"", node->content);
    if (node->attributes) printf(" [%s]", node->attributes);
    printf("\n");
    for (int i = 0; i < node->num_children; i++) {
        print_ast(node->children[i], depth + 1);
    }
} 
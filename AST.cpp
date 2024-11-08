#include "AST.h"
#include <iostream>

// Recursive function to print the AST
void printAST(ASTNode* node, int depth) {
    if (!node) return;

    std::string indent(depth * 2, ' '); // Indentation for hierarchy
    std::cout << indent << node->getName();

    if (auto textNode = dynamic_cast<TextNode*>(node)) {
        std::cout << ": " << textNode->text;
    }

    std::cout << std::endl;

    if (auto elementNode = dynamic_cast<ElementNode*>(node)) {
        for (ASTNode* child : elementNode->children) {
            if (child) { // Check for non-null child nodes
                printAST(child, depth + 1);
            }
        }
    }
}

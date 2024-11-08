#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

// Abstract base class for AST nodes
class ASTNode {
public:
    virtual ~ASTNode() = default; // Default destructor
    virtual std::string getName() const = 0; // Get the name of the node
    virtual void addChild(ASTNode* child) = 0; // Add a child node
};

// Class for element nodes
class ElementNode : public ASTNode {
public:
    std::string name; // Name of the element
    std::vector<ASTNode*> children; // Children of this element

    ElementNode(const std::string& n) : name(n) {} // Constructor

    std::string getName() const override { return name; } // Override getName

    void addChild(ASTNode* child) override {
        children.push_back(child); // Add child to the vector
    }
};

// Class for text nodes
class TextNode : public ASTNode {
public:
    std::string text; // Text content

    TextNode(const std::string& t) : text(t) {} // Constructor

    std::string getName() const override { return "Text"; } // Override getName

    void addChild(ASTNode* child) override {
        // Text nodes do not have children, so do nothing
    }
};

// Function to print the AST
void printAST(ASTNode* node, int depth);

#endif // AST_H

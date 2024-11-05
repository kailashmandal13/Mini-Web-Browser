#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>

// Base class for all nodes in the DOM tree
class HTMLNode {
public:
    virtual ~HTMLNode() {}
    virtual void print(int depth = 0) const = 0;  // Pure virtual function for printing
};

// Class for HTML element nodes (e.g., <div>, <p>)
class ElementNode : public HTMLNode {
public:
    std::string tagName;
    std::vector<std::shared_ptr<HTMLNode>> children;

    ElementNode(const std::string& name) : tagName(name) {}

    void addChild(std::shared_ptr<HTMLNode> child) {
        children.push_back(child);
    }

    // Print function to visualize the DOM structure
    void print(int depth = 0) const override {
        std::cout << std::string(depth * 2, ' ') << "<" << tagName << ">" << std::endl;
        for (const auto& child : children) {
            child->print(depth + 1);
        }
        std::cout << std::string(depth * 2, ' ') << "</" << tagName << ">" << std::endl;
    }
};

// Class for text nodes
class TextNode : public HTMLNode {
public:
    std::string textContent;

    TextNode(const std::string& text) : textContent(text) {}

    // Print function to visualize text within the DOM structure
    void print(int depth = 0) const override {
        std::cout << std::string(depth * 2, ' ') << textContent << std::endl;
    }
};

#endif // AST_H

#ifndef AST_HPP
#define AST_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

enum class NodeType {
    ROOT,
    HTML,
    HEAD,
    TITLE,
    BODY,
    NAV,
    HEADER,
    SECTION,
    ARTICLE,
    ASIDE,
    FOOTER,
    HEADING,
    PARAGRAPH,
    LIST,
    LIST_ITEM,
    LINK,
    IMAGE,
    TEXT,
    FORMATTED_TEXT,
    CONTAINER
};

struct ASTNode {
    NodeType type;
    std::string content;
    std::string attributes;
    int heading_level;
    std::vector<ASTNode*> children;
    
    ASTNode(NodeType t) : type(t), heading_level(0) {}
    
    void add_child(ASTNode* child) {
        if (child) children.push_back(child);
    }

    void print_ast(int indent = 0) const {
        std::string indent_str(indent * 2, ' ');
        std::cout << indent_str << to_string() << std::endl;
        for (const auto* child : children) {
            if (child) child->print_ast(indent + 1);
        }
    }

    void print_ast_to_file(std::ofstream& out, int indent = 0) const {
        std::string indent_str(indent * 2, ' ');
        out << indent_str << to_string() << std::endl;
        for (const auto* child : children) {
            if (child) child->print_ast_to_file(out, indent + 1);
        }
    }

private:
    std::string to_string() const {
        std::string result;
        switch (type) {
            case NodeType::ROOT: result = "ROOT"; break;
            case NodeType::HTML: result = "HTML"; break;
            case NodeType::HEAD: result = "HEAD"; break;
            case NodeType::TITLE: result = "TITLE"; break;
            case NodeType::BODY: result = "BODY"; break;
            case NodeType::NAV: result = "NAV"; break;
            case NodeType::HEADER: result = "HEADER"; break;
            case NodeType::SECTION: result = "SECTION"; break;
            case NodeType::ARTICLE: result = "ARTICLE"; break;
            case NodeType::ASIDE: result = "ASIDE"; break;
            case NodeType::FOOTER: result = "FOOTER"; break;
            case NodeType::HEADING: 
                result = "HEADING (h" + std::to_string(heading_level) + ")"; 
                break;
            case NodeType::PARAGRAPH: result = "PARAGRAPH"; break;
            case NodeType::LIST: result = "LIST"; break;
            case NodeType::LIST_ITEM: result = "LIST_ITEM"; break;
            case NodeType::LINK: result = "LINK " + attributes; break;
            case NodeType::IMAGE: result = "IMAGE " + attributes; break;
            case NodeType::TEXT: result = "TEXT: \"" + content + "\""; break;
            case NodeType::FORMATTED_TEXT: 
                result = "FORMATTED_TEXT " + attributes; 
                break;
            case NodeType::CONTAINER: result = "CONTAINER"; break;
        }
        return result;
    }
};

#endif // AST_HPP 
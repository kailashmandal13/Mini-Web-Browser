#include "ast.hpp"
#include <iostream>

ASTNode::ASTNode(NodeType t) : type(t), heading_level(0) {}

ASTNode::~ASTNode() {
    for (auto* child : children) {
        delete child;
    }
    children.clear();
}

void ASTNode::add_child(ASTNode* child) {
    if (child) {
        children.push_back(child);
    }
}

std::string ASTNode::get_node_type_str(NodeType type) {
    switch (type) {
        case NodeType::ROOT: return "ROOT";
        case NodeType::HTML: return "HTML";
        case NodeType::HEAD: return "HEAD";
        case NodeType::TITLE: return "TITLE";
        case NodeType::BODY: return "BODY";
        case NodeType::NAV: return "NAV";
        case NodeType::HEADER: return "HEADER";
        case NodeType::SECTION: return "SECTION";
        case NodeType::ARTICLE: return "ARTICLE";
        case NodeType::ASIDE: return "ASIDE";
        case NodeType::FOOTER: return "FOOTER";
        case NodeType::HEADING: return "HEADING";
        case NodeType::PARAGRAPH: return "PARAGRAPH";
        case NodeType::LIST: return "LIST";
        case NodeType::LIST_ITEM: return "LIST_ITEM";
        case NodeType::LINK: return "LINK";
        case NodeType::IMAGE: return "IMAGE";
        case NodeType::TEXT: return "TEXT";
        case NodeType::FORMATTED_TEXT: return "FORMATTED_TEXT";
        case NodeType::CONTAINER: return "CONTAINER";
        default: return "UNKNOWN";
    }
}

void ASTNode::print_ast_to_file(std::ofstream& out, int depth) const {
    std::string indent(depth * 2, ' ');
    out << indent << get_node_type_str(type);
    
    if (type == NodeType::HEADING) {
        out << " (h" << heading_level << ")";
    }
    if (!attributes.empty()) {
        out << " [" << attributes << "]";
    }
    if (!content.empty()) {
        out << ": \"" << content << "\"";
    }
    out << "\n";

    for (const auto* child : children) {
        if (child) {
            child->print_ast_to_file(out, depth + 1);
        }
    }
}

void ASTNode::print_ast(int depth) const {
    std::string indent(depth * 2, ' ');
    std::cout << indent << get_node_type_str(type);
    
    if (type == NodeType::HEADING) {
        std::cout << " (h" << heading_level << ")";
    }
    if (!attributes.empty()) {
        std::cout << " [" << attributes << "]";
    }
    if (!content.empty()) {
        std::cout << ": \"" << content << "\"";
    }
    std::cout << "\n";

    for (const auto* child : children) {
        if (child) {
            child->print_ast(depth + 1);
        }
    }
}

std::string ASTNode::get_dom_node_str() const {
    return get_node_type_str(type);
}

void ASTNode::print_dom(std::ofstream& out, int depth) const {
    std::string indent(depth * 2, ' ');
    out << indent << get_dom_node_str();
    if (!content.empty()) {
        out << ": " << content;
    }
    out << "\n";
    
    for (const auto* child : children) {
        if (child) {
            child->print_dom(out, depth + 1);
        }
    }
} 
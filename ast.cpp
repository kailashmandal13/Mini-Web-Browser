#include "ast.hpp"

ASTNode::ASTNode(NodeType t) 
    : type(t), heading_level(0) {}

ASTNode::~ASTNode() {
    for (ASTNode* child : children) {
        delete child;
    }
}

void ASTNode::add_child(ASTNode* child) {
    if (child) {
        children.push_back(child);
    }
}

std::string ASTNode::get_node_type_str(NodeType type) {
    switch(type) {
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
        default: return "UNKNOWN";
    }
}

void ASTNode::print_ast_to_file(std::ofstream& out, int depth) const {
    std::string indent(depth * 2, ' ');
    
    out << indent << get_node_type_str(type);
    
    if (heading_level > 0) {
        out << " (h" << heading_level << ")";
    }
    
    if (!content.empty()) {
        out << ": \"" << content << "\"";
    }
    
    if (!attributes.empty()) {
        out << " [" << attributes << "]";
    }
    
    out << "\n";
    
    for (const auto* child : children) {
        child->print_ast_to_file(out, depth + 1);
    }
}

void ASTNode::print_ast(int depth) const {
    for (int i = 0; i < depth; i++) {
        std::cout << "  ";
    }

    std::cout << get_node_type_str(type);

    if (heading_level > 0) {
        std::cout << " (h" << heading_level << ")";
    }
    if (!content.empty()) {
        std::cout << ": \"" << content << "\"";
    }
    if (!attributes.empty()) {
        std::cout << " [" << attributes << "]";
    }
    std::cout << "\n";

    for (const auto* child : children) {
        child->print_ast(depth + 1);
    }
}

std::string ASTNode::get_dom_node_str() const {
    switch(type) {
        case NodeType::ROOT: return "document";
        case NodeType::HTML: return "html";
        case NodeType::HEAD: return "head";
        case NodeType::TITLE: return "title";
        case NodeType::BODY: return "body";
        case NodeType::NAV: return "nav";
        case NodeType::HEADER: return "header";
        case NodeType::SECTION: return "section";
        case NodeType::ARTICLE: return "article";
        case NodeType::ASIDE: return "aside";
        case NodeType::FOOTER: return "footer";
        case NodeType::HEADING: return "h" + std::to_string(heading_level);
        case NodeType::PARAGRAPH: return "p";
        case NodeType::LIST: return "ul";  // or "ol" depending on context
        case NodeType::LIST_ITEM: return "li";
        case NodeType::LINK: return "a";
        case NodeType::IMAGE: return "img";
        case NodeType::TEXT: return "#text";
        case NodeType::FORMATTED_TEXT: return "formatted";
        default: return "unknown";
    }
}

void ASTNode::print_dom(std::ofstream& out, int depth) const {
    // Indent based on depth
    std::string indent(depth * 2, ' ');
    
    // Print node type
    out << indent << "<" << get_dom_node_str();
    
    // Print attributes if any
    if (!attributes.empty()) {
        out << " " << attributes;
    }
    
    // For text nodes, print content inline
    if (type == NodeType::TEXT) {
        out << ">" << content << "</" << get_dom_node_str() << ">\n";
        return;
    }
    
    out << ">\n";
    
    // Print children
    for (const auto* child : children) {
        child->print_dom(out, depth + 1);
    }
    
    // Close tag
    out << indent << "</" << get_dom_node_str() << ">\n";
} 
#pragma once
#include <string>
#include <vector>
#include <fstream>

enum class NodeType {
    ROOT, HTML, HEAD, TITLE, BODY, NAV, HEADER, SECTION,
    ARTICLE, ASIDE, FOOTER, HEADING, PARAGRAPH, LIST,
    LIST_ITEM, LINK, IMAGE, TEXT, FORMATTED_TEXT, CONTAINER
};

struct ASTNode {
    NodeType type;
    std::string content;
    std::string attributes;
    int heading_level;
    std::vector<ASTNode*> children;

    explicit ASTNode(NodeType t);
    ~ASTNode();
    
    void add_child(ASTNode* child);
    void print_ast(int indent = 0) const;
    void print_ast_to_file(std::ofstream& out, int indent = 0) const;
    
private:
    static std::string get_node_type_str(NodeType type);
    std::string get_dom_node_str() const;
    void print_dom(std::ofstream& out, int depth) const;
}; 
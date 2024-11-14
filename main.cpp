#include <QApplication>
#include <iostream>
#include "parser.hpp"
#include "renderer.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <html_file>" << std::endl;
        return 1;
    }

    ASTNode* root = parse_html_file(argv[1]);
    
    if (root) {
        HTMLRenderer* renderer = new HTMLRenderer(root);
        renderer->show();
        
        int result = app.exec();
        delete root;
        return result;
    }
    
    std::cerr << "No AST was created (root is null)" << std::endl;
    return 1;
} 
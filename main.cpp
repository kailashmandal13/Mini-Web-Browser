#include <QApplication>
#include <QScrollArea>
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
        // Create scroll area
        QScrollArea* scrollArea = new QScrollArea();
        
        // Create and set up renderer
        HTMLRenderer* renderer = new HTMLRenderer(root);
        
        // Important: Set size policy for renderer
        renderer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        
        // Set up scroll area
        scrollArea->setWidget(renderer);
        scrollArea->setWidgetResizable(true);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);  // Always show vertical scrollbar
        
        // Set initial size
        scrollArea->resize(800, 600);
        scrollArea->show();
        
        int result = app.exec();
        delete root;
        return result;
    }
    
    std::cerr << "No AST was created (root is null)" << std::endl;
    return 1;
} 
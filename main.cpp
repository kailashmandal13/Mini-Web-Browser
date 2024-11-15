#include <QApplication>
#include <QDebug>
#include <QScrollArea>
#include <QTemporaryFile>
#include <QTextStream>
#include "browser_window.hpp"
#include "renderer.hpp"
#include "parser.hpp"
#include "network_manager.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    
    qDebug() << "Starting application with" << argc << "arguments";
    
    if (argc > 1) {
        QString url = argv[1];
        qDebug() << "Running as renderer process for:" << url;
        
        // Fetch content
        QString content = NetworkManager::instance().fetchUrlSync(url);
        if (content.isEmpty()) {
            qDebug() << "Failed to fetch content from:" << url;
            return 1;
        }
        
        // Create temporary file for parser
        QTemporaryFile tempFile;
        if (!tempFile.open()) {
            qDebug() << "Failed to create temporary file";
            return 1;
        }
        
        // Write content to temporary file
        QTextStream stream(&tempFile);
        stream << content;
        stream.flush();
        
        // Parse the HTML file
        ASTNode* root = parse_html_file(tempFile.fileName().toLocal8Bit().constData());
        if (!root) {
            qDebug() << "Failed to parse HTML content";
            return 1;
        }
        
        // Create and show the renderer window
        QScrollArea* scrollArea = new QScrollArea();
        HTMLRenderer* renderer = new HTMLRenderer(root);
        scrollArea->setWidget(renderer);
        scrollArea->setWidgetResizable(true);
        scrollArea->resize(800, 600);
        scrollArea->show();
        
        int result = app.exec();
        delete root;
        return result;
        
    } else {
        // Running as main browser process
        BrowserWindow* window = new BrowserWindow();
        window->show();
        return app.exec();
    }
} 
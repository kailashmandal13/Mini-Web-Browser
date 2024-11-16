#include "thread_pool_manager.hpp"
#include "parser.hpp"
#include <QFuture>
#include <QtConcurrent>
#include <QDebug>

ThreadPoolManager::ThreadPoolManager() {
    parserPool.setMaxThreadCount(4);  // Adjust based on system capabilities
}

ThreadPoolManager& ThreadPoolManager::instance() {
    static ThreadPoolManager instance;
    return instance;
}

void ThreadPoolManager::parseHtml(const QString& html, std::function<void(ASTNode*)> callback) {
    qDebug() << "Starting HTML parsing...";
    QtConcurrent::run(&parserPool, [html, callback]() {
        // Create a temporary file to store the HTML content
        QTemporaryFile tempFile;
        if (!tempFile.open()) {
            qDebug() << "Failed to create temporary file for parsing";
            callback(nullptr);
            return;
        }

        // Write the HTML content to the temporary file
        QTextStream stream(&tempFile);
        stream << html;
        stream.flush();
        
        QString fileName = tempFile.fileName();
        qDebug() << "Parsing HTML from file:" << fileName;
        
        // Parse the HTML using the existing parser
        ASTNode* root = parse_html_file(fileName.toLocal8Bit().constData());
        
        if (root) {
            qDebug() << "Successfully parsed HTML";
        } else {
            qDebug() << "Failed to parse HTML";
        }
        
        callback(root);
    });
} 
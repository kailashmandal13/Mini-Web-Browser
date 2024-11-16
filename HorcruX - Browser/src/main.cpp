#include <QApplication>
#include <QTemporaryFile>
#include <QTextStream>
#include <QDebug>
#include "browser/browser_window.hpp"
#include "renderer/renderer.hpp"
#include "network/network_manager.hpp"
#include "utils/thread_pool_manager.hpp"
#include "utils/history_manager.hpp"
#include "core/parser.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    qDebug() << "Starting application with" << argc << "arguments";

    // Create and show the browser window
    BrowserWindow* browser = new BrowserWindow();
    browser->show();

    // If a file was specified as an argument, load it
    if (argc > 1) {
        QString htmlContent;
        QFile file(argv[1]);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            htmlContent = QString::fromUtf8(file.readAll());
            file.close();
        }

        if (!htmlContent.isEmpty()) {
            QTemporaryFile tempFile;
            if (tempFile.open()) {
                QTextStream stream(&tempFile);
                stream << htmlContent;
                stream.flush();
                tempFile.close();

                // Parse the HTML file
                ASTNode* root = parse_html_file(tempFile.fileName().toStdString().c_str());
                if (root) {
                    // Create a new renderer window
                    QWidget* window = new QWidget();
                    QVBoxLayout* layout = new QVBoxLayout(window);
                    QScrollArea* scrollArea = new QScrollArea();
                    HTMLRenderer* renderer = new HTMLRenderer(root);
                    scrollArea->setWidget(renderer);
                    scrollArea->setWidgetResizable(true);
                    layout->addWidget(scrollArea);
                    window->show();
                }
            }
        }
    }

    return app.exec();
} 
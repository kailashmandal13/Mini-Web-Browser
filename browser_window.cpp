#include "browser_window.hpp"
#include <QToolBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

BrowserWindow::BrowserWindow(QWidget* parent) : QMainWindow(parent) {
    qDebug() << "Initializing BrowserWindow";
    
    // Create central widget and layout
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    
    // Create toolbar with URL bar and new tab button
    QHBoxLayout* toolbarLayout = new QHBoxLayout();
    
    urlBar = new QLineEdit(this);
    QPushButton* newTabButton = new QPushButton("+", this);
    
    toolbarLayout->addWidget(urlBar);
    toolbarLayout->addWidget(newTabButton);
    
    // Create tab manager
    tabManager = new TabManager(this);
    
    // Add widgets to main layout
    layout->addLayout(toolbarLayout);
    layout->addWidget(tabManager);
    
    // Set central widget
    setCentralWidget(centralWidget);
    
    // Connect signals
    connect(urlBar, &QLineEdit::returnPressed,
            this, &BrowserWindow::handleUrlEntered);
    connect(newTabButton, &QPushButton::clicked,
            this, &BrowserWindow::addNewTab);
    connect(tabManager, &TabManager::tabUrlChanged,
            this, &BrowserWindow::handleTabUrlChanged);
    connect(tabManager, &QTabWidget::currentChanged,
            this, &BrowserWindow::handleTabChanged);
    
    // Create initial tab
    addNewTab();
}

void BrowserWindow::handleUrlEntered() {
    QString url = urlBar->text();
    if (!url.isEmpty()) {
        int currentIndex = tabManager->currentIndex();
        if (currentIndex != -1) {
            // Load URL in current tab
            tabManager->loadUrlInTab(currentIndex, url);
        } else {
            // If no tab exists, create a new one
            tabManager->addNewTab(url);
        }
        urlBar->clear();
    }
}

void BrowserWindow::addNewTab() {
    // Start with an empty tab
    tabManager->addNewTab("");
}

void BrowserWindow::handleTabChanged(int index) {
    // Update URL bar when switching tabs
    if (index >= 0) {
        QString url = tabManager->getTabUrl(index);
        urlBar->setText(url);
    }
}

void BrowserWindow::handleTabUrlChanged(int index, const QString& url) {
    if (index == tabManager->currentIndex()) {
        urlBar->setText(url);
    }
} 
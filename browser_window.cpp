#include "browser_window.hpp"
#include <QToolBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QListWidget>
#include <QDialog>
#include <QMessageBox>
#include <QSettings>

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
    
    // Add navigation buttons to toolbar
    backButton = new QPushButton("←", this);
    forwardButton = new QPushButton("→", this);
    
    toolbarLayout->addWidget(backButton);
    toolbarLayout->addWidget(forwardButton);
    toolbarLayout->addWidget(urlBar);
    toolbarLayout->addWidget(newTabButton);
    
    // Connect navigation signals
    connect(backButton, &QPushButton::clicked, this, &BrowserWindow::navigateBack);
    connect(forwardButton, &QPushButton::clicked, this, &BrowserWindow::navigateForward);
    
    // Create menus
    createMenus();
    
    // Initialize session saving based on saved preference
    bool saveSession = settings.value("saveSession", true).toBool();
    saveSessionAction->setChecked(saveSession);
    
    // Only restore session if enabled
    if (saveSession) {
        tabManager->restoreSession();
    } else {
        addNewTab();
    }
}

void BrowserWindow::handleUrlEntered() {
    QString url = urlBar->text();
    
    // Add http:// if no protocol specified
    if (!url.isEmpty() && !url.contains("://")) {
        url = "http://" + url;
    }
    
    qDebug() << "Handling URL:" << url;
    
    if (!url.isEmpty()) {
        int currentIndex = tabManager->currentIndex();
        if (currentIndex != -1) {
            tabManager->loadUrlInTab(currentIndex, url);
        } else {
            tabManager->addNewTab(url);
        }
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

void BrowserWindow::navigateBack() {
    int currentIndex = tabManager->currentIndex();
    if (currentIndex != -1) {
        tabManager->navigateBack(currentIndex);
    }
}

void BrowserWindow::navigateForward() {
    int currentIndex = tabManager->currentIndex();
    if (currentIndex != -1) {
        tabManager->navigateForward(currentIndex);
    }
}

void BrowserWindow::createMenus() {
    QMenuBar* menuBar = new QMenuBar(this);
    setMenuBar(menuBar);
    
    // File Menu
    QMenu* fileMenu = menuBar->addMenu("File");
    saveSessionAction = fileMenu->addAction("Save Session on Exit");
    saveSessionAction->setCheckable(true);
    connect(saveSessionAction, &QAction::toggled, this, &BrowserWindow::toggleSessionSaving);
    
    // History Menu
    historyMenu = menuBar->addMenu("History");
    QAction* showHistoryAction = historyMenu->addAction("Show History");
    QAction* clearHistoryAction = historyMenu->addAction("Clear History");
    historyMenu->addSeparator();
    
    connect(showHistoryAction, &QAction::triggered, this, &BrowserWindow::showHistory);
    connect(clearHistoryAction, &QAction::triggered, this, &BrowserWindow::clearHistory);
}

void BrowserWindow::toggleSessionSaving(bool enabled) {
    settings.setValue("saveSession", enabled);
    settings.sync();
}

void BrowserWindow::showHistory() {
    QStringList history = settings.value("history").toStringList();
    
    // Create a new window to show history
    QDialog* historyDialog = new QDialog(this);
    historyDialog->setWindowTitle("Browser History");
    historyDialog->setMinimumSize(400, 300);
    
    QVBoxLayout* layout = new QVBoxLayout(historyDialog);
    
    // Create a list widget to show history items
    QListWidget* historyList = new QListWidget(historyDialog);
    for (const QString& url : history) {
        QListWidgetItem* item = new QListWidgetItem(url);
        historyList->addItem(item);
    }
    
    // Add ability to click on history items
    connect(historyList, &QListWidget::itemClicked, [this, historyDialog](QListWidgetItem* item) {
        int currentIndex = tabManager->currentIndex();
        if (currentIndex != -1) {
            tabManager->loadUrlInTab(currentIndex, item->text());
        } else {
            tabManager->addNewTab(item->text());
        }
        historyDialog->close();
    });
    
    layout->addWidget(historyList);
    historyDialog->setLayout(layout);
    historyDialog->show();
}

void BrowserWindow::clearHistory() {
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Clear History",
        "Are you sure you want to clear all browsing history?",
        QMessageBox::Yes | QMessageBox::No
    );
    
    if (reply == QMessageBox::Yes) {
        settings.remove("history");
        settings.sync();
    }
} 
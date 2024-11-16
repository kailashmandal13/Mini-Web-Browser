#include "browser_window.hpp"
#include <QToolBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include "history_manager.hpp"
#include <QMenu>
#include <QMenuBar>
#include <QTimer>

BrowserWindow::BrowserWindow(QWidget* parent) : QMainWindow(parent) {
    qDebug() << "Initializing BrowserWindow";
    
    // Set window title
    setWindowTitle("HorcruX");
    
    // Create central widget and layout
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    
    // Create toolbar with navigation buttons, URL bar and new tab button
    QHBoxLayout* toolbarLayout = new QHBoxLayout();
    
    // Add navigation buttons
    backButton = new QPushButton("←", this);
    forwardButton = new QPushButton("→", this);
    backButton->setEnabled(false);
    forwardButton->setEnabled(false);
    
    urlBar = new QLineEdit(this);
    QPushButton* newTabButton = new QPushButton("+", this);
    
    toolbarLayout->addWidget(backButton);
    toolbarLayout->addWidget(forwardButton);
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
    connect(tabManager, &TabManager::navigationStateChanged,
            this, &BrowserWindow::handleNavigationStateChanged);
    
    // Connect navigation buttons
    connect(backButton, &QPushButton::clicked, [this]() {
        qDebug() << "Back button clicked";
        int currentIndex = tabManager->currentIndex();
        if (currentIndex >= 0) {
            tabManager->navigateBack(currentIndex);
        }
    });
    connect(forwardButton, &QPushButton::clicked, [this]() {
        qDebug() << "Forward button clicked";
        int currentIndex = tabManager->currentIndex();
        if (currentIndex >= 0) {
            tabManager->navigateForward(currentIndex);
        }
    });
    
    // Create Settings menu
    QMenu* settingsMenu = menuBar()->addMenu("Settings");
    
    // Add History submenu
    QMenu* historySubmenu = settingsMenu->addMenu("History");
    historySubmenu->addAction("Show Recent Pages", this, &BrowserWindow::showHistoryMenu);
    
    // Add separator
    settingsMenu->addSeparator();
    
    // Add Save Session option
    QAction* saveSessionAction = settingsMenu->addAction("Save Session on Exit");
    saveSessionAction->setCheckable(true);
    saveSessionAction->setChecked(HistoryManager::instance().isSaveSessionEnabled());
    connect(saveSessionAction, &QAction::toggled, this, &BrowserWindow::toggleSaveSession);
    
    // Create initial tab
    addNewTab();
    
    // Restore last session on startup
    QTimer::singleShot(0, this, &BrowserWindow::restoreLastSession);
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

void BrowserWindow::showHistoryMenu() {
    QMenu menu(this);
    
    // Add recent URLs
    auto recentUrls = HistoryManager::instance().getMostRecentUrls();
    if (!recentUrls.isEmpty()) {
        menu.addSection("Recent");
        for (const auto& pair : recentUrls) {
            menu.addAction(pair.second.isEmpty() ? pair.first : pair.second, [this, url = pair.first]() {
                int currentIndex = tabManager->currentIndex();
                if (currentIndex != -1) {
                    tabManager->loadUrlInTab(currentIndex, url);
                } else {
                    tabManager->addNewTab(url);
                }
            });
        }
    }
    
    // Add most frequent URLs
    auto frequentUrls = HistoryManager::instance().getMostFrequentUrls();
    if (!frequentUrls.isEmpty()) {
        menu.addSection("Most Visited");
        for (const auto& pair : frequentUrls) {
            menu.addAction(pair.second.isEmpty() ? pair.first : pair.second, [this, url = pair.first]() {
                int currentIndex = tabManager->currentIndex();
                if (currentIndex != -1) {
                    tabManager->loadUrlInTab(currentIndex, url);
                } else {
                    tabManager->addNewTab(url);
                }
            });
        }
    }
    
    menu.exec(QCursor::pos());
}

void BrowserWindow::restoreLastSession() {
    if (!HistoryManager::instance().isSaveSessionEnabled()) {
        qDebug() << "Session restoration disabled";
        return;
    }

    QVector<QString> urls = HistoryManager::instance().loadLastSession();
    qDebug() << "Attempting to restore" << urls.size() << "tabs";
    
    if (!urls.isEmpty()) {
        // Close the default empty tab
        if (tabManager->count() == 1 && tabManager->getTabUrl(0).isEmpty()) {
            tabManager->closeTab(0);
        }
        
        // Restore all tabs
        for (const QString& url : urls) {
            qDebug() << "Restoring tab with URL:" << url;
            tabManager->addNewTab(url);
        }
    } else {
        qDebug() << "No session to restore";
    }
}

void BrowserWindow::toggleSaveSession(bool enabled) {
    HistoryManager::instance().setSaveSessionEnabled(enabled);
}

void BrowserWindow::saveCurrentSession() {
    QVector<QString> currentUrls;
    for (int i = 0; i < tabManager->count(); ++i) {
        QString tabUrl = tabManager->getTabUrl(i);
        if (!tabUrl.isEmpty()) {
            currentUrls.append(tabUrl);
        }
    }
    HistoryManager::instance().saveSession(currentUrls);
}

void BrowserWindow::closeEvent(QCloseEvent* event) {
    if (HistoryManager::instance().isSaveSessionEnabled()) {
        saveCurrentSession();
    }
    QMainWindow::closeEvent(event);
}

void BrowserWindow::handleNavigationStateChanged(int index, bool canGoBack, bool canGoForward) {
    if (index == tabManager->currentIndex()) {
        backButton->setEnabled(canGoBack);
        forwardButton->setEnabled(canGoForward);
    }
} 
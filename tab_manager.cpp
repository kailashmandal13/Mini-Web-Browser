#include "tab_manager.hpp"
#include <QProcess>
#include <QDebug>

TabManager::TabManager(QWidget* parent) : QTabWidget(parent) {
    setTabsClosable(true);
    connect(this, &QTabWidget::tabCloseRequested, this, &TabManager::handleTabClose);
}

void TabManager::addNewTab(const QString& url) {
    qDebug() << "Adding new tab with URL:" << url;
    
    // Create a new tab with a placeholder
    QWidget* placeholder = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(placeholder);
    layout->setContentsMargins(0, 0, 0, 0);
    
    int index = addTab(placeholder, url.isEmpty() ? "" : url);
    setCurrentIndex(index);

    if (!url.isEmpty()) {
        loadUrlInTab(index, url);
    }
}

void TabManager::handleTabClose(int index) {
    if (tabs.contains(index)) {
        if (tabs[index].process) {
            tabs[index].process->terminate();
            tabs[index].process->waitForFinished();
            delete tabs[index].process;
        }
        tabs.remove(index);
    }
    removeTab(index);
}

void TabManager::handleProcessFinished(int exitCode, QProcess::ExitStatus exitStatus) {
    QProcess* process = qobject_cast<QProcess*>(sender());
    if (!process) return;
    
    qDebug() << "Process finished with exit code:" << exitCode 
             << "and status:" << exitStatus;
    
    // Find the tab for this process
    for (auto it = tabs.begin(); it != tabs.end(); ++it) {
        if (it.value().process == process) {
            int index = it.key();
            if (exitCode == 0) {
                qDebug() << "Renderer process completed successfully for tab" << index;
            } else {
                qDebug() << "Renderer process failed for tab" << index;
                QWidget* errorWidget = new QWidget();
                QVBoxLayout* layout = new QVBoxLayout(errorWidget);
                layout->addWidget(new QLabel("Error loading page: Exit code " + QString::number(exitCode)));
                setCurrentIndex(index);
                removeTab(index);
                insertTab(index, errorWidget, it.value().url);
            }
            break;
        }
    }
}

QString TabManager::getTabUrl(int index) const {
    if (tabs.contains(index)) {
        return tabs[index].url;
    }
    return QString();
}

void TabManager::loadUrlInTab(int index, const QString& url) {
    if (!tabs.contains(index)) {
        tabs[index] = TabInfo();
    }
    
    qDebug() << "Loading URL in tab" << index << ":" << url;
    auto& tab = tabs[index];
    tab.url = url;
    
    // Update history
    updateTabHistory(index, url);
    saveHistory(url);
    
    // Show loading indicator
    QWidget* loadingWidget = new QWidget();
    QVBoxLayout* loadingLayout = new QVBoxLayout(loadingWidget);
    QLabel* loadingLabel = new QLabel("Loading...");
    loadingLayout->addWidget(loadingLabel);
    removeTab(index);
    insertTab(index, loadingWidget, url);
    
    // Fetch content
    QString content = NetworkManager::instance().fetchUrlSync(url);
    qDebug() << "Fetched content length:" << content.length();
    
    if (!content.isEmpty()) {
        ThreadPoolManager::instance().parseHtml(content, [this, index, url, content](ASTNode* root) {
            QMetaObject::invokeMethod(this, [this, root, index, url]() {
                if (root) {
                    // Extract title from AST
                    QString pageTitle = url;  // Default to URL
                    for (const auto* child : root->children) {
                        if (child && child->type == NodeType::HTML) {
                            for (const auto* htmlChild : child->children) {
                                if (htmlChild && htmlChild->type == NodeType::HEAD) {
                                    for (const auto* headChild : htmlChild->children) {
                                        if (headChild && headChild->type == NodeType::TITLE &&
                                            !headChild->children.empty() &&
                                            headChild->children[0]->type == NodeType::TEXT) {
                                            pageTitle = QString::fromStdString(headChild->children[0]->content);
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                            break;
                        }
                    }

                    // Create scroll area and renderer
                    QScrollArea* scrollArea = new QScrollArea(this);
                    scrollArea->setWidgetResizable(true);
                    
                    QWidget* contentWidget = new QWidget(scrollArea);
                    QVBoxLayout* layout = new QVBoxLayout(contentWidget);
                    
                    HTMLRenderer* renderer = new HTMLRenderer(root, contentWidget);
                    layout->addWidget(renderer);
                    layout->setContentsMargins(0, 0, 0, 0);  // Remove layout margins
                    
                    contentWidget->setLayout(layout);
                    scrollArea->setWidget(contentWidget);
                    
                    removeTab(index);
                    insertTab(index, scrollArea, pageTitle);  // Use extracted title
                    setCurrentIndex(index);
                } else {
                    qDebug() << "Failed to parse HTML";
                    QLabel* errorLabel = new QLabel("Error: Failed to parse content");
                    removeTab(index);
                    insertTab(index, errorLabel, url);
                }
            }, Qt::QueuedConnection);
        });
    } else {
        qDebug() << "Failed to fetch content for URL:" << url;
        QLabel* errorLabel = new QLabel("Error: Failed to fetch content");
        removeTab(index);
        insertTab(index, errorLabel, url);
    }
    
    setCurrentIndex(index);
}

void TabManager::updateTabHistory(int index, const QString& url) {
    if (!tabs.contains(index)) return;
    
    auto& tab = tabs[index];
    
    // If we're not at the end of history, truncate forward history
    if (tab.historyIndex < tab.history.size() - 1) {
        tab.history.remove(tab.historyIndex + 1, 
                         tab.history.size() - tab.historyIndex - 1);
    }
    
    // Add new URL to history
    tab.history.append(url);
    tab.historyIndex = tab.history.size() - 1;
}

void TabManager::saveHistory(const QString& url) {
    // Save to global history
    QStringList history = settings.value("history").toStringList();
    history.removeAll(url);  // Remove if exists
    history.append(url);     // Add to end
    
    // Keep only last 100 entries
    while (history.size() > 100) {
        history.removeFirst();
    }
    
    settings.setValue("history", history);
}

void TabManager::navigateBack(int index) {
    if (!tabs.contains(index)) return;
    
    auto& tab = tabs[index];
    if (tab.historyIndex > 0) {
        tab.historyIndex--;
        QString url = tab.history[tab.historyIndex];
        loadUrlInTab(index, url);
    }
}

void TabManager::navigateForward(int index) {
    if (!tabs.contains(index)) return;
    
    auto& tab = tabs[index];
    if (tab.historyIndex < tab.history.size() - 1) {
        tab.historyIndex++;
        QString url = tab.history[tab.historyIndex];
        loadUrlInTab(index, url);
    }
}

void TabManager::saveSession() {
    QStringList urls;
    for (int i = 0; i < count(); ++i) {
        if (tabs.contains(i)) {
            urls.append(tabs[i].url);
        }
    }
    settings.setValue("session", urls);
    settings.sync();
}

void TabManager::restoreSession() {
    QStringList urls = settings.value("session").toStringList();
    if (urls.isEmpty()) {
        // Add empty tab if no session to restore
        addNewTab("");
        return;
    }
    
    for (const QString& url : urls) {
        addNewTab(url);
    }
}

TabManager::~TabManager() {
    saveSession();
} 
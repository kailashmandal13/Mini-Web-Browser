#include "tab_manager.hpp"
#include <QProcess>
#include <QDebug>
#include "history_manager.hpp"

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
    updateNavigationState(index);
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

void TabManager::loadUrlInTab(int index, const QString& url, bool addToHistory) {
    qDebug() << "Loading URL in tab" << index << ":" << url;
    
    if (index < 0 || index >= count()) {
        qDebug() << "Invalid tab index:" << index;
        return;
    }

    // Update navigation history
    if (addToHistory && tabs.contains(index)) {
        TabInfo& info = tabs[index];
        if (!info.url.isEmpty()) {
            qDebug() << "Adding to back stack:" << info.url;
            info.backStack.push(info.url);
            info.forwardStack.clear();
        }
    }

    // Create new content widget but don't delete the old tab yet
    QWidget* newWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(newWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    
    // Create a loading indicator
    QLabel* loadingLabel = new QLabel("Loading...");
    layout->addWidget(loadingLabel);
    
    // Replace the tab widget
    QWidget* oldWidget = widget(index);
    removeTab(index);
    insertTab(index, newWidget, url);
    setCurrentIndex(index);
    
    // Now we can safely delete the old widget
    if (oldWidget) {
        oldWidget->deleteLater();
    }
    
    // Fetch content
    QString htmlContent = NetworkManager::instance().fetchUrlSync(url);
    if (htmlContent.isEmpty()) {
        qDebug() << "Failed to fetch content for URL:" << url;
        delete loadingLabel;
        QLabel* errorLabel = new QLabel("Error: Failed to fetch content");
        layout->addWidget(errorLabel);
        return;
    }
    
    // Start loading content
    ThreadPoolManager::instance().parseHtml(
        htmlContent,
        [this, index, layout, loadingLabel, url](ASTNode* root) {
            QMetaObject::invokeMethod(this, [this, root, index, layout, loadingLabel, url]() {
                if (root) {
                    // Find the title node
                    QString title = "New Tab";
                    for (const auto* child : root->children) {
                        if (child && child->type == NodeType::HTML) {
                            for (const auto* htmlChild : child->children) {
                                if (htmlChild && htmlChild->type == NodeType::HEAD) {
                                    for (const auto* headChild : htmlChild->children) {
                                        if (headChild && headChild->type == NodeType::TITLE) {
                                            if (!headChild->children.empty() && 
                                                headChild->children[0]->type == NodeType::TEXT) {
                                                title = QString::fromStdString(headChild->children[0]->content);
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    
                    // Create scroll area and renderer
                    QScrollArea* scrollArea = new QScrollArea();
                    HTMLRenderer* renderer = new HTMLRenderer(root);
                    connectRendererSignals(renderer);
                    scrollArea->setWidget(renderer);
                    scrollArea->setWidgetResizable(true);
                    
                    delete loadingLabel;
                    layout->addWidget(scrollArea);
                    
                    // Update tab title and info
                    setTabText(index, title);
                    
                    // Update tab info
                    if (!tabs.contains(index)) {
                        tabs[index] = TabInfo();
                    }
                    tabs[index].url = url;
                    tabs[index].title = title;
                    
                    // Emit signal for URL bar update
                    emit tabUrlChanged(index, url);
                    
                    // Add to history with title
                    HistoryManager::instance().addToHistory(url, title);
                    
                    // Update navigation state
                    updateNavigationState(index);
                    
                } else {
                    delete loadingLabel;
                    QLabel* errorLabel = new QLabel("Error: Failed to parse HTML");
                    layout->addWidget(errorLabel);
                }
            }, Qt::QueuedConnection);
        }
    );
}

void TabManager::closeTab(int index) {
    handleTabClose(index);
}

void TabManager::connectRendererSignals(HTMLRenderer* renderer) {
    connect(renderer, &HTMLRenderer::linkClicked, [this](const QString& url) {
        qDebug() << "Link clicked in tab manager:" << url;
        // Add new tab with the clicked URL
        addNewTab(url);
    });
}

void TabManager::navigateBack(int index) {
    qDebug() << "Attempting to navigate back for tab" << index;
    if (!canGoBack(index)) {
        qDebug() << "Cannot go back - no history";
        return;
    }
    
    TabInfo& info = tabs[index];
    QString currentUrl = info.url;
    QString previousUrl = info.backStack.pop();
    qDebug() << "Navigating back from" << currentUrl << "to" << previousUrl;
    info.forwardStack.push(currentUrl);
    
    loadUrlInTab(index, previousUrl, false);
    updateNavigationState(index);
}

void TabManager::navigateForward(int index) {
    qDebug() << "Attempting to navigate forward for tab" << index;
    if (!canGoForward(index)) {
        qDebug() << "Cannot go forward - no forward history";
        return;
    }
    
    TabInfo& info = tabs[index];
    QString currentUrl = info.url;
    QString nextUrl = info.forwardStack.pop();
    qDebug() << "Navigating forward from" << currentUrl << "to" << nextUrl;
    info.backStack.push(currentUrl);
    
    loadUrlInTab(index, nextUrl, false);
    updateNavigationState(index);
}

bool TabManager::canGoBack(int index) const {
    return tabs.contains(index) && !tabs[index].backStack.isEmpty();
}

bool TabManager::canGoForward(int index) const {
    return tabs.contains(index) && !tabs[index].forwardStack.isEmpty();
}

void TabManager::updateNavigationState(int index) {
    if (tabs.contains(index)) {
        qDebug() << "Updating navigation state for tab" << index
                 << "- Can go back:" << canGoBack(index)
                 << "- Can go forward:" << canGoForward(index);
        emit navigationStateChanged(index, canGoBack(index), canGoForward(index));
    }
} 
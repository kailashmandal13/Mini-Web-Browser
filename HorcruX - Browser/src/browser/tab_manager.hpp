#pragma once
#include <QTabWidget>
#include <QProcess>
#include <QLabel>
#include <QVBoxLayout>
#include <QMap>
#include <QScrollArea>
#include <QStack>
#include "../utils/thread_pool_manager.hpp"
#include "../network/network_manager.hpp"
#include "../renderer/renderer.hpp"
#include "../core/ast.hpp"

class TabManager : public QTabWidget {
    Q_OBJECT
public:
    explicit TabManager(QWidget* parent = nullptr);
    ~TabManager() override = default;
    void addNewTab(const QString& url);
    QString getTabUrl(int index) const;
    void loadUrlInTab(int index, const QString& url, bool addToHistory = true);
    void closeTab(int index);
    
    // Navigation methods
    void navigateBack(int index);
    void navigateForward(int index);
    bool canGoBack(int index) const;
    bool canGoForward(int index) const;

signals:
    void tabUrlChanged(int index, const QString& url);
    void navigationStateChanged(int index, bool canGoBack, bool canGoForward);

private slots:
    void handleTabClose(int index);
    void handleProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    struct TabInfo {
        QProcess* process = nullptr;
        QString url;
        QString title;
        QStack<QString> backStack;    // Stack for back navigation
        QStack<QString> forwardStack; // Stack for forward navigation
    };
    QMap<int, TabInfo> tabs;
    void connectRendererSignals(HTMLRenderer* renderer);
    void updateNavigationState(int index);
}; 
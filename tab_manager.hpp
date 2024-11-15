#pragma once
#include <QTabWidget>
#include <QProcess>
#include <QLabel>
#include <QVBoxLayout>
#include <QMap>
#include <QScrollArea>
#include <QSettings>
#include "thread_pool_manager.hpp"
#include "network_manager.hpp"
#include "renderer.hpp"
#include "ast.hpp"

class TabManager : public QTabWidget {
    Q_OBJECT
public:
    explicit TabManager(QWidget* parent = nullptr);
    ~TabManager() override;
    void addNewTab(const QString& url);
    QString getTabUrl(int index) const;
    void loadUrlInTab(int index, const QString& url);
    void navigateBack(int index);
    void navigateForward(int index);
    void saveSession();
    void restoreSession();

signals:
    void tabUrlChanged(int index, const QString& url);

private slots:
    void handleTabClose(int index);
    void handleProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    struct TabInfo {
        QProcess* process = nullptr;
        QString url;
        QString title;
        QVector<QString> history;  // Store tab's history
        int historyIndex = -1;     // Current position in history
    };
    QMap<int, TabInfo> tabs;
    QSettings settings{"MyCompany", "WebBrowser"};  // For persistent storage
    
    void updateTabHistory(int index, const QString& url);
    void saveHistory(const QString& url);
}; 
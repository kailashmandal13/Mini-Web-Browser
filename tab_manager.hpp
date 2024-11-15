#pragma once
#include <QTabWidget>
#include <QProcess>
#include <QLabel>
#include <QVBoxLayout>
#include <QMap>
#include <QScrollArea>
#include "thread_pool_manager.hpp"
#include "network_manager.hpp"
#include "renderer.hpp"
#include "ast.hpp"

class TabManager : public QTabWidget {
    Q_OBJECT
public:
    explicit TabManager(QWidget* parent = nullptr);
    ~TabManager() override = default;
    void addNewTab(const QString& url);
    QString getTabUrl(int index) const;
    void loadUrlInTab(int index, const QString& url);

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
    };
    QMap<int, TabInfo> tabs;
}; 
#pragma once
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include "tab_manager.hpp"
#include "../utils/history_manager.hpp"
#include <QMenu>
#include <QMenuBar>

class BrowserWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit BrowserWindow(QWidget* parent = nullptr);
    ~BrowserWindow() override = default;

private slots:
    void handleUrlEntered();
    void addNewTab();
    void handleTabUrlChanged(int index, const QString& url);
    void handleTabChanged(int index);
    void showHistoryMenu();
    void restoreLastSession();
    void toggleSaveSession(bool enabled);
    void saveCurrentSession();
    void handleNavigationStateChanged(int index, bool canGoBack, bool canGoForward);

private:
    QLineEdit* urlBar;
    TabManager* tabManager;
    QPushButton* backButton;
    QPushButton* forwardButton;
    void closeEvent(QCloseEvent* event) override;
}; 
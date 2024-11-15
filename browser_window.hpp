#pragma once
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include "tab_manager.hpp"

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
    void navigateBack();
    void navigateForward();
    void showHistory();
    void toggleSessionSaving(bool enabled);
    void clearHistory();

private:
    void createMenus();
    
    QLineEdit* urlBar;
    TabManager* tabManager;
    QPushButton* backButton;
    QPushButton* forwardButton;
    QSettings settings{"MyCompany", "WebBrowser"};
    QMenu* historyMenu;
    QAction* saveSessionAction;
}; 
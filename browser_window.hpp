#pragma once
#include <QMainWindow>
#include <QLineEdit>
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

private:
    QLineEdit* urlBar;
    TabManager* tabManager;
}; 
#pragma once
#include <QObject>
#include <QLocalServer>
#include <QLocalSocket>

class BrowserProcess : public QObject {
    Q_OBJECT
public:
    explicit BrowserProcess(QObject* parent = nullptr);
    ~BrowserProcess();

private slots:
    void handleNewConnection();

private:
    QLocalServer* server;
}; 
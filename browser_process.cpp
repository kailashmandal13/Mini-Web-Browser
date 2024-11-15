#include "browser_process.hpp"
#include <QDebug>

BrowserProcess::BrowserProcess(QObject* parent) : QObject(parent) {
    server = new QLocalServer(this);
    
    // Remove any existing server with the same name
    QLocalServer::removeServer("BrowserIPC");
    
    if (!server->listen("BrowserIPC")) {
        qDebug() << "Failed to start IPC server:" << server->errorString();
        return;
    }
    
    connect(server, &QLocalServer::newConnection,
            this, &BrowserProcess::handleNewConnection);
            
    qDebug() << "IPC server started successfully";
}

BrowserProcess::~BrowserProcess() {
    if (server) {
        server->close();
    }
}

void BrowserProcess::handleNewConnection() {
    QLocalSocket* socket = server->nextPendingConnection();
    if (!socket) {
        qDebug() << "Failed to get new connection";
        return;
    }
    
    connect(socket, &QLocalSocket::readyRead, [socket]() {
        QByteArray data = socket->readAll();
        qDebug() << "Received data from renderer process:" << data;
        // Handle IPC messages
    });
    
    connect(socket, &QLocalSocket::disconnected, [socket]() {
        qDebug() << "Renderer process disconnected";
        socket->deleteLater();
    });
    
    qDebug() << "New renderer process connected";
} 
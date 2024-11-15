#include "network_manager.hpp"
#include <QEventLoop>
#include <QFile>

NetworkManager::NetworkManager(QObject* parent) : QObject(parent) {}

NetworkManager& NetworkManager::instance() {
    static NetworkManager instance;
    return instance;
}

QString NetworkManager::fetchUrlSync(const QString& url) {
    qDebug() << "Attempting to fetch URL:" << url;
    
    if (url.startsWith("http://") || url.startsWith("https://")) {
        QUrl qUrl(url);
        QNetworkRequest request;
        request.setUrl(qUrl);
        
        QNetworkReply* reply = manager.get(request);
        
        QEventLoop loop;
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();
        
        if (reply->error() == QNetworkReply::NoError) {
            QString content = QString::fromUtf8(reply->readAll());
            qDebug() << "Successfully fetched content, length:" << content.length();
            reply->deleteLater();
            return content;
        }
        qDebug() << "Network error:" << reply->errorString();
        reply->deleteLater();
        return QString();
    } else {
        // Handle local file
        QFile file(url);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QString content = QString::fromUtf8(file.readAll());
            qDebug() << "Successfully read local file, length:" << content.length();
            return content;
        }
        qDebug() << "Failed to open local file:" << url;
        return QString();
    }
} 
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
    
    QUrl qUrl;
    if (url.startsWith("http://") || url.startsWith("https://")) {
        qUrl = QUrl(url);
    } else {
        // Handle relative paths
        QString adjustedPath = url;
        if (url.startsWith("./")) {
            adjustedPath = url.mid(2);
        }
        if (!url.startsWith("/")) {
            adjustedPath = "/" + adjustedPath;
        }
        qUrl = QUrl("http://localhost:8000" + adjustedPath);
    }
    
    if (qUrl.isValid()) {
        if (qUrl.scheme().startsWith("http")) {
            QNetworkReply* reply = manager.get(QNetworkRequest(qUrl));
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
        }
    }
    
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
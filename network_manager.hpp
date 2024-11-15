#pragma once
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QObject>
#include <QString>

class NetworkManager : public QObject {
    Q_OBJECT
public:
    static NetworkManager& instance();
    QString fetchUrlSync(const QString& url);

private:
    explicit NetworkManager(QObject* parent = nullptr);
    QNetworkAccessManager manager;
}; 
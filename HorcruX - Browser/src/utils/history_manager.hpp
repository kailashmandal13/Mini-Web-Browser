#pragma once
#include <QObject>
#include <QSettings>
#include <QDateTime>
#include <QString>
#include <QVector>
#include <QMap>
#include <QStringList>

class HistoryManager : public QObject {
    Q_OBJECT
public:
    static HistoryManager& instance();
    
    // History management
    void addToHistory(const QString& url, const QString& title);
    QVector<QPair<QString, QString>> getMostRecentUrls(int count = 10);
    QVector<QPair<QString, QString>> getMostFrequentUrls(int count = 10);
    
    // Session management
    void saveSession(const QVector<QString>& urls);
    QVector<QString> loadLastSession();
    bool isSaveSessionEnabled() const;
    void setSaveSessionEnabled(bool enabled);
    
private:
    explicit HistoryManager(QObject* parent = nullptr);
    void loadHistory();
    void saveHistory();
    
    struct HistoryEntry {
        QString title;
        QDateTime timestamp;
        int visitCount;
    };
    
    QMap<QString, HistoryEntry> history;
    QSettings settings;
}; 
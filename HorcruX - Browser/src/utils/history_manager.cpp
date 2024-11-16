#include "history_manager.hpp"
#include <QDebug>
#include <algorithm>

HistoryManager::HistoryManager(QObject* parent) 
    : QObject(parent), settings("MyBrowser", "BrowserHistory") {
    loadHistory();
}

HistoryManager& HistoryManager::instance() {
    static HistoryManager instance;
    return instance;
}

void HistoryManager::addToHistory(const QString& url, const QString& title) {
    auto& entry = history[url];
    entry.title = title;
    entry.timestamp = QDateTime::currentDateTime();
    entry.visitCount++;
    saveHistory();
}

QVector<QPair<QString, QString>> HistoryManager::getMostRecentUrls(int count) {
    QVector<QPair<QString, QString>> result;
    QVector<QPair<QString, QDateTime>> sortedUrls;
    
    for (auto it = history.begin(); it != history.end(); ++it) {
        sortedUrls.append({it.key(), it.value().timestamp});
    }
    
    std::sort(sortedUrls.begin(), sortedUrls.end(),
              [](const auto& a, const auto& b) { return a.second > b.second; });
    
    for (int i = 0; i < std::min(count, sortedUrls.size()); ++i) {
        const auto& url = sortedUrls[i].first;
        result.append({url, history[url].title});
    }
    
    return result;
}

QVector<QPair<QString, QString>> HistoryManager::getMostFrequentUrls(int count) {
    QVector<QPair<QString, QString>> result;
    QVector<QPair<QString, int>> sortedUrls;
    
    for (auto it = history.begin(); it != history.end(); ++it) {
        sortedUrls.append({it.key(), it.value().visitCount});
    }
    
    std::sort(sortedUrls.begin(), sortedUrls.end(),
              [](const auto& a, const auto& b) { return a.second > b.second; });
    
    for (int i = 0; i < std::min(count, sortedUrls.size()); ++i) {
        const auto& url = sortedUrls[i].first;
        result.append({url, history[url].title});
    }
    
    return result;
}

void HistoryManager::saveSession(const QVector<QString>& urls) {
    QStringList urlList;
    for (const QString& url : urls) {
        urlList.append(url);
    }
    settings.setValue("lastSession", urlList);
    settings.sync();
}

QVector<QString> HistoryManager::loadLastSession() {
    QStringList urlList = settings.value("lastSession").toStringList();
    QVector<QString> urls;
    for (const QString& url : urlList) {
        urls.append(url);
    }
    return urls;
}

void HistoryManager::loadHistory() {
    int size = settings.beginReadArray("history");
    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        QString url = settings.value("url").toString();
        HistoryEntry entry;
        entry.title = settings.value("title").toString();
        entry.timestamp = settings.value("timestamp").toDateTime();
        entry.visitCount = settings.value("visitCount").toInt();
        history[url] = entry;
    }
    settings.endArray();
}

void HistoryManager::saveHistory() {
    settings.beginWriteArray("history");
    int i = 0;
    for (auto it = history.begin(); it != history.end(); ++it, ++i) {
        settings.setArrayIndex(i);
        settings.setValue("url", it.key());
        settings.setValue("title", it.value().title);
        settings.setValue("timestamp", it.value().timestamp);
        settings.setValue("visitCount", it.value().visitCount);
    }
    settings.endArray();
    settings.sync();
}

bool HistoryManager::isSaveSessionEnabled() const {
    return settings.value("saveSessionEnabled", false).toBool();
}

void HistoryManager::setSaveSessionEnabled(bool enabled) {
    settings.setValue("saveSessionEnabled", enabled);
    settings.sync();
} 
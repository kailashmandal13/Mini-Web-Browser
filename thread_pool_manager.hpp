#pragma once
#include <QThreadPool>
#include <QRunnable>
#include <QString>
#include <functional>
#include "ast.hpp"

class ThreadPoolManager {
public:
    static ThreadPoolManager& instance();
    void parseHtml(const QString& html, std::function<void(ASTNode*)> callback);

private:
    ThreadPoolManager();
    QThreadPool parserPool;
}; 
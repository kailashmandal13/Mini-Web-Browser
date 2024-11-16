#pragma once
#include <QWidget>
#include <QPainter>
#include <QFontMetrics>
#include <QMouseEvent>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include <iostream>
#include "../core/ast.hpp"

class HTMLRenderer : public QWidget {
    Q_OBJECT
public:
    explicit HTMLRenderer(ASTNode* root, QWidget* parent = nullptr);
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

signals:
    void linkClicked(const QString& url);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

private:
    ASTNode* rootNode;
    static const int MARGIN_TOP = 20;
    static const int MARGIN_BOTTOM = 20;
    static int MARGIN_LEFT;
    static const int MARGIN_RIGHT = 20;
    static const int LINE_HEIGHT = 20;
    
    struct ClickableArea {
        QRect rect;
        QString url;
    };
    std::vector<ClickableArea> clickableAreas;
    
    int totalHeight;
    
    void renderNode(const ASTNode* node, QPainter& painter, int& yPos, int indentLevel);
    void renderText(QPainter& painter, int& yPos, const std::string& text, int indent);
    void renderHeading(QPainter& painter, int& yPos, const std::string& text, int level);
    void renderList(QPainter& painter, int& yPos, const ASTNode* node, int indentLevel);
    void renderLink(QPainter& painter, int& yPos, const ASTNode* node, int indent);
    void renderImage(QPainter& painter, int& yPos, const ASTNode* node, int indent = 0);
    void renderFormattedText(QPainter& painter, int& yPos, const ASTNode* node, int indent);
    void renderParagraph(QPainter& painter, int& yPos, const ASTNode* node, int indent);

    void printNodeType(const ASTNode* node) {
        std::cout << "Node type: " << static_cast<int>(node->type) << std::endl;
    }
}; 
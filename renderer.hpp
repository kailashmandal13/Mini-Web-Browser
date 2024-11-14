#pragma once
#include <QWidget>
#include <QPainter>
#include <QFontMetrics>
#include <QMouseEvent>
#include <QDesktopServices>
#include <QUrl>
#include <iostream>
#include "ast.hpp"

class HTMLRenderer : public QWidget {
    Q_OBJECT
public:
    explicit HTMLRenderer(ASTNode* root, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

private:
    ASTNode* rootNode;
    const int MARGIN_LEFT = 20;
    const int MARGIN_RIGHT = 20;
    const int MARGIN_TOP = 20;
    const int LINE_HEIGHT = 20;
    
    struct ClickableArea {
        QRect rect;
        QString url;
    };
    std::vector<ClickableArea> clickableAreas;
    
    void renderNode(const ASTNode* node, QPainter& painter, int& yPos, int depth = 0);
    void renderText(QPainter& painter, int& yPos, const std::string& text, int indent = 0);
    void renderHeading(QPainter& painter, int& yPos, const std::string& text, int level);
    void renderList(QPainter& painter, int& yPos, const ASTNode* node, int depth);
    void renderLink(QPainter& painter, int& yPos, const ASTNode* node, int indent = 0);
    void renderImage(QPainter& painter, int& yPos, const ASTNode* node, int indent = 0);
    void renderFormattedText(QPainter& painter, int& yPos, const ASTNode* node, int indent = 0);
    void renderParagraph(QPainter& painter, int& yPos, const ASTNode* node, int indent = 0);

    void printNodeType(const ASTNode* node) {
        std::cout << "Node type: " << static_cast<int>(node->type) << std::endl;
    }
}; 
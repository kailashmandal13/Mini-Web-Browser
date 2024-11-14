#pragma once
#include <QWidget>
#include <QPainter>
#include <QFontMetrics>
#include "ast.hpp"

class HTMLRenderer : public QWidget {
    Q_OBJECT
public:
    explicit HTMLRenderer(ASTNode* root, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    ASTNode* rootNode;
    const int MARGIN_LEFT = 20;
    const int MARGIN_RIGHT = 20;
    const int MARGIN_TOP = 20;
    const int LINE_HEIGHT = 20;
    
    void renderNode(const ASTNode* node, QPainter& painter, int& yPos, int depth = 0);
    void renderText(QPainter& painter, int& yPos, const std::string& text, int indent = 0);
    void renderHeading(QPainter& painter, int& yPos, const std::string& text, int level);
    void renderList(QPainter& painter, int& yPos, const ASTNode* node, int depth);
    void renderLink(QPainter& painter, int& yPos, const std::string& text, int indent = 0);
}; 
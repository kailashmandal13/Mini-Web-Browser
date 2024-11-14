#include "renderer.hpp"
#include <iostream>

HTMLRenderer::HTMLRenderer(ASTNode* root, QWidget* parent) 
    : QWidget(parent), rootNode(root) {
    setMinimumSize(800, 600);
    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::white);
    setPalette(pal);
}

void HTMLRenderer::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    int yPos = MARGIN_TOP;
    
    if (rootNode) {
        renderNode(rootNode, painter, yPos);
    }
}

void HTMLRenderer::renderText(QPainter& painter, int& yPos, const std::string& text, int indent) {
    if (text.empty()) return;
    
    QFont font("Arial", 12);
    painter.setFont(font);
    
    QFontMetrics metrics(font);
    QString qtext = QString::fromStdString(text);
    int maxWidth = width() - (MARGIN_LEFT + indent + MARGIN_RIGHT);
    
    QStringList words = qtext.split(' ');
    QString currentLine;
    
    for (const QString& word : words) {
        QString testLine = currentLine.isEmpty() ? word : currentLine + ' ' + word;
        if (metrics.horizontalAdvance(testLine) <= maxWidth) {
            currentLine = testLine;
        } else {
            painter.drawText(MARGIN_LEFT + indent, yPos, currentLine);
            yPos += LINE_HEIGHT;
            currentLine = word;
        }
    }
    
    if (!currentLine.isEmpty()) {
        painter.drawText(MARGIN_LEFT + indent, yPos, currentLine);
        yPos += LINE_HEIGHT;
    }
}

void HTMLRenderer::renderHeading(QPainter& painter, int& yPos, const std::string& text, int level) {
    if (text.empty()) return;
    
    QFont font("Arial", 24 - ((level - 1) * 4));
    font.setBold(true);
    painter.setFont(font);
    
    yPos += 10;
    
    QString qtext = QString::fromStdString(text);
    painter.drawText(MARGIN_LEFT, yPos, qtext);
    yPos += font.pointSize() + 10;
}

void HTMLRenderer::renderList(QPainter& painter, int& yPos, const ASTNode* node, int depth) {
    if (!node || node->children.empty()) return;
    
    int indent = depth * 20;
    for (const auto* item : node->children) {
        if (!item) continue;
        
        if (item->type == NodeType::LIST_ITEM) {
            int bulletY = yPos - 5;
            painter.setBrush(Qt::black);
            painter.drawEllipse(QPoint(MARGIN_LEFT + indent + 5, bulletY), 2, 2);
            
            if (!item->children.empty()) {
                for (const auto* child : item->children) {
                    if (child) {
                        renderNode(child, painter, yPos, depth + 1);
                    }
                }
            }
        }
    }
}

void HTMLRenderer::renderLink(QPainter& painter, int& yPos, const std::string& text, int indent) {
    QFont font("Arial", 12);
    font.setUnderline(true);
    painter.setFont(font);
    
    QPen originalPen = painter.pen();
    painter.setPen(Qt::blue);
    
    painter.drawText(MARGIN_LEFT + indent, yPos, QString::fromStdString(text));
    yPos += LINE_HEIGHT;
    
    painter.setPen(originalPen);
    font.setUnderline(false);
    painter.setFont(font);
}

void HTMLRenderer::renderNode(const ASTNode* node, QPainter& painter, int& yPos, int depth) {
    if (!node) return;

    try {
        switch (node->type) {
            case NodeType::TEXT:
                if (!node->content.empty()) {
                    renderText(painter, yPos, node->content, depth * 20);
                }
                break;

            case NodeType::HEADING:
                if (!node->children.empty() && node->children[0]) {
                    renderHeading(painter, yPos, node->children[0]->content, node->heading_level);
                }
                break;

            case NodeType::LIST:
                renderList(painter, yPos, node, depth);
                break;

            case NodeType::LINK:
                if (!node->children.empty() && node->children[0]) {
                    renderLink(painter, yPos, node->children[0]->content, depth * 20);
                }
                break;

            case NodeType::PARAGRAPH:
                for (const auto* child : node->children) {
                    if (child) {
                        renderNode(child, painter, yPos, depth);
                    }
                }
                yPos += LINE_HEIGHT/2;
                break;

            default:
                for (const auto* child : node->children) {
                    if (child) {
                        renderNode(child, painter, yPos, depth);
                    }
                }
                break;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error rendering node: " << e.what() << std::endl;
    }
} 
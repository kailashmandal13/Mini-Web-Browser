#include "renderer.hpp"
#include <iostream>

HTMLRenderer::HTMLRenderer(ASTNode* root, QWidget* parent) 
    : QWidget(parent), rootNode(root), totalHeight(0) {
    setMinimumSize(800, 600);
    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::white);
    setPalette(pal);
}

void HTMLRenderer::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    // First pass: calculate total height
    int calculateYPos = MARGIN_TOP;
    clickableAreas.clear();
    
    if (rootNode) {
        renderNode(rootNode, painter, calculateYPos);
    }
    
    // Set the total height with extra padding
    totalHeight = calculateYPos + MARGIN_TOP + 100;  // Increased padding
    
    // Set minimum size based on content
    setMinimumHeight(totalHeight);
    
    // Second pass: actual rendering
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
    
    yPos += 20;
    
    QString qtext = QString::fromStdString(text);
    painter.drawText(MARGIN_LEFT, yPos, qtext);
    yPos += font.pointSize() + 20;
}

void HTMLRenderer::renderList(QPainter& painter, int& yPos, const ASTNode* node, int depth) {
    if (!node || node->children.empty()) return;
    
    // Debug print
    std::cout << "Rendering list with " << node->children.size() << " children" << std::endl;
    printNodeType(node);
    
    yPos += LINE_HEIGHT; // Space before list
    int indent = depth * 20;
    
    for (const auto* item : node->children) {
        if (!item) continue;
        
        // Debug print
        std::cout << "List item: " << std::endl;
        printNodeType(item);
        
        // Calculate positions
        int bulletX = MARGIN_LEFT + indent + 5;  // Bullet point position
        int bulletY = yPos - 5;  // Align with text baseline
        int textIndent = indent + 20;  // Text position after bullet
        
        // Draw bullet point
        painter.save();
        painter.setBrush(Qt::black);
        painter.setPen(Qt::black);
        painter.drawEllipse(QPoint(bulletX, bulletY), 3, 3);
        painter.restore();
        
        // Handle the content
        if (!item->children.empty()) {
            for (const auto* child : item->children) {
                if (!child) continue;
                
                // Debug print
                std::cout << "List item child: " << std::endl;
                printNodeType(child);
                
                if (child->type == NodeType::TEXT) {
                    renderText(painter, yPos, child->content, textIndent);
                } else if (child->type == NodeType::LINK) {
                    renderLink(painter, yPos, child, textIndent);
                } else {
                    renderNode(child, painter, yPos, depth + 1);
                }
            }
        }
        
        yPos += LINE_HEIGHT;  // Space after each item
    }
    
    yPos += LINE_HEIGHT / 2;  // Space after list
}

void HTMLRenderer::renderLink(QPainter& painter, int& yPos, const ASTNode* node, int indent) {
    if (!node || node->children.empty()) return;
    
    QFont font("Arial", 12);
    font.setUnderline(true);
    painter.setFont(font);
    
    QPen originalPen = painter.pen();
    painter.setPen(Qt::blue);
    
    QString text;
    if (!node->children.empty() && node->children[0]) {
        text = QString::fromStdString(node->children[0]->content);
    }
    
    // Extract href from attributes
    std::string attrs = node->attributes;
    size_t hrefStart = attrs.find("href=\"");
    if (hrefStart != std::string::npos) {
        hrefStart += 6; // length of 'href="'
        size_t hrefEnd = attrs.find("\"", hrefStart);
        if (hrefEnd != std::string::npos) {
            QString url = QString::fromStdString(attrs.substr(hrefStart, hrefEnd - hrefStart));
            
            QFontMetrics fm(font);
            int textWidth = fm.horizontalAdvance(text);
            QRect linkRect(MARGIN_LEFT + indent, yPos - fm.height(), textWidth, fm.height());
            
            clickableAreas.push_back({linkRect, url});
        }
    }
    
    painter.drawText(MARGIN_LEFT + indent, yPos, text);
    yPos += LINE_HEIGHT * 1.5; // Increased line spacing
    
    painter.setPen(originalPen);
    font.setUnderline(false);
    painter.setFont(font);
}

void HTMLRenderer::renderFormattedText(QPainter& painter, int& yPos, const ASTNode* node, int indent) {
    if (!node) return;
    
    QFont originalFont = painter.font();
    QFont formattedFont = originalFont;
    QPen originalPen = painter.pen();
    
    bool isBlockquote = node->attributes.find("type=\"blockquote\"") != std::string::npos;
    
    // Apply formatting based on type
    if (node->attributes.find("type=\"strong\"") != std::string::npos) {
        formattedFont.setBold(true);
        painter.setFont(formattedFont);
    } else if (node->attributes.find("type=\"emphasis\"") != std::string::npos) {
        formattedFont.setItalic(true);
        painter.setFont(formattedFont);
    } else if (node->attributes.find("type=\"preformatted\"") != std::string::npos) {
        formattedFont.setFamily("Courier New");
        painter.setFont(formattedFont);
    } else if (isBlockquote) {
        yPos += 20;  // Increased spacing before blockquote
        indent += 40;  // Increased indentation for blockquote
    }
    
    // Handle text content
    if (!node->content.empty()) {
        painter.drawText(MARGIN_LEFT + indent, yPos, QString::fromStdString(node->content));
    }
    
    // Handle child nodes
    for (const auto* child : node->children) {
        if (child && child->type == NodeType::TEXT) {
            painter.drawText(MARGIN_LEFT + indent, yPos, 
                           QString::fromStdString(child->content));
            yPos += LINE_HEIGHT;  // Add line spacing after each text node
        } else if (child) {
            renderNode(child, painter, yPos, indent);
        }
    }
    
    // Add extra spacing after blockquote
    if (isBlockquote) {
        yPos += 20;  // Increased spacing after blockquote
    }
    
    // Reset font and pen
    painter.setFont(originalFont);
    painter.setPen(originalPen);
}

void HTMLRenderer::renderParagraph(QPainter& painter, int& yPos, const ASTNode* node, int indent) {
    if (!node) return;
    
    QFont font("Arial", 12);
    painter.setFont(font);
    
    int xPos = MARGIN_LEFT + indent;
    
    // First pass: calculate total width
    int totalWidth = 0;
    for (const auto* child : node->children) {
        if (!child) continue;
        
        if (child->type == NodeType::TEXT) {
            QString text = QString::fromStdString(child->content);
            QFontMetrics metrics(painter.font());
            totalWidth += metrics.horizontalAdvance(text + " ");
        } else if (child->type == NodeType::FORMATTED_TEXT) {
            // Handle formatted text width calculation
            QString text;
            if (!child->content.empty()) {
                text = QString::fromStdString(child->content);
            } else if (!child->children.empty() && child->children[0]) {
                text = QString::fromStdString(child->children[0]->content);
            }
            QFont tempFont = font;
            if (child->attributes.find("type=\"strong\"") != std::string::npos) {
                tempFont.setBold(true);
            } else if (child->attributes.find("type=\"emphasis\"") != std::string::npos) {
                tempFont.setItalic(true);
            }
            QFontMetrics metrics(tempFont);
            totalWidth += metrics.horizontalAdvance(text + " ");
        }
    }
    
    // Second pass: render
    for (const auto* child : node->children) {
        if (!child) continue;
        
        if (child->type == NodeType::TEXT) {
            QString text = QString::fromStdString(child->content);
            painter.drawText(xPos, yPos, text);
            QFontMetrics metrics(painter.font());
            xPos += metrics.horizontalAdvance(text + " ");
        } else if (child->type == NodeType::FORMATTED_TEXT) {
            QFont tempFont = font;
            if (child->attributes.find("type=\"strong\"") != std::string::npos) {
                tempFont.setBold(true);
            } else if (child->attributes.find("type=\"emphasis\"") != std::string::npos) {
                tempFont.setItalic(true);
            } else if (child->attributes.find("type=\"preformatted\"") != std::string::npos) {
                tempFont.setFamily("Courier New");
            }
            painter.setFont(tempFont);
            
            QString text;
            if (!child->content.empty()) {
                text = QString::fromStdString(child->content);
            } else if (!child->children.empty() && child->children[0]) {
                text = QString::fromStdString(child->children[0]->content);
            }
            
            painter.drawText(xPos, yPos, text);
            QFontMetrics metrics(tempFont);
            xPos += metrics.horizontalAdvance(text + " ");
            painter.setFont(font);
        }
    }
    
    yPos += LINE_HEIGHT * 1.5; // Increased from LINE_HEIGHT
}

void HTMLRenderer::renderNode(const ASTNode* node, QPainter& painter, int& yPos, int depth) {
    if (!node) return;

    try {
        // Debug print
        std::cout << "Rendering node: " << std::endl;
        printNodeType(node);
        
        switch (node->type) {
            case NodeType::LIST:  // Make sure this case exists
                renderList(painter, yPos, node, depth);
                break;
                
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

            case NodeType::PARAGRAPH:
                renderParagraph(painter, yPos, node, depth * 20);
                break;

            case NodeType::FORMATTED_TEXT:
                renderFormattedText(painter, yPos, node, depth * 20);
                break;

            case NodeType::LINK:
                renderLink(painter, yPos, node, depth * 20);
                break;

            case NodeType::IMAGE:
                renderImage(painter, yPos, node, depth * 20);
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

void HTMLRenderer::mousePressEvent(QMouseEvent* event) {
    for (const auto& area : clickableAreas) {
        if (area.rect.contains(event->pos())) {
            QDesktopServices::openUrl(QUrl(area.url));
            break;
        }
    }
}

void HTMLRenderer::renderImage(QPainter& painter, int& yPos, const ASTNode* node, int indent) {
    if (!node) return;
    
    // Extract src from attributes
    std::string attrs = node->attributes;
    size_t srcStart = attrs.find("src=\"");
    if (srcStart != std::string::npos) {
        srcStart += 5; // length of 'src="'
        size_t srcEnd = attrs.find("\"", srcStart);
        if (srcEnd != std::string::npos) {
            QString imagePath = QString::fromStdString(attrs.substr(srcStart, srcEnd - srcStart));
            QImage image(imagePath);
            
            if (!image.isNull()) {
                // Scale image if needed while maintaining aspect ratio
                int maxWidth = width() - (MARGIN_LEFT + indent + MARGIN_RIGHT);
                if (image.width() > maxWidth) {
                    image = image.scaledToWidth(maxWidth, Qt::SmoothTransformation);
                }
                
                painter.drawImage(MARGIN_LEFT + indent, yPos, image);
                yPos += image.height() + LINE_HEIGHT * 2; // Add space after image
            }
        }
    }
}

QSize HTMLRenderer::sizeHint() const {
    return QSize(800, totalHeight);
}

QSize HTMLRenderer::minimumSizeHint() const {
    return QSize(400, std::min(600, totalHeight));
} 
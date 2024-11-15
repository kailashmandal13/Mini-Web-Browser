#include "renderer.hpp"
#include <QDebug>

HTMLRenderer::HTMLRenderer(ASTNode* root, QWidget* parent) 
    : QWidget(parent), rootNode(root), totalHeight(0) {
    qDebug() << "Creating HTMLRenderer with root node:" << (root ? "valid" : "null");
    setMinimumSize(800, 600);
    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::white);
    setPalette(pal);
}

void HTMLRenderer::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    // Set default font
    QFont defaultFont("Arial", 12);
    painter.setFont(defaultFont);
    
    // Set default text color
    painter.setPen(Qt::black);
    
    // First pass: calculate total height
    int yPos = MARGIN_TOP;
    clickableAreas.clear();
    
    if (rootNode) {
        renderNode(rootNode, painter, yPos, 0);
    }
    
    // Set the total height with extra padding
    totalHeight = yPos + MARGIN_BOTTOM;
    setMinimumHeight(totalHeight);
}

void HTMLRenderer::renderText(QPainter& painter, int& yPos, const std::string& text, int xOffset) {
    // Skip if this is title text and we're not in a heading
    if (text.empty()) return;
    
    QFontMetrics fm(painter.font());
    QString qtext = QString::fromStdString(text);
    
    // Word wrap the text
    QRect bounds(MARGIN_LEFT + xOffset, yPos, 
                width() - (2 * MARGIN_LEFT + xOffset), LINE_HEIGHT);
    QRect usedRect = fm.boundingRect(bounds, 
                                   Qt::TextWordWrap | Qt::AlignLeft | Qt::AlignTop,
                                   qtext);
    
    painter.drawText(bounds, Qt::TextWordWrap | Qt::AlignLeft | Qt::AlignTop, qtext);
    yPos += usedRect.height() + 5;  // Add a small gap between text blocks
}

void HTMLRenderer::renderHeading(QPainter& painter, int& yPos, const std::string& text, int level) {
    QFont font = painter.font();
    int fontSize;
    
    // Set font size based on heading level
    switch (level) {
        case 1: fontSize = 32; break;
        case 2: fontSize = 28; break;
        case 3: fontSize = 24; break;
        case 4: fontSize = 20; break;
        case 5: fontSize = 18; break;
        default: fontSize = 16; break;
    }
    
    // Save the current font
    QFont oldFont = painter.font();
    
    // Set up heading font
    font.setPointSize(fontSize);
    font.setBold(true);
    painter.setFont(font);
    
    // Calculate text height
    QFontMetrics fm(font);
    QString qtext = QString::fromStdString(text);
    QRect textRect = fm.boundingRect(QRect(MARGIN_LEFT, yPos, 
                                         width() - 2 * MARGIN_LEFT, fontSize * 2),
                                   Qt::TextWordWrap | Qt::AlignLeft,
                                   qtext);
    
    // Draw the heading text
    painter.drawText(textRect, Qt::TextWordWrap | Qt::AlignLeft, qtext);
    
    // Update yPos to include only the text height
    yPos = textRect.bottom();
    
    // Restore the original font
    painter.setFont(oldFont);
}

void HTMLRenderer::renderList(QPainter& painter, int& yPos, const ASTNode* node, int depth) {
    int bulletX = MARGIN_LEFT + depth * 20;
    int textX = bulletX + 20;  // Space for bullet/number
    bool isOrdered = node->attributes.find("type=\"ordered\"") != std::string::npos;
    int itemNumber = 1;  // Counter for ordered lists
    
    for (const auto* child : node->children) {
        if (child && child->type == NodeType::LIST_ITEM) {
            QFontMetrics fm(painter.font());
            int bulletBaseline = yPos + fm.ascent();
            
            // First render the content to get its height
            for (const auto* itemChild : child->children) {
                if (itemChild) {
                    int savedMargin = MARGIN_LEFT;
                    MARGIN_LEFT = textX;
                    renderNode(itemChild, painter, yPos, depth);
                    MARGIN_LEFT = savedMargin;
                }
            }
            
            // Draw bullet point or number
            if (isOrdered) {
                painter.drawText(QPoint(bulletX, bulletBaseline), 
                               QString::number(itemNumber++) + ".");
            } else {
                painter.drawText(QPoint(bulletX, bulletBaseline), "•");
            }
            
            yPos += 5;
        }
    }
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
    
    // Get text content from node or its children
    QString text;
    if (!node->content.empty()) {
        text = QString::fromStdString(node->content);
    } else if (!node->children.empty() && node->children[0] && 
               node->children[0]->type == NodeType::TEXT) {
        text = QString::fromStdString(node->children[0]->content);
    }

    // Special handling for different types
    if (node->attributes.find("type=\"blockquote\"") != std::string::npos) {
        // Add left margin for blockquote
        int blockquoteIndent = 40;
        QFontMetrics fm(formattedFont);
        
        QRect textRect(MARGIN_LEFT + indent + blockquoteIndent, yPos - fm.ascent(),
                      width() - (MARGIN_LEFT + indent + blockquoteIndent + MARGIN_RIGHT),
                      fm.height() * 2);
                      
        painter.drawText(textRect, Qt::TextWordWrap | Qt::AlignLeft, text);
        yPos += fm.boundingRect(textRect, Qt::TextWordWrap | Qt::AlignLeft, text).height() + LINE_HEIGHT;
        return;
    }
    else if (node->attributes.find("type=\"code\"") != std::string::npos) {
        formattedFont.setFamily("Courier New");
        painter.setFont(formattedFont);
        QFontMetrics fm(formattedFont);
        
        // Draw background
        QRect bgRect(MARGIN_LEFT + indent, yPos - fm.ascent(),
                    width() - (MARGIN_LEFT + indent + MARGIN_RIGHT),
                    fm.height());
        painter.fillRect(bgRect, QColor(240, 240, 240));
        
        // Draw text
        painter.drawText(MARGIN_LEFT + indent + 5, yPos, text);
        yPos += LINE_HEIGHT;
        return;
    }
    else if (node->attributes.find("type=\"small\"") != std::string::npos) {
        formattedFont.setPointSize(originalFont.pointSize() * 0.8);
        painter.setFont(formattedFont);
        painter.drawText(MARGIN_LEFT + indent, yPos, text);
        yPos += LINE_HEIGHT;
        return;
    }
    else if (node->attributes.find("type=\"strong\"") != std::string::npos) {
        formattedFont.setBold(true);
    }
    else if (node->attributes.find("type=\"emphasis\"") != std::string::npos) {
        formattedFont.setItalic(true);
    }
    else if (node->attributes.find("type=\"underline\"") != std::string::npos) {
        formattedFont.setUnderline(true);
    }
    
    painter.setFont(formattedFont);
    
    // Handle regular formatted text
    if (!text.isEmpty()) {
        painter.drawText(MARGIN_LEFT + indent, yPos, text);
        yPos += LINE_HEIGHT;
    } else {
        // Process children only if we haven't rendered text directly
        for (const auto* child : node->children) {
            if (child) {
                renderNode(child, painter, yPos, indent);
            }
        }
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
    
    // Don't add extra spacing here - let the parent handle spacing
}

void HTMLRenderer::renderNode(const ASTNode* node, QPainter& painter, int& yPos, int indentLevel) {
    if (!node) return;
    
    qDebug() << "Rendering node type:" << static_cast<int>(node->type);
    
    try {
        // Skip rendering the HEAD section content
        if (node->type == NodeType::HEAD) {
            return;
        }

        switch (node->type) {
            case NodeType::TEXT:
                renderText(painter, yPos, node->content, indentLevel * 20);
                break;

            case NodeType::HEADING:
                if (node->children.size() > 0 && node->children[0]->type == NodeType::TEXT) {
                    renderHeading(painter, yPos, node->children[0]->content, node->heading_level);
                    yPos += LINE_HEIGHT * 2;  // Doubled the spacing after headings
                }
                break;

            case NodeType::PARAGRAPH:
                renderParagraph(painter, yPos, node, indentLevel * 20);
                yPos += LINE_HEIGHT;  // Keep paragraph spacing as is
                break;

            case NodeType::LIST:
                renderList(painter, yPos, node, indentLevel);
                break;

            case NodeType::FORMATTED_TEXT:
                renderFormattedText(painter, yPos, node, indentLevel * 20);
                break;

            case NodeType::LINK:
                renderLink(painter, yPos, node, indentLevel * 20);
                break;

            case NodeType::IMAGE: {
                // Extract image source from attributes
                std::string src;
                size_t srcPos = node->attributes.find("src=\"");
                if (srcPos != std::string::npos) {
                    srcPos += 5; // length of 'src="'
                    size_t endPos = node->attributes.find("\"", srcPos);
                    if (endPos != std::string::npos) {
                        src = node->attributes.substr(srcPos, endPos - srcPos);
                    }
                }

                if (!src.empty()) {
                    QImage image(QString::fromStdString(src));
                    if (!image.isNull()) {
                        // Scale image if it's too large
                        int maxWidth = width() - (MARGIN_LEFT + indentLevel + MARGIN_RIGHT);
                        if (image.width() > maxWidth) {
                            image = image.scaledToWidth(maxWidth, Qt::SmoothTransformation);
                        }
                        
                        // Draw the image
                        painter.drawImage(QPoint(MARGIN_LEFT + indentLevel, yPos), image);
                        yPos += image.height() + LINE_HEIGHT;
                    } else {
                        // Draw placeholder or alt text if image can't be loaded
                        QString altText = "Image not found";
                        size_t altPos = node->attributes.find("alt=\"");
                        if (altPos != std::string::npos) {
                            altPos += 5; // length of 'alt="'
                            size_t endPos = node->attributes.find("\"", altPos);
                            if (endPos != std::string::npos) {
                                altText = QString::fromStdString(node->attributes.substr(altPos, endPos - altPos));
                            }
                        }
                        painter.drawText(MARGIN_LEFT + indentLevel, yPos, "[" + altText + "]");
                        yPos += LINE_HEIGHT;
                    }
                }
                break;
            }

            default:
                // Recursively render children for other node types
                for (const auto* child : node->children) {
                    renderNode(child, painter, yPos, indentLevel);
                }
                break;
        }
    } catch (const std::exception& e) {
        qDebug() << "Error rendering node:" << e.what();
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

QSize HTMLRenderer::sizeHint() const {
    return QSize(800, totalHeight);
}

QSize HTMLRenderer::minimumSizeHint() const {
    return QSize(400, std::min(600, totalHeight));
}

int HTMLRenderer::MARGIN_LEFT = 20; 
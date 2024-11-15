#include "renderer.hpp"
#include <QDebug>

HTMLRenderer::HTMLRenderer(ASTNode* root, QWidget* parent) 
    : QWidget(parent), rootNode(root) {
    qDebug() << "Creating HTMLRenderer with root node:" << (root ? "valid" : "null");
    
    // Calculate total height
    calculateTotalHeight(root, totalHeight);
    totalHeight += MARGIN_TOP + MARGIN_BOTTOM;
    
    setMinimumSize(800, totalHeight);
    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::white);
    setPalette(pal);
}

HTMLRenderer::~HTMLRenderer() {
    delete rootNode;  // Clean up the AST when renderer is destroyed
}

void HTMLRenderer::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    // Set default font
    QFont defaultFont("Arial", 12);
    painter.setFont(defaultFont);
    
    // Set default text color
    painter.setPen(Qt::black);
    
    int yPos = MARGIN_TOP;
    clickableAreas.clear();
    
    if (rootNode) {
        renderNode(rootNode, painter, yPos, 0);
    }
    
    totalHeight = yPos + MARGIN_BOTTOM;
    setMinimumHeight(totalHeight);
    update();
}

void HTMLRenderer::renderNode(const ASTNode* node, QPainter& painter, int& yPos, int indentLevel) {
    if (!node) return;
    
    qDebug() << "Rendering node type:" << ASTNode::get_node_type_str(node->type).c_str();
    
    try {
        switch (node->type) {
            case NodeType::ROOT:
            case NodeType::HTML:
            case NodeType::BODY:
            case NodeType::NAV:
            case NodeType::HEADER:
            case NodeType::SECTION:
            case NodeType::ARTICLE:
            case NodeType::ASIDE:
            case NodeType::FOOTER:
                // Container nodes - just render children
                for (const auto* child : node->children) {
                    renderNode(child, painter, yPos, indentLevel);
                }
                break;

            case NodeType::HEAD:
            case NodeType::TITLE:
                // Skip HEAD and TITLE nodes completely
                break;

            case NodeType::TEXT:
                renderText(painter, yPos, node->content, indentLevel * 20);
                break;

            case NodeType::HEADING: {
                // Get text from the first TEXT child node
                std::string headingText;
                if (!node->children.empty() && node->children[0] && 
                    node->children[0]->type == NodeType::TEXT) {
                    headingText = node->children[0]->content;
                }
                renderHeading(painter, yPos, headingText, node->heading_level);
                yPos += LINE_HEIGHT;
                break;
            }

            case NodeType::PARAGRAPH:
                renderParagraph(painter, yPos, node, indentLevel * 20);
                break;

            case NodeType::LIST:
                renderList(painter, yPos, node, indentLevel);
                break;

            case NodeType::LIST_ITEM:
                // List items are handled by renderList
                break;

            case NodeType::LINK:
                renderLink(painter, yPos, node, indentLevel * 20);
                break;

            case NodeType::IMAGE:
                renderImage(painter, yPos, node, indentLevel * 20);
                break;

            case NodeType::FORMATTED_TEXT:
                renderFormattedText(painter, yPos, node, indentLevel * 20);
                break;

            case NodeType::CONTAINER:
                // Generic container - just render children
                for (const auto* child : node->children) {
                    renderNode(child, painter, yPos, indentLevel);
                }
                break;
        }
    } catch (const std::exception& e) {
        qDebug() << "Error rendering node:" << e.what();
    }
}

void HTMLRenderer::calculateTotalHeight(const ASTNode* node, int& height, int indentLevel) {
    if (!node) return;
    
    if (node->type == NodeType::TEXT) {
        height += LINE_HEIGHT;
    }
    else if (node->type == NodeType::HEADING) {
        height += LINE_HEIGHT * 2;
    }
    else if (node->type == NodeType::PARAGRAPH) {
        height += LINE_HEIGHT * 1.5;
    }
    else if (node->type == NodeType::LIST) {
        height += LINE_HEIGHT;  // Add space for the list itself
    }
    else if (node->type == NodeType::IMAGE) {
        height += LINE_HEIGHT * 3;  // Approximate space for images
    }
    
    // Always process children for all node types
    for (const auto* child : node->children) {
        calculateTotalHeight(child, height, indentLevel + 1);
    }
}

void HTMLRenderer::renderText(QPainter& painter, int& yPos, const std::string& text, int indent) {
    QFontMetrics fm(painter.font());
    int availableWidth = width() - (MARGIN_LEFT + indent + MARGIN_RIGHT);
    
    QString qtext = QString::fromStdString(text);
    QRect boundingRect = fm.boundingRect(MARGIN_LEFT + indent, yPos, 
                                       availableWidth, LINE_HEIGHT * 10,
                                       Qt::TextWordWrap, qtext);
    
    painter.drawText(boundingRect, Qt::TextWordWrap | Qt::AlignLeft, qtext);
    yPos += boundingRect.height() + 5;
}

void HTMLRenderer::renderHeading(QPainter& painter, int& yPos, const std::string& text, int level) {
    // Add spacing before heading
    yPos += LINE_HEIGHT;
    
    QFont originalFont = painter.font();
    QFont headingFont("Arial");
    
    // Set font size based on heading level
    switch (level) {
        case 1: headingFont.setPointSize(28); break;
        case 2: headingFont.setPointSize(24); break;
        case 3: headingFont.setPointSize(20); break;
        case 4: headingFont.setPointSize(18); break;
        case 5: headingFont.setPointSize(16); break;
        default: headingFont.setPointSize(14); break;
    }
    
    headingFont.setBold(true);
    painter.setFont(headingFont);
    
    // Draw the heading
    QString qtext = QString::fromStdString(text);
    QFontMetrics fm(headingFont);
    painter.drawText(QPoint(MARGIN_LEFT, yPos + fm.ascent()), qtext);
    
    // Update yPos and add spacing after heading
    yPos += fm.height() + LINE_HEIGHT;
    
    // Restore original font
    painter.setFont(originalFont);
}

void HTMLRenderer::renderParagraph(QPainter& painter, int& yPos, const ASTNode* node, int indent) {
    yPos += LINE_HEIGHT / 2;  // Space before paragraph
    
    int currentX = MARGIN_LEFT + indent;
    int lineStartY = yPos;
    QFontMetrics defaultFm(painter.font());
    int lineHeight = defaultFm.height();
    QFont originalFont = painter.font();
    
    auto renderPiece = [&](const QString& text, const QFont& font) {
        painter.setFont(font);
        QFontMetrics fm(font);
        int textWidth = fm.horizontalAdvance(text);
        
        if (currentX + textWidth > width() - MARGIN_RIGHT) {
            currentX = MARGIN_LEFT + indent;
            lineStartY += lineHeight;
        }
        
        painter.drawText(QPoint(currentX, lineStartY + fm.ascent()), text);
        currentX += textWidth + fm.horizontalAdvance(" ");
        painter.setFont(originalFont);
    };
    
    std::function<void(const ASTNode*)> processNode = [&](const ASTNode* n) {
        if (!n) return;
        
        if (n->type == NodeType::TEXT) {
            renderPiece(QString::fromStdString(n->content), originalFont);
        }
        else if (n->type == NodeType::FORMATTED_TEXT) {
            QFont formattedFont = originalFont;
            if (n->attributes.find("type=\"strong\"") != std::string::npos) {
                formattedFont.setBold(true);
            }
            else if (n->attributes.find("type=\"emphasis\"") != std::string::npos) {
                formattedFont.setItalic(true);
            }
            
            // Get text from node or its children
            QString text;
            if (!n->content.empty()) {
                text = QString::fromStdString(n->content);
            } else if (!n->children.empty() && n->children[0]) {
                text = QString::fromStdString(n->children[0]->content);
            }
            
            if (!text.isEmpty()) {
                renderPiece(text, formattedFont);
                return; // Skip processing children since we've already used their content
            }
        }
        
        // Only process children for non-FORMATTED_TEXT nodes
        if (n->type != NodeType::FORMATTED_TEXT) {
            for (const auto* child : n->children) {
                processNode(child);
            }
        }
    };
    
    processNode(node);
    
    yPos = lineStartY + lineHeight + LINE_HEIGHT/2;
}

void HTMLRenderer::renderList(QPainter& painter, int& yPos, const ASTNode* node, int indentLevel) {
    bool isOrdered = node->attributes.find("type=\"ordered\"") != std::string::npos;
    int itemNumber = 1;
    int indent = indentLevel * 20 + 20;  // Additional indent for list items
    
    for (const auto* child : node->children) {
        if (child->type == NodeType::LIST_ITEM) {
            QString marker = isOrdered ? QString::number(itemNumber++) + "."
                                     : "•";
            
            // Draw bullet point or number
            painter.drawText(QRect(MARGIN_LEFT + indent - 20, yPos,
                                 20, LINE_HEIGHT),
                           Qt::AlignRight | Qt::AlignVCenter,
                           marker);
            
            // Render list item content with proper indentation
            for (const auto* itemChild : child->children) {
                renderNode(itemChild, painter, yPos, indentLevel + 2);
            }
            
            yPos += 5;  // Space between list items
        }
    }
    
    yPos += 10;  // Space after list
}

void HTMLRenderer::renderFormattedText(QPainter& painter, int& yPos, const ASTNode* node, int indent) {
    if (!node) return;
    
    // Handle block-level formatted elements
    if (node->attributes.find("type=\"blockquote\"") != std::string::npos ||
        node->attributes.find("type=\"code\"") != std::string::npos ||
        node->attributes.find("type=\"pre\"") != std::string::npos) {
        
        QFont originalFont = painter.font();
        QFont formattedFont = originalFont;
        
        if (node->attributes.find("type=\"blockquote\"") != std::string::npos) {
            formattedFont.setItalic(true);
            painter.setFont(formattedFont);
            
            QString text = QString::fromStdString(node->content);
            if (text.isEmpty() && !node->children.empty() && node->children[0]) {
                text = QString::fromStdString(node->children[0]->content);
            }
            
            QRect textRect(MARGIN_LEFT + 20, yPos,
                         width() - (MARGIN_LEFT + 20 + MARGIN_RIGHT),
                         QFontMetrics(formattedFont).height() * 2);
            
            painter.drawText(textRect, Qt::TextWordWrap | Qt::AlignLeft, text);
            yPos += QFontMetrics(formattedFont).boundingRect(textRect, Qt::TextWordWrap, text).height() + LINE_HEIGHT;
        }
        else if (node->attributes.find("type=\"code\"") != std::string::npos ||
                 node->attributes.find("type=\"pre\"") != std::string::npos) {
            formattedFont.setFamily("Courier New");
            painter.setFont(formattedFont);
            
            // Calculate text bounds
            QString text = QString::fromStdString(node->content);
            if (text.isEmpty() && !node->children.empty() && node->children[0]) {
                text = QString::fromStdString(node->children[0]->content);
            }
            
            QRect textBounds = painter.fontMetrics().boundingRect(
                QRect(0, 0, width() - (MARGIN_LEFT + indent + MARGIN_RIGHT), LINE_HEIGHT * 10),
                Qt::TextWordWrap,
                text
            );
            
            // Draw background slightly larger than text
            QRect bgRect(MARGIN_LEFT + indent, 
                        yPos, 
                        textBounds.width() + 10,  // Add padding
                        textBounds.height() + 10);
            painter.fillRect(bgRect, QColor(240, 240, 240));
            
            // Draw text with padding
            painter.drawText(
                QRect(MARGIN_LEFT + indent + 5,  // 5px padding
                      yPos + 5,
                      bgRect.width() - 10,
                      bgRect.height() - 10),
                Qt::TextWordWrap,
                text
            );
            
            yPos += bgRect.height() + LINE_HEIGHT;
        }
        
        painter.setFont(originalFont);
    }
    // Inline formatting is handled by renderParagraph
}

void HTMLRenderer::renderLink(QPainter& painter, int& yPos, const ASTNode* node, int indent) {
    // Save original pen and font
    QPen originalPen = painter.pen();
    QFont originalFont = painter.font();
    
    // Set link style
    painter.setPen(Qt::blue);
    QFont linkFont = originalFont;
    linkFont.setUnderline(true);
    painter.setFont(linkFont);
    
    // Extract href from attributes
    size_t hrefStart = node->attributes.find("href=\"");
    QString url;
    if (hrefStart != std::string::npos) {
        hrefStart += 6;  // Length of 'href="'
        size_t hrefEnd = node->attributes.find("\"", hrefStart);
        if (hrefEnd != std::string::npos) {
            url = QString::fromStdString(node->attributes.substr(hrefStart, hrefEnd - hrefStart));
        }
    }
    
    // Get link text from content or first child
    QString text = QString::fromStdString(
        node->children.empty() ? node->content : node->children[0]->content
    );
    
    // Calculate text rectangle
    QFontMetrics fm(painter.font());
    QRect textRect(MARGIN_LEFT + indent, yPos,
                  width() - (MARGIN_LEFT + indent + MARGIN_RIGHT),
                  fm.height());
    
    // Draw the link text
    painter.drawText(textRect, Qt::TextWordWrap, text);
    
    // Store clickable area
    if (!url.isEmpty()) {
        clickableAreas.push_back({textRect, url});
    }
    
    yPos += textRect.height() + 5;
    
    // Restore original style
    painter.setPen(originalPen);
    painter.setFont(originalFont);
}

void HTMLRenderer::renderImage(QPainter& painter, int& yPos, const ASTNode* node, int indent) {
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
            int maxWidth = width() - (MARGIN_LEFT + indent + MARGIN_RIGHT);
            if (image.width() > maxWidth) {
                image = image.scaledToWidth(maxWidth, Qt::SmoothTransformation);
            }
            
            // Draw the image
            painter.drawImage(QPoint(MARGIN_LEFT + indent, yPos), image);
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
            painter.drawText(MARGIN_LEFT + indent, yPos, "[" + altText + "]");
            yPos += LINE_HEIGHT;
        }
    }
}

void HTMLRenderer::mousePressEvent(QMouseEvent* event) {
    QPoint pos = event->pos();
    for (const auto& area : clickableAreas) {
        if (area.rect.contains(pos)) {
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
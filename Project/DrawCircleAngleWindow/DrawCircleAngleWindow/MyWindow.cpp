#include "MyWindow.h"
#include <QPainter>

MyWindow::MyWindow(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

void MyWindow::setType(Type t)
{
    m_type = t;
}

void MyWindow::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // ¿¹¾â³İ

    painter.setClipping(true);
    QPainterPath canDrawingPathArea; // ÄÜ»­ÉÏµÄÇøÓò
    canDrawingPathArea.addRoundedRect(rect(), 50, 50);
    canDrawingPathArea.setFillRule(Qt::WindingFill); // ¶à¿éÇøÓò×éºÏÌî³äÄ£Ê½

    switch (m_type)
    {
    case LeftTop:// ×óÉÏ½ÇÔ²½Ç
    {
        canDrawingPathArea.addRect(0, height() - 50, 50, 50); // Ìî³ä×óÏÂ½Ç
        canDrawingPathArea.addRect(width() - 50, 0, 50, 50); // Ìî³äÓÒÉÏ½Ç
        canDrawingPathArea.addRect(width() - 50, height() - 50, 50, 50);// Ìî³äÓÒÏÂ½Ç
        break;
    }
    case RightTop: // ÓÒÉÏ½ÇÔ²½Ç
    {
        canDrawingPathArea.addRect(0, height() - 50, 50, 50); // Ìî³ä×óÏÂ½Ç
        canDrawingPathArea.addRect(0, 0, 50, 50); // Ìî³ä×óÉÏ½Ç
        canDrawingPathArea.addRect(width() - 50, height() - 50, 50, 50);// Ìî³äÓÒÏÂ½Ç
        break;
    }
    case LeftBottom:// ×óÏÂ½ÇÔ²½Ç
    {
        canDrawingPathArea.addRect(width() - 50, 0, 50, 50); // Ìî³äÓÒÉÏ½Ç
        canDrawingPathArea.addRect(width() - 50, height() - 50, 50, 50);// Ìî³äÓÒÏÂ½Ç
        canDrawingPathArea.addRect(0, 0, 50, 50); // Ìî³ä×óÉÏ½Ç
        break;
    }
    case RightBottom: // ÓÒÏÂ½ÇÔ²½Ç
    {
        canDrawingPathArea.addRect(0, height() - 50, 50, 50); // Ìî³ä×óÏÂ½Ç
        canDrawingPathArea.addRect(width() - 50, 0, 50, 50); // Ìî³äÓÒÉÏ½Ç
        canDrawingPathArea.addRect(0, 0, 50, 50); // Ìî³ä×óÉÏ½Ç
        break;
    }
    case Top:         // ÉÏÁ½¸öÔ²½Ç
    {
        canDrawingPathArea.addRect(0, height() - 50, 50, 50); // Ìî³ä×óÏÂ½Ç
        canDrawingPathArea.addRect(width() - 50, height() - 50, 50, 50);// Ìî³äÓÒÏÂ½Ç
        break;
    }
    case Bottom:     // ÏÂÁ½¸öÔ²½Ç
    {
        canDrawingPathArea.addRect(width() - 50, 0, 50, 50); // Ìî³äÓÒÉÏ½Ç
        canDrawingPathArea.addRect(0, 0, 50, 50); // Ìî³ä×óÉÏ½Ç
        break;
    }
    case Left:  // ×óÁ½¸öÔ²½Ç
    {
        canDrawingPathArea.addRect(width() - 50, 0, 50, 50); // Ìî³äÓÒÉÏ½Ç
        canDrawingPathArea.addRect(width() - 50, height() - 50, 50, 50);// Ìî³äÓÒÏÂ½Ç
        break;
    }
    case Right:      // ÓÒÁ½¸öÔ²½Ç
    {
        canDrawingPathArea.addRect(0, height() - 50, 50, 50); // Ìî³ä×óÏÂ½Ç
        canDrawingPathArea.addRect(0, 0, 50, 50); // Ìî³ä×óÉÏ½Ç
        break;
    }
    case All:          // ËÄ¸ö½ÇÔ²½Ç
    {
        break;
    }
    default:
        break;
    }
    painter.setClipPath(canDrawingPathArea);

    QColor color(Qt::darkRed);
    color.setAlpha(200);
    painter.setPen(Qt::NoPen);
    painter.setBrush(color);
    painter.drawRect(rect());

    return QWidget::paintEvent(event);
}

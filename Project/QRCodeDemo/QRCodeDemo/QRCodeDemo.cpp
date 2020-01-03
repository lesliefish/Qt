#include "QRCodeDemo.h"
#include <QPainter>
#include "qrcode/qrencode.h"

QRCodeDemo::QRCodeDemo(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    setWindowTitle(QStringLiteral("二维码生成示例"));
}

void QRCodeDemo::setCodeString(const QString& strCodeString)
{
    m_strCodeString = strCodeString;
}

void QRCodeDemo::paintEvent(QPaintEvent *event)
{
    QRcode *qrcode;
    qrcode = QRcode_encodeString(m_strCodeString.toStdString().c_str(), 2, QR_ECLEVEL_Q, QR_MODE_8, 1);
    if (nullptr == qrcode)
    {
        return QWidget::paintEvent(event);
    }
    qint32 temp_width = ui.label->width();
    qint32 temp_height = ui.label->height();
    qint32 qrcode_width = qrcode->width > 0 ? qrcode->width : 1;
    double scale_x = (double)temp_width / (double)qrcode_width;
    double scale_y = (double)temp_height / (double)qrcode_width;
    QImage mainimg = QImage(temp_width, temp_height, QImage::Format_ARGB32);
    QPainter painter(&mainimg);

    QColor background(Qt::white);
    painter.setBrush(background);
    painter.setPen(Qt::NoPen);
    painter.drawRect(0, 0, temp_width, temp_height);
    QColor foreground(QColor("#002266")); // 二维码颜色
    painter.setBrush(foreground);
    for (qint32 y = 0; y < qrcode_width; y++)
    {
        for (qint32 x = 0; x < qrcode_width; x++)
        {
            unsigned char b = qrcode->data[y*qrcode_width + x];
            if (b & 0x01)
            {
                QRectF r(x*scale_x, y*scale_y, scale_x, scale_y);
                painter.drawRects(&r, 1);
            }
        }
    }

    ui.label->setPixmap(QPixmap::fromImage(mainimg));

    return QWidget::paintEvent(event);
}

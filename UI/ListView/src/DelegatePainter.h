#pragma once

#include <QPainter>
#include <QSvgRenderer>
#include <QStyleOptionViewItemV4>

class DelegatePainter 
{

public:
    DelegatePainter();
    ~DelegatePainter();

public:
    // paint文字
    void paintText(QPainter* painter, const QStyleOptionViewItemV4& op, const QModelIndex &index,
        int role, Qt::AlignmentFlag addFlag, const QColor& color, const QRect& paintRect, int fontSize, QString content = "");
   
    // Svg图片
    void paintSvgImage(QPainter* painter, const QString& imagePath, const QRect& paintRect);

private:
    // 返回处理过之后的文本字符串
    QString getElidedText(const int weight, const int size, const QString& fontName, const QString& content, const int maxWidth, Qt::TextElideMode elider);

private:
    QSvgRenderer* m_svgRenderer{ nullptr };
};

/** @file    DelegatePainter.h
 *  @date    2019/02/04 10:58
 *  @brief   绘制文本/图片等  提供给代理类使用
 *
 *  @author  yu
 *  @contact ylesliefish@gmail.com
 */

#pragma once

#include <QPainter>
#include <QSvgRenderer>
#include <QStyleOptionViewItemV4>

namespace publicgui
{
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

}

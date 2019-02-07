#include "DelegatePainter.h"
#include <QDebug>

namespace publicgui
{
    DelegatePainter::DelegatePainter()
    {
        m_svgRenderer = new QSvgRenderer();
    }

    DelegatePainter::~DelegatePainter()
    {
    }

    /****************************************!
     * @brief  文本处理
     * @param  [in]  const int weight 字体类型 粗体/正常等
     * @param  [in]  const int size 字体大小
     * @param  [in]  const QString & fontName 字体名称
     * @param  [in]  const QString & content 文本内容
     * @param  [in]  const int maxWidth 最大宽度
     * @param  [in]  Qt::TextElideMode elider
     * @return QT_NAMESPACE::QString
     ****************************************/
    QString DelegatePainter::getElidedText(const int weight, const int size, const QString& fontName, const QString& content, const int maxWidth, Qt::TextElideMode elider)
    {
        QString result = content;

        QFont wordfont;
        wordfont.setFamily(fontName);
        wordfont.setPixelSize(size);
        wordfont.setWeight(weight);

        QFontMetrics fontWidth(wordfont);
        int width = fontWidth.width(content);

        //当字符串宽度太大的话  右边显示省略号
        if (width >= maxWidth)
        {
            result = fontWidth.elidedText(content, elider, maxWidth);
        }

        return result;
    }

    /****************************************!
     * @brief  绘制文本
     * @param  [in]  QPainter * painter 绘制painter
     * @param  [in]  const QStyleOptionViewItemV4 & op
     * @param  [in]  const QModelIndex & index 索引
     * @param  [in]  int role 角色
     * @param  [in]  Qt::AlignmentFlag addFlag 字体对齐方式
     * @param  [in]  const QColor & color 颜色
     * @param  [in]  const QRect & paintRect paint区域
     * @param  [in]  int fontSize 字体大小
     * @param  [in]  QString content 文字内容
     * @return void
     ****************************************/
    void DelegatePainter::paintText(QPainter* painter, const QStyleOptionViewItemV4& op, const QModelIndex &index,
        int role, Qt::AlignmentFlag addFlag, const QColor& color, const QRect& paintRect, int fontSize, QString content /*= ""*/)
    {
        if (nullptr == painter)
        {
            return;
        }
        painter->save();
        if (content.isEmpty())
        {
            content = index.data(role).toString();

        }
        content = getElidedText(QFont::Normal, fontSize, "microsoft yahei", content, paintRect.width(), Qt::ElideRight);

        QFont font = painter->font();
        font.setFamily("microsoft yahei");
        font.setPixelSize(fontSize);
        painter->setFont(font);
        painter->setPen(color);
        painter->drawText(paintRect, addFlag | Qt::AlignVCenter, content);
        painter->save();
        painter->restore();
    }

    /****************************************!
     * @brief  加载Svg图片 绘图不失真
     * @param  [in]  QPainter * painter 绘图指针
     * @param  [in]  const QString & imagePath 图片路径
     * @param  [in]  const QRect & paintRect 画图区域
     * @return void
     ****************************************/
    void DelegatePainter::paintSvgImage(QPainter* painter, const QString& imagePath, const QRect& paintRect)
    {
        painter->save();

        if (!m_svgRenderer->load(imagePath))
        {
            return;
        }

        m_svgRenderer->render(painter, paintRect);
        painter->restore();
    }
}

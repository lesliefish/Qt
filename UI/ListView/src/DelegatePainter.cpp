#include "DelegatePainter.h"
#include <QDebug>

DelegatePainter::DelegatePainter()
{
    m_svgRenderer = new QSvgRenderer();
}

DelegatePainter::~DelegatePainter()
{
}

/** @fn     DelegatePainter::getElidedText
 *  @brief  文本处理
 *  @param  const int weight 字体类型 粗体/正常等
 *  @param  const int size 字体大小
 *  @param  const QString & fontName 字体名称
 *  @param  const QString & content 文本内容
 *  @param  const int maxWidth 最大宽度
 *  @param  Qt::TextElideMode elider 
 *  @return QString 
 */
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

/** @fn     DelegatePainter::paintText
 *  @brief
 *  @param  QPainter * painter 绘制painter
 *  @param  const QStyleOptionViewItemV4 & op
 *  @param  const QModelIndex & index 索引
 *  @param  int role 角色
 *  @param  Qt::AlignmentFlag addFlag 字体对齐方式
 *  @param  const QColor & color 颜色
 *  @param  const QRect & paintRect paint区域
 *  @param  int fontSize 字体大小
 *  @param  QString content 文字内容
 *  @return void
 */
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
}

/** @fn     filemanagement::DelegatePainter::paintImage
*  @brief  加载Svg图片 绘图不失真
*  @param  QPainter * painter 绘图指针
*  @param  const QString & imagePath 图片路径
*  @param  const QRect & paintRect 画图区域
*  @return void
*/
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

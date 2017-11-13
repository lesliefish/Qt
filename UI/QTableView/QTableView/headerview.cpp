#include "headerview.h"

HeaderView::HeaderView(Qt::Orientation orientation, QWidget*  parent)
    : QHeaderView(orientation, parent)
{

}

void HeaderView::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
    painter->save();
    QHeaderView::paintSection(painter, rect, logicalIndex);
    painter->restore();

    if(logicalIndex == 0)
    {
        QStyleOptionButton option;
        option.iconSize = QSize(10,10);
        option.rect = rect;

        if(isOn)
            option.state = QStyle::State_On;
        else
            option.state = QStyle::State_Off;
        this->style()->drawPrimitive(QStyle::PE_IndicatorCheckBox, &option, painter);
    }
}


void HeaderView::mousePressEvent(QMouseEvent *event)
{
  if (isOn)
    isOn = false;
  else
    isOn = true;
  this->update();
  QHeaderView::mousePressEvent(event);
}

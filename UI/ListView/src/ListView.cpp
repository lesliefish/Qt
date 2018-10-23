#include "ListView.h"

ListView::ListView(QWidget *parent)
    : QListView(parent)
{
}

ListView::~ListView()
{
}

bool ListView::viewportEvent(QEvent* pEvent)
{
    bool result = QListView::viewportEvent(pEvent);
    QEvent::Type eventType = pEvent->type();

    switch (eventType)
    {
    case QEvent::HoverEnter:
    case QEvent::HoverLeave:
    case QEvent::HoverMove:
    {
        // hover 事件
        QHoverEvent* pHoverEvent = static_cast<QHoverEvent*>(pEvent);
        QModelIndex modelIndex = indexAt(pHoverEvent->pos());
        QStyleOptionViewItemV4 option = viewOptions();
        option.rect = visualRect(modelIndex);
        option.widget = this;
        QMetaObject::invokeMethod(qobject_cast<StyledDelegate*>(itemDelegate(modelIndex)), "hoverEvent",
            Q_ARG(QHoverEvent*, pHoverEvent),
            Q_ARG(QAbstractItemView*, this),
            Q_ARG(QStyleOptionViewItem, option),
            Q_ARG(QModelIndex, modelIndex));
    }
    break;
    case QEvent::MouseButtonPress:
    case QEvent::MouseButtonRelease:
    case QEvent::MouseButtonDblClick:
    {
        int role = -1;
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(pEvent);
        QModelIndex modelIndex = indexAt(mouseEvent->pos());
        QStyleOptionViewItemV4 option = viewOptions();
        option.rect = visualRect(modelIndex);
        option.widget = this;

        QMetaObject::invokeMethod(qobject_cast<StyledDelegate*>(itemDelegate(modelIndex)), "mouseEvent",
            Q_RETURN_ARG(int, role),
            Q_ARG(QMouseEvent*, mouseEvent),
            Q_ARG(QAbstractItemView*, this),
            Q_ARG(QStyleOptionViewItem, option),
            Q_ARG(QModelIndex, modelIndex));

        if (eventType == QEvent::MouseButtonRelease &&
            Qt::LeftButton == mouseEvent->button()) 
        {
            // 左键按下
            if (role != -1)
            {
                emit signalClicked(modelIndex, role);
            }
            else
            {
                emit signalClicked(modelIndex);
            }
        }
        if (eventType == QEvent::MouseButtonDblClick &&
            Qt::LeftButton == mouseEvent->button()) 
        {
            // 左键双击
            emit signalDoubleClicked(modelIndex);
        }
    }
    break;
    default:
        break;
    }


    return result;
}

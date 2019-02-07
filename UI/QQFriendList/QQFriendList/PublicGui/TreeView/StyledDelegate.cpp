#include "StyledDelegate.h"

namespace publicgui
{
    StyledDelegate::StyledDelegate(QObject *parent)
        : QStyledItemDelegate(parent)
    {
    }

    StyledDelegate::~StyledDelegate()
    {
    }

    void StyledDelegate::paint(QPainter *painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
    {

    }

    StyledDelegate::OperateActions StyledDelegate::getOperateActions(const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        OperateActions oa{};
        oa.isSelected = (option.state& QStyle::State_Selected) == QStyle::State_Selected ? true : false;
        oa.isHovered = (option.state& QStyle::State_MouseOver) == QStyle::State_MouseOver ? true : false;
        oa.isPressed = index.data(ItemRole::MousePressRole).toBool();
        oa.mousePosX = index.data(ItemRole::PosRole).toPoint().x();
        oa.mousePosY = index.data(ItemRole::PosRole).toPoint().y();

        return oa;
    }

    int StyledDelegate::getMouseEventRole(const QPoint& pos, const QStyleOptionViewItem& option, const QModelIndex &index) const
    {
        return -1;
    }

    int StyledDelegate::getHoverEventRole(const QPoint& pos, const QStyleOptionViewItem& option, const QModelIndex &index) const
    {
        return -1;
    }

    Q_INVOKABLE int StyledDelegate::hoverEvent(QHoverEvent* hoverEvent, QAbstractItemView* view,
        const QStyleOptionViewItem& option, const QModelIndex& modelIndex)
    {
        if (nullptr == hoverEvent || nullptr == view || !modelIndex.isValid())
        {
            return -1;
        }

        auto curModel = view->model();
        if (nullptr == curModel)
        {
            return -1;
        }
        auto pos = hoverEvent->pos();

        auto eventType = hoverEvent->type();
        switch (eventType)
        {
        case QEvent::HoverEnter:
        case QEvent::HoverLeave:
            break;
        case QEvent::HoverMove:
        {
            curModel->setData(modelIndex, pos, ItemRole::PosRole); // 获取位置

            switch (eventType)
            {
            case QHoverEvent::HoverMove:
                curModel->setData(modelIndex, option.rect.contains(pos) ? true : false, ItemRole::MouseHoverRole);
                break;
            case QHoverEvent::HoverLeave:
            case QHoverEvent::Leave:
                curModel->setData(modelIndex, false, ItemRole::MousePressRole);
                curModel->setData(modelIndex, false, ItemRole::MouseHoverRole);
                break;
            case QHoverEvent::HoverEnter:
                curModel->setData(modelIndex, true, ItemRole::MouseHoverRole);
                break;
            default:
                break;
            }
            break;
        }
        default:
            break;
        }

        view->update(modelIndex);

        if (option.rect.contains(pos))
        {
            // hover 的role
            return getHoverEventRole(pos, option, modelIndex);
        }

        return -1;
    }

    Q_INVOKABLE int StyledDelegate::mouseEvent(QMouseEvent* mouseEvent, QAbstractItemView* view,
        const QStyleOptionViewItem& option, const QModelIndex& modelIndex)
    {
        if (nullptr == mouseEvent || nullptr == view || !modelIndex.isValid())
        {
            return -1;
        }

        auto curModel = view->model();
        if (nullptr == curModel)
        {
            return -1;
        }

        auto pos = mouseEvent->pos();

        curModel->setData(modelIndex, pos, ItemRole::PosRole);

        auto eventType = mouseEvent->type();
        switch (eventType)
        {
        case QMouseEvent::MouseMove:
            curModel->setData(modelIndex, true, ItemRole::MouseHoverRole);
            break;
        case QMouseEvent::MouseButtonPress:
            curModel->setData(modelIndex, true, ItemRole::MousePressRole);
            break;
        case QMouseEvent::MouseButtonRelease:
            curModel->setData(modelIndex, true, ItemRole::MousePressRole);
            break;
        default:
            break;
        }

        view->update(modelIndex);

        if (option.rect.contains(pos))
        {
            // 点到的区域
            return getMouseEventRole(pos, option, modelIndex);
        }

        return -1;
    }
}

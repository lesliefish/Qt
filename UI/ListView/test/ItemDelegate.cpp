#include "ItemDelegate.h"
#include "DelegatePainter.h"
#include "DataDefines.h"

namespace
{
    const QRect kHeadRect(16, 8, 32, 32); // 头像
    const QRect kNameRect(64, 8, 156, 18);
    const QRect kTimeRect(231, 17, 32, 12);
    const QRect kVipRect(64, 28, 12, 12);
    const QRect kMottoRect(80, 28, 140, 12);

    QString headPotrait{ ":/Test/res/boy.svg" };
    QString onlineIcon{ ":/Test/res/online.svg" };
    QString offlineIcon{ ":/Test/res/online.svg" };
}

ItemDelegate::ItemDelegate(QObject *parent)
    : StyledDelegate(parent)
{
}

ItemDelegate::~ItemDelegate()
{
}

void ItemDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    DelegatePainter delegatePainter;
    OperateActions operateActions = getOperateActions(option, index);

    QColor color;
    color = (operateActions.isSelected) ? QColor("dark") // 选中
        : (!operateActions.isSelected && operateActions.isHovered) ? QColor("lightblue") // hover
        : QColor("#ffffff");    // 默认

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(color);
    painter->drawRect(option.rect);
    painter->save();


    QRect headRect(option.rect.left() + kHeadRect.x(), option.rect.top() + kHeadRect.y(), kHeadRect.width(), kHeadRect.height());
    delegatePainter.paintSvgImage(painter, headPotrait, headRect);
    // name
    QRect nameRect(option.rect.left() + kNameRect.x(), option.rect.top() + kNameRect.y(), kNameRect.width(), kNameRect.height());
    delegatePainter.paintText(painter, option, index, PaintRoleType::NameRole, Qt::AlignLeft, QColor("red"), nameRect, 14);

    // time
    QRect timeRect(option.rect.left() + kMottoRect.x(), option.rect.top() + kMottoRect.y(), kMottoRect.width(), kMottoRect.height());
    delegatePainter.paintText(painter, option, index, PaintRoleType::DepartmentRole, Qt::AlignLeft, QColor("#556677"), timeRect, 10);

    // on or off
    QString lineIcon = index.data(IsVipRole).toInt() ? onlineIcon : offlineIcon;
    QRect callTypeIconRect(option.rect.left() + kVipRect.x(), option.rect.top() + kVipRect.y(), kVipRect.width(), kVipRect.height());
    delegatePainter.paintSvgImage(painter, lineIcon, callTypeIconRect);
}

int ItemDelegate::getMouseEventRole(const QPoint& pos, const QStyleOptionViewItem& option, const QModelIndex &index) const
{
    QRect headRect(option.rect.left() + kHeadRect.x(), option.rect.top() + kHeadRect.y(), kHeadRect.width(), kHeadRect.height());

    if (headRect.contains(pos))
    {
        return PaintRoleType::NameRole;
    }


    QRect callTypeIconRect(option.rect.left() + kVipRect.x(), option.rect.top() + kVipRect.y(), kVipRect.width(), kVipRect.height());

    if (callTypeIconRect.contains(pos))
    {
        return PaintRoleType::IsVipRole;
    }

    return -1;
}

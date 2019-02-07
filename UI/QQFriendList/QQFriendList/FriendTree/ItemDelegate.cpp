#include "ItemDelegate.h"
#include "PublicGui/TreeView/DelegatePainter.h"
#include "GlobalDefines.h"

namespace qqfriendlist
{
    namespace
    {
        const int kGroupItemHeight{ 35 };
        const int kContactItemHeight{ 60 };

        const QRect kGroupPullIconRect{ 10,12,11,11 }; // 群组下拉图标
        const QRect kGroupNameRect{ 30,0,200,35 };	   // 群组名称

        const QRect kContactPortraitRect{ 10,10,40,40 }; // 联系人头像
        const QRect kContactNameRect{ 60,10,200,20 };	 // 联系人名字
        const QRect kSignatureRect{ 60,30,160,20 };		 // 联系人个性签名
        const QRect kVipIconRect{ 60,30,30,12 };		 // 联系人VIP图标
        const QRect kOnlineStateIconRect{ 40,35,14,14 }; // 在线状态图标
        const QRect kVideoIconRect{ 0,25,20,13 };	     // 视频通话图标
    }


    ItemDelegate::ItemDelegate(QObject *parent)
        : StyledDelegate(parent)
    {
    }

    ItemDelegate::~ItemDelegate()
    {
    }

    /****************************************!
     * @brief  代理绘制
     * @param  [in]  QPainter * painter
     * @param  [in]  const QStyleOptionViewItem & option
     * @param  [in]  const QModelIndex & index
     * @return void
     ****************************************/
    void ItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
    {
        DelegatePainter delegatePainter;
        OperateActions operateActions = getOperateActions(option, index);
        QColor color;
        color = (operateActions.isHovered) ? QColor("#f0f0f0") //背景色选中
            : (!operateActions.isSelected && operateActions.isHovered) ? QColor("lightblue") // hover
            : QColor("#ffffff");
        if (index.data(static_cast<int>(CustomRole::IsGroupRole)).toBool())
        {
            paintGroup(painter, option, index);
            return;
        }
        else
        {
            paintContact(painter, option, index); // 绘制联系人
        }
    }

    /****************************************!
     * @brief  绘制群组Item
     * @param  [in]  QPainter * painter
     * @param  [in]  const QStyleOptionViewItem & option
     * @param  [in]  const QModelIndex & index
     * @return void
     ****************************************/
    void ItemDelegate::paintGroup(QPainter *painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
    {
        DelegatePainter delegatePainter;
        OperateActions operateActions = getOperateActions(option, index);
        QColor color;
        color = (operateActions.isHovered) ? QColor("#f0f0f0") : QColor("#ffffff"); // hover时变灰

        // 背景色
        painter->setPen(Qt::NoPen);
        painter->setBrush(color);
        painter->drawRect(option.rect);

        // 下拉列表图标
        QRect pullIconRect(option.rect.left() + kGroupPullIconRect.x(), option.rect.top() + kGroupPullIconRect.y(),
            kGroupPullIconRect.width(), kGroupPullIconRect.height());
        QString pullIconPath{ ":/QQFriendList/Resources/images/expand_down.svg" };
        if (!index.data(static_cast<int>(CustomRole::IsExpandedRole)).toBool())
        {
            pullIconPath = ":/QQFriendList/Resources/images/expand_right.svg";
        }
        delegatePainter.paintSvgImage(painter, pullIconPath, pullIconRect);

        // 群组名称
        QRect nameRect(option.rect.left() + kGroupNameRect.x(), option.rect.top() + kGroupNameRect.y(), kGroupNameRect.width(), kGroupNameRect.height());
        delegatePainter.paintText(painter, option, index, Qt::DisplayRole, Qt::AlignLeft, QColor("black"), nameRect, 13);
    }

    /****************************************!
     * @brief  绘制联系人信息
     * @param  [in]  QPainter * painter
     * @param  [in]  const QStyleOptionViewItem & option
     * @param  [in]  const QModelIndex & index
     * @return void
     ****************************************/
    void ItemDelegate::paintContact(QPainter *painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
    {
        DelegatePainter delegatePainter;
        OperateActions operateActions = getOperateActions(option, index);
        QColor backgroundColor;
        if (operateActions.isHovered && !operateActions.isSelected)
        {
            backgroundColor = QColor("#f2f2f2");
        }
        else if (operateActions.isSelected)
        {
            backgroundColor = QColor("#ebebeb");
        }
        else
        {
            backgroundColor = QColor("#ffffff");
        }

        // 背景色
        painter->setPen(Qt::NoPen);
        painter->setBrush(backgroundColor);
        painter->drawRect(option.rect);

        // 联系人信息
        auto info = index.data(static_cast<int>(CustomRole::ContactRole)).value<Contact>();

        // 联系人头像
        {
            QRect contactHeadPortraitRect(option.rect.left() + kContactPortraitRect.x(), option.rect.top() + kContactPortraitRect.y(),
                kContactPortraitRect.width(), kContactPortraitRect.height());
            QString contactHeadPortraitPath{ ":/QQFriendList/Resources/images/portrait_boy.svg" };
            if (!info.sex)
            {
                contactHeadPortraitPath = ":/QQFriendList/Resources/images/portrait_girl.svg";
            }
            delegatePainter.paintSvgImage(painter, contactHeadPortraitPath, contactHeadPortraitRect);
        }

        // 联系人名称
        {
            QRect nameRect(option.rect.left() + kContactNameRect.x(), option.rect.top() + kContactNameRect.y(),
                kContactNameRect.width(), kContactNameRect.height());
            QColor nameColor{ "black" };
            if (info.isVip) // 是vip
            {
                nameColor = QColor("#ff0000");
            }
            delegatePainter.paintText(painter, option, index, Qt::DisplayRole,
                Qt::AlignLeft, nameColor, nameRect, 13, info.name + "(" + info.nickName + ")");
        }

        // 个性签名
        {
            QRect signatureRect(option.rect.left() + kSignatureRect.x(), option.rect.top() + kSignatureRect.y(),
                kSignatureRect.width(), kSignatureRect.height());
            delegatePainter.paintText(painter, option, index, Qt::DisplayRole,
                Qt::AlignLeft, QColor("black"), signatureRect, 13, info.signature);
        }


        // 在线状态图标
        {
            QRect onlineStateIconRect(option.rect.left() + kOnlineStateIconRect.x(), option.rect.top() + kOnlineStateIconRect.y(),
                kOnlineStateIconRect.width(), kOnlineStateIconRect.height());
            QString onlineStateIconPath{ ":/QQFriendList/Resources/images/online-im.svg" };
            switch (info.onlineState)
            {
            case OnlineState::Busy:
            {
                onlineStateIconPath = ":/QQFriendList/Resources/images/busy-im.svg";
                break;
            }
            case OnlineState::Leave:
            {
                onlineStateIconPath = ":/QQFriendList/Resources/images/leave-im.svg";
                break;
            }
            case OnlineState::Online:
            {
                break;
            }
            default:break;
            }
            // 防背景透明 先把背景处理了 用背景色backgroundColor画一个圆形区域
            painter->setPen(Qt::NoPen);
            painter->setBrush(backgroundColor);
            painter->drawRoundedRect(onlineStateIconRect, onlineStateIconRect.width() / 2, onlineStateIconRect.height() / 2);

            delegatePainter.paintSvgImage(painter, onlineStateIconPath, onlineStateIconRect);
        }

        // 视频通话
        {
            // 只有hover状态才会显示视频通话图标
            if (operateActions.isHovered)
            {
                QRect videoRect(option.rect.left() + option.rect.width() - kVideoIconRect.width() - 16, option.rect.top() + kVideoIconRect.y(),
                    kVideoIconRect.width(), kVideoIconRect.height());
                delegatePainter.paintSvgImage(painter, ":/QQFriendList/Resources/images/video.svg", videoRect);
            }
        }
    }

    /****************************************!
     * @brief  根据Item不同调整高度
     * @param  [in]  const QStyleOptionViewItem & option
     * @param  [in]  const QModelIndex & index
     * @return QSize
     ****************************************/
    QSize ItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        QSize size = QStyledItemDelegate::sizeHint(option, index);

        if (index.data(static_cast<int>(CustomRole::IsGroupRole)).toBool())
        {
            return QSize(size.width(), kGroupItemHeight); // 群组Item高度
        }

        return QSize(size.width(), kContactItemHeight);   // 联系人Item高度
    }

    /****************************************!
     * @brief  根据鼠标位置 判断hover的role是哪个 并返回
     * @param  [in]  const QPoint & pos 鼠标位置
     * @param  [in]  const QStyleOptionViewItem & option
     * @param  [in]  const QModelIndex & index 索引位置
     * @return int
     ****************************************/
    int ItemDelegate::getHoverEventRole(const QPoint& pos, const QStyleOptionViewItem& option, const QModelIndex &index) const
    {
        // 视频通话图标位置
        QRect videoRect(option.rect.left() + option.rect.width() - kVideoIconRect.width() - 16, option.rect.top() + kVideoIconRect.y(),
            kVideoIconRect.width(), kVideoIconRect.height());
        if (!index.data(static_cast<int>(CustomRole::IsGroupRole)).toBool() && videoRect.contains(pos))
        {
            return static_cast<int>(CustomRole::VideoRole);
        }

        // 个性签名
        QRect signatureRect(option.rect.left() + kSignatureRect.x(), option.rect.top() + kSignatureRect.y(),
            kSignatureRect.width(), kSignatureRect.height());
        if (!index.data(static_cast<int>(CustomRole::IsGroupRole)).toBool() && signatureRect.contains(pos))
        {
            return static_cast<int>(CustomRole::SignatureRole);
        }

        // 头像
        QRect contactHeadPortraitRect(option.rect.left() + kContactPortraitRect.x(), option.rect.top() + kContactPortraitRect.y(),
            kContactPortraitRect.width(), kContactPortraitRect.height());
        if (!index.data(static_cast<int>(CustomRole::IsGroupRole)).toBool() && contactHeadPortraitRect.contains(pos))
        {
            return static_cast<int>(CustomRole::PortraitRole);
        }
        return -1;
    }

    /****************************************!
     * @brief  返回点击的Item的角色
     * @param  [in]  const QPoint & pos
     * @param  [in]  const QStyleOptionViewItem & option
     * @param  [in]  const QModelIndex & index
     * @return int
     ****************************************/
    int ItemDelegate::getMouseEventRole(const QPoint& pos, const QStyleOptionViewItem& option, const QModelIndex &index) const
    {
        // 视频通话图标位置
        QRect videoRect(option.rect.left() + option.rect.width() - kVideoIconRect.width() - 16, option.rect.top() + kVideoIconRect.y(),
            kVideoIconRect.width(), kVideoIconRect.height());
        if (!index.data(static_cast<int>(CustomRole::IsGroupRole)).toBool() && videoRect.contains(pos))
        {
            return static_cast<int>(CustomRole::VideoRole);
        }

        return -1;
    }

}


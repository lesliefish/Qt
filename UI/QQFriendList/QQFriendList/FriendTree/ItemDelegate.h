/** @file    ItemDelegate.h
 *  @date    2019/02/04 13:09
 *  @brief   代理
 *
 *  @author  yu
 *  @contact ylesliefish@gmail.com
 */
#pragma once

#include "PublicGui/TreeView/StyledDelegate.h"

using namespace publicgui;

namespace qqfriendlist
{
    class ItemDelegate : public StyledDelegate
    {
        Q_OBJECT

    public:
        ItemDelegate(QObject *parent = Q_NULLPTR);
        ~ItemDelegate();

        // 完成Item具体内容的绘制
        virtual void paint(QPainter *painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

        // 绘制群组
        virtual void paintGroup(QPainter *painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

        // 绘制联系人
        virtual void paintContact(QPainter *painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    protected:
        QSize sizeHint(const QStyleOptionViewItem &option,
            const QModelIndex &index) const Q_DECL_OVERRIDE;

        // hover的role
        virtual int getHoverEventRole(const QPoint& pos, const QStyleOptionViewItem& option, const QModelIndex &index) const;

        // 点击的role
        virtual int getMouseEventRole(const QPoint& pos, const QStyleOptionViewItem& option, const QModelIndex &index) const;
    };

}

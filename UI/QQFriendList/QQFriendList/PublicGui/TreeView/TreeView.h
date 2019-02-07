/** @file    TreeView.h
 *  @date    2019/02/07 13:58
 *  @brief   从QTreeView继承出自定义TreeView
 *
 *  @author  yu
 *  @contact ylesliefish@gmail.com
 */
#pragma once

#include <QStandardItemModel>
#include <QTreeView>
#include <QEvent>
#include <QHoverEvent>
#include "StyledDelegate.h"

namespace publicgui
{
    class TreeView : public QTreeView
    {
        Q_OBJECT

    public:
        TreeView(QWidget *parent = Q_NULLPTR);
        ~TreeView();

    signals:
        // 点击Item信号
        void signalClicked(const QModelIndex& iIndex);
        // 点击Item信号 具体到点到的Role
        void signalClicked(const QModelIndex& iIndex, int role);
        // 双击信号
        void signalDoubleClicked(const QModelIndex& iIndex);
        // hoverItem信号 具体到hover的Role
        void signalHover(const QModelIndex& iIndex, int role);
    protected:
        virtual bool viewportEvent(QEvent* pEvent);
    };

}

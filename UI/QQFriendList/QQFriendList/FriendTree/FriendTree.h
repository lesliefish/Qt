/** @file    FriendTree.h
 *  @date    2019/02/04 11:01
 *  @brief   好友列表树
 *
 *  @author  yu
 *  @contact ylesliefish@gmail.com
 */

#pragma once

#include <QTreeView>
#include "PublicGui/TreeView/TreeView.h"
#include "GlobalDefines.h"

using namespace publicgui;

namespace qqfriendlist
{
    class ItemDelegate;
    class FriendTree : public TreeView
    {
        Q_OBJECT

    public:
        FriendTree(QWidget *parent = Q_NULLPTR);
        ~FriendTree();

        // 赋值
        void setValues(const std::vector<Group>& groups);

    private:
        void initUi();
        void initConnection();
        // 自定义的hover处理
        void onHoverHandle(const QModelIndex& index, int role);
        // 自定义的点击事件处理
        void onClickedHandle(const QModelIndex& index, int role);
    private:
        QStandardItemModel* m_model{ nullptr }; // model
        ItemDelegate* m_delegate{ nullptr };
    };
}

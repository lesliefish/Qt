/** @file    FriendTree.h
 *  @date    2019/02/04 11:01
 *  @brief   ºÃÓÑÁÐ±íÊ÷
 *
 *  @author  yu
 *  @contact ylesliefish@gmail.com
 */
 
#pragma once

#include <QTreeView>
#include "PublicGui/TreeView/TreeView.h"

using namespace publicgui;

namespace qqfriendlist
{
	class FriendTree : public TreeView
	{
		Q_OBJECT

	public:
		FriendTree(QWidget *parent);
		~FriendTree();

	private:
		void initUi();
		void initConnection();
	};
}

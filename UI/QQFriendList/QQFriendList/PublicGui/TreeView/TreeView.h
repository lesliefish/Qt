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

	protected:
		virtual bool viewportEvent(QEvent* pEvent);

	private:
		StyledDelegate m_itemDelegate;
		QStandardItemModel m_model;
	};

}

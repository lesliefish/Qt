#include "FriendTree.h"
#include "ItemDelegate.h"
#include <QHeaderView>
#include "GlobalDefines.h"

namespace qqfriendlist
{
	FriendTree::FriendTree(QWidget *parent)
		: TreeView(parent)
	{
		initUi();
		initConnection();
	}

	FriendTree::~FriendTree()
	{
	}

	/****************************************!
	 * @brief  赋值接口
	 * @param  [in]  const std::vector<Group> & groups
	 * @return void
	 ****************************************/
	void FriendTree::setValues(const std::vector<Group>& groups)
	{
		m_model->clear();
		for (const auto& group : groups)
		{
			// 添加分组
			QStandardItem* item = new QStandardItem(group.groupName);
			item->setEditable(false);
			item->setData(true, static_cast<int>(CustomRole::IsGroupRole));
			m_model->appendRow(item);
			for (const auto& contact : group.contactList)
			{
				// 分组下的联系人
				QStandardItem* contactItem = new QStandardItem(contact.name);
				contactItem->setEditable(false);

				QVariant value{};
				value.setValue(contact);
				contactItem->setData(value, static_cast<int>(CustomRole::ContactRole));
				item->appendRow(contactItem);
			}
		}
	}

	/****************************************!
	 * @brief  初始化界面
	 * @return void  
	 ****************************************/
	void FriendTree::initUi()
	{
		setWindowTitle(tr("QQ Friend List"));
		// basic init
		header()->hide();	// 隐藏表头
		setIndentation(0);	// 左边距设置为0
		setAnimated(true);  // 展开时动画

		m_model = new QStandardItemModel(this);
		setModel(m_model);
		m_delegate = new ItemDelegate(this);
		setItemDelegate(m_delegate);
	}

	/****************************************!
	 * @brief  初始化信号槽链接
	 * @return void  
	 ****************************************/
	void FriendTree::initConnection()
	{
		connect(this, &QTreeView::clicked, [&](const QModelIndex& index)
		{
			if (index.data(static_cast<int>(CustomRole::IsGroupRole)).toBool())
			{
				setExpanded(index, !isExpanded(index));
			}
		});

		connect(this, &QTreeView::expanded, [&](const QModelIndex& index) 
		{
			m_model->itemFromIndex(index)->setData(true, static_cast<int>(CustomRole::IsExpandedRole));
		});

		connect(this, &QTreeView::collapsed, [&](const QModelIndex& index)
		{
			m_model->itemFromIndex(index)->setData(false, static_cast<int>(CustomRole::IsExpandedRole));
		});
	}

}


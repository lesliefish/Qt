#include "FriendTree.h"
#include "ItemDelegate.h"
#include <QHeaderView>
#include <QTime>
#include <QMessageBox>
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
            item->setData(group.groupName, Qt::ToolTipRole);
            item->setData(true, static_cast<int>(CustomRole::IsGroupRole));
            m_model->appendRow(item);
            for (const auto& contact : group.contactList)
            {
                // 分组下的联系人
                QStandardItem* contactItem = new QStandardItem(contact.name);
                contactItem->setEditable(false);
                contactItem->setData(contact.name, Qt::ToolTipRole);

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
        setWindowTitle(QStringLiteral("QQ好友列表"));
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
        // 点击事件
        connect(this, &QTreeView::clicked, [&](const QModelIndex& index)
        {
            if (index.data(static_cast<int>(CustomRole::IsGroupRole)).toBool())
            {
                setExpanded(index, !isExpanded(index)); // 单击展开/收缩列表
            }
        });

        // 双击打开聊天
        connect(this, &QTreeView::doubleClicked, [&](const QModelIndex& index)
        {
            if (!index.data(static_cast<int>(CustomRole::IsGroupRole)).toBool())
            {
                // 不是分组Item才去处理双击事件
                auto info = index.data(static_cast<int>(CustomRole::ContactRole)).value<Contact>();
                QMessageBox msgBox;
                msgBox.setWindowTitle(QStringLiteral("双击打开聊天"));
                msgBox.setText(QStringLiteral("你好，") + info.name + QStringLiteral("。在不？"));
                msgBox.exec();
            }
        });

        // 展开时更换左侧的展开图标
        connect(this, &QTreeView::expanded, [&](const QModelIndex& index)
        {
            m_model->itemFromIndex(index)->setData(true, static_cast<int>(CustomRole::IsExpandedRole));
        });

        // 收起时更换左侧的展开图标
        connect(this, &QTreeView::collapsed, [&](const QModelIndex& index)
        {
            m_model->itemFromIndex(index)->setData(false, static_cast<int>(CustomRole::IsExpandedRole));
        });

        // 自定义hover事件
        connect(this, &TreeView::signalHover, this, &FriendTree::onHoverHandle);

        // 自定义点击事件
        connect(this, QOverload<const QModelIndex&, int>::of(&TreeView::signalClicked), this, &FriendTree::onClickedHandle);
    }

    /****************************************!
     * @brief  hover事件处理
     * @param  [in]  const QModelIndex & index 索引项
     * @param  [in]  int role 角色
     * @return void
     ****************************************/
    void FriendTree::onHoverHandle(const QModelIndex& index, int role)
    {
        if (index.data(static_cast<int>(CustomRole::IsGroupRole)).toBool())
        {
            return; // 群组的hover事件 退出
        }
        else
        {
            // 不同区域显示不同tooltip
            auto info = index.data(static_cast<int>(CustomRole::ContactRole)).value<Contact>();
            QString displayName{};
            switch (role)
            {
            case static_cast<int>(CustomRole::PortraitRole) : // 视频通话
            {
                displayName = QStringLiteral("鼠标移到头像上啦！");
                break;
            }
            case static_cast<int>(CustomRole::VideoRole) : // 视频通话
            {
                displayName = QStringLiteral("视频通话");
                break;
            }
            case static_cast<int>(CustomRole::SignatureRole) : // 个性签名
            {
                displayName = info.signature;
                break;
            }
            default:
            {
                // 默认tooltip显示用户名称+QQ号
                displayName = info.name + "(" + info.nickName + ")" + "(" + info.id + ")";
                break;
            }
            }

            m_model->itemFromIndex(index)->setData(displayName, Qt::ToolTipRole);
        }
    }

    /****************************************!
     * @brief  点击事件角色处理
     * @param  [in]  const QModelIndex & index
     * @param  [in]  int role
     * @return void
     ****************************************/
    void FriendTree::onClickedHandle(const QModelIndex& index, int role)
    {
        // 不同区域显示不同tooltip
        auto info = index.data(static_cast<int>(CustomRole::ContactRole)).value<Contact>();
        switch (role)
        {
        case static_cast<int>(CustomRole::VideoRole) : // 视频通话
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle(QStringLiteral("视频通话"));
            msgBox.setText(QTime::currentTime().toString("hh:mm:ss")
                + QStringLiteral("，向") + info.name + QStringLiteral("发起视频通话。"));
            msgBox.exec();
            break;
        }
        default:
        {
            break;
        }
        }
    }
}


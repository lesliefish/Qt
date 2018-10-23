#include "TestView.h"
#include <QScrollBar>

TestView::TestView(QWidget *parent)
    : ListView(parent)
{
    initUi();
}

TestView::~TestView()
{
}

void TestView::initUi()
{
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    // …Ë÷√—˘ Ω
    setStyleSheet(
        "QListView{background: rgb(255, 255, 255);border:none;font: 14px;}"
        "QListView::item{width : 280px; height: 48px;}"
    );

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedWidth(280);

    m_model.insertColumns(0, 1);
    setModel(&m_model);
    setItemDelegate(&m_itemDelegate);


    QList<UserInfo> list{};
    for (int i = 0; i < 10; i++)
    {
        UserInfo info{};
        info.isVip = i % 2;
        info.name = tr("121312");
        info.depart = tr("software department");
        list.append(info);
    }

    addItem(list);
}

void TestView::addItem(const QList<UserInfo>& infoList)
{
    for (const auto& iter : infoList)
    {
        QStandardItem* newItem = new QStandardItem();
        newItem->setEditable(false);
        newItem->setData(iter.name, PaintRoleType::NameRole);
        newItem->setData(iter.isVip, PaintRoleType::IsVipRole);
        newItem->setData(iter.depart, PaintRoleType::DepartmentRole);

        m_model.setItem(m_model.rowCount(), 0, newItem);
    }
}
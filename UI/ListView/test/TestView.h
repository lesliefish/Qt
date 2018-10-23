#pragma once
#include "ItemDelegate.h"
#include "DataDefines.h"
#include "ListView.h"

class TestView : public ListView
{
    Q_OBJECT

public:
    TestView(QWidget *parent = Q_NULLPTR);
    ~TestView();

private:
    void initUi();
    void addItem(const QList<UserInfo>& infoList);

private:
    ItemDelegate m_itemDelegate;
    QStandardItemModel m_model;
};

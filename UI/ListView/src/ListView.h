#pragma once

#include <QStandardItemModel>
#include <QListView>
#include <QEvent>
#include <QHoverEvent>
#include "StyledDelegate.h"

class ListView : public QListView
{
    Q_OBJECT

public:
    ListView(QWidget *parent = Q_NULLPTR);
    ~ListView();

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

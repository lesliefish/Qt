#pragma once

#include "StyledDelegate.h"

class ItemDelegate : public StyledDelegate
{
    Q_OBJECT

public:
    ItemDelegate(QObject *parent = Q_NULLPTR);
    ~ItemDelegate();

public:
    virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

protected:
    virtual int getMouseEventRole(const QPoint& pos, const QStyleOptionViewItem& option, const QModelIndex &index) const;

};

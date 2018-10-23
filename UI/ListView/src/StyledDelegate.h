#pragma once

#include <QStyledItemDelegate>
#include <QHoverEvent>
#include <QAbstractItemView>

class StyledDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit StyledDelegate(QObject *parent = Q_NULLPTR);
    virtual ~StyledDelegate();

public:
    enum ItemRole
    {
        PosRole = Qt::UserRole + 10000, // 位置
        MousePressRole,                 // 点击
        MouseHoverRole,                 // hover
    };

    // 操作行为
    struct OperateActions
    {
        bool isHovered{ false };
        bool isPressed{ false };
        bool isSelected{ false };
        int mousePosX{ 0 };
        int mousePosY{ 0 };
    };

    // 完成Item具体内容的绘制
    virtual void paint(QPainter *painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    // 获取当前Item的行为状态信息
    virtual OperateActions getOperateActions(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    // 返回被点击的角色 具体点了Item上的哪一个控件
    virtual int getMouseEventRole(const QPoint& pos, const QStyleOptionViewItem& option, const QModelIndex &index) const;

public slots:
    // view上层调用这两个函数
    Q_INVOKABLE virtual void hoverEvent(QHoverEvent* hoverEvent, QAbstractItemView* view, const QStyleOptionViewItem& option, const QModelIndex& modelIndex);
    Q_INVOKABLE virtual int mouseEvent(QMouseEvent* mouseEvent, QAbstractItemView* view, const QStyleOptionViewItem& option, const QModelIndex& modelIndex);

};

#include "Square.h"
#include <windows.h>

Square::Square(QObject *parent)
    : QObject(parent), QGraphicsItem()
{
    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &Square::slotTimer);
    m_timer->start(1000 / 33);
}

Square::~Square()
{
}

void Square::setCallbackFunc(void(*func) (QPointF point))
{
    m_callbackFunc = func;
}

QRectF Square::boundingRect() const
{
    return QRectF(-15, -15, 30, 30);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawRect(-15, -15, 30, 30);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Square::slotTimer()
{
    // 根据按钮触发情况移动正方形
    if (GetAsyncKeyState('A')) 
    {
        this->setX(this->x() - 2);
    }
    if (GetAsyncKeyState('D')) 
    {
        this->setX(this->x() + 2);
    }
    if (GetAsyncKeyState('W')) 
    {
        this->setY(this->y() - 2);
    }
    if (GetAsyncKeyState('S')) 
    {
        this->setY(this->y() + 2);
    }
    // 调用回调函数传递正方形位置  类似于发信号给mainwindow  由mainwindow执行相应槽函数
    m_callbackFunc(this->pos());
}

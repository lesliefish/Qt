#pragma once

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPointF>

class Square : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit Square(QObject *parent = 0);
    ~Square();

    // 设置回调函数的函数
    void setCallbackFunc(void(*func) (QPointF point));

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QTimer * m_timer;

    void(*m_callbackFunc)(QPointF point);

private slots:
    void slotTimer();
};

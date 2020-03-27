#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>

Bullet::Bullet()
{
    setRect(0, 0, 10, 50);

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [&] {move(); });

    timer->start(50);
}

Bullet::~Bullet()
{
}

void Bullet::move()
{
    setPos(x(), y() - 10);

    if (pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

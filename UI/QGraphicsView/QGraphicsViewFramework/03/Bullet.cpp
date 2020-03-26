#include "Bullet.h"
#include <QTimer>

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
}

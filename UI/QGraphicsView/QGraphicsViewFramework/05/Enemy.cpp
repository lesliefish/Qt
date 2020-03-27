#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>

Enemy::Enemy()
{
    int randomNumber = rand() % 700;
    setPos(randomNumber, 0);

    setRect(0, 0, 100, 100);

    QTimer* timer = new QTimer(this);

    connect(timer, &QTimer::timeout, [&] {move(); });

    timer->start(50);
}

Enemy::~Enemy()
{
}

void Enemy::move()
{
    setPos(x(), y() + 5);
    if (pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

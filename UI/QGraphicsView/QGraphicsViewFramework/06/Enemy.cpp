#include "Enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include "Game.h"

extern Game * gGame;

Enemy::Enemy(QGraphicsItem *parent /*= Q_NULLPTR*/)
    : QGraphicsRectItem(parent)
{
    setPos(rand() % 700, 0);

    setRect(0, 0, 100, 100);

    QTimer* timer = new QTimer(this);

    connect(timer, &QTimer::timeout, [&] {move(); });
    timer->start(50);
}

void Enemy::move()
{
    setPos(x(), y() + 5);
    if (pos().y() > 600)
    {
        gGame->getHealth().decrease();

        scene()->removeItem(this);
        delete this;
    }
}
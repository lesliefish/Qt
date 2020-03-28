#include "Enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include "Game.h"

extern Game * gGame;

Enemy::Enemy(QGraphicsItem *parent /*= Q_NULLPTR*/)
    : QGraphicsPixmapItem(parent)
{
    setPos(rand() % 700, 0);

    setPixmap(QPixmap(":/pic/tiger.png"));

    QTimer* timer = new QTimer(this);

    connect(timer, &QTimer::timeout, [&] {move(); });
    timer->start(10);
}

void Enemy::move()
{
    setPos(x(), y() + 1);
    if (pos().y() > 600)
    {
        gGame->getHealth().decrease();

        scene()->removeItem(this);
        delete this;
    }
}
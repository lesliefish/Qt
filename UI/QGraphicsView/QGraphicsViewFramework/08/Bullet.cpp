#include "Bullet.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include "Enemy.h"
#include "Game.h"

extern Game * gGame; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent /*= Q_NULLPTR*/)
    :QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/pic/bullet.png"));

    QTimer * timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [&] {move(); });
    timer->start(10);
}


void Bullet::move()
{
    auto items = collidingItems();
    for (int i = 0; i < items.size(); ++i)
    {
        if (typeid(*items[i]) == typeid(Enemy))
        {
            gGame->getScore().increase();

            scene()->removeItem(items[i]);
            scene()->removeItem(this);

            delete items[i];
            delete this;

            return;
        }
    }

    setPos(x(), y() - 2);

    if (pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"

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
    QList<QGraphicsItem*> collidingitems = collidingItems(); // ÓÐÅö×²µÄÏî

    for (int i = 0; i < collidingitems.size(); ++i)
    {
        if (typeid(*(collidingitems[i])) == typeid(Enemy))
        {
            scene()->removeItem(collidingitems[i]);
            scene()->removeItem(this);

            delete collidingitems[i];
            delete this;
            return;
        }
    }

    setPos(x(), y() - 10);

    if (pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

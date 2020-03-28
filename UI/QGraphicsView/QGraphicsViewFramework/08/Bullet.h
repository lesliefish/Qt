#pragma once

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Bullet(QGraphicsItem *parent = Q_NULLPTR);

public slots:
    void move();
};

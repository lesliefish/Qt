#pragma once

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsItem>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Enemy(QGraphicsItem *parent = Q_NULLPTR);

public:
    void move();
};

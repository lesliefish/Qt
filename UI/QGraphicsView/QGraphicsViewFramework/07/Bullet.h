#pragma once

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsItem>

class Bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Bullet(QGraphicsItem *parent = Q_NULLPTR);

public slots:
    void move();
};

#pragma once

#include <QObject>
#include <QGraphicsItem>

class Bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Bullet();
    ~Bullet();

public slots:
    void move();
};

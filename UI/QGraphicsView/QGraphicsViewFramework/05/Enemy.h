#pragma once

#include <QObject>
#include <QGraphicsRectItem>

class Enemy : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Enemy();
    ~Enemy();

    public slots:
    void move();
};

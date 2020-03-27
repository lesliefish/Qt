#pragma once

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsItem>

class Player : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Player(QGraphicsItem *parent = Q_NULLPTR);
    ~Player();

    void keyPressEvent(QKeyEvent *event);

public slots:
    void spawn();
};

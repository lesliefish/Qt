#pragma once

#include <QObject>
#include <QGraphicsTextItem>
#include <QGraphicsItem>

class Health : public QGraphicsTextItem
{

public:
    Health(QGraphicsItem *parent = Q_NULLPTR);

    void decrease();

    int getHealth();

private:
    int m_health;
};

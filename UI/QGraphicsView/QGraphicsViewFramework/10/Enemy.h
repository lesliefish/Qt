#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);
public slots:
    void moveForward();
private:
    QList<QPointF> points;
    QPointF m_dest;
    int m_pointIndex;
};

#endif // ENEMY_H

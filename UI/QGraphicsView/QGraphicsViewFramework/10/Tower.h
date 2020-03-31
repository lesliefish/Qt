#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QObject>
#include <QPointF>

class Tower : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

public:
	Tower(QGraphicsItem *parent = Q_NULLPTR);
	double distanceTo(QGraphicsItem * item);
	void fire();

	public slots:
	void aquire_target();
private:
	QGraphicsPolygonItem * attack_area;
	QPointF attack_dest;
	bool has_target;
};

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

public slots:
	void attack_target();

private:
	QGraphicsPolygonItem* m_attackArea{};

	QPointF attack_dest;
};

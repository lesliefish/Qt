#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QObject>

class Tower : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

public:
	Tower(QGraphicsItem *parent = Q_NULLPTR);

private:
	QGraphicsPolygonItem* m_attackArea{};
};

#include "Tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QTimer>
#include <QPolygonF>
#include "Bullet.h"
#include "Game.h"

extern Game * game;

Tower::Tower(QGraphicsItem *parent)
	: QObject(), QGraphicsPixmapItem(parent)
{
	setPixmap(QPixmap(":/images/tower.png"));

	// create points vector
	QVector<QPointF> points;
	points << QPoint(1, 0) << QPoint(2, 0) << QPoint(3, 1) << QPoint(3, 2) << QPoint(2, 3)
		<< QPoint(1, 3) << QPoint(0, 2) << QPoint(0, 1);

	// scale points
	int SCALE_FACTOR = 75;
	for (size_t i = 0, n = points.size(); i < n; i++) 
	{
		points[i] *= SCALE_FACTOR;
	}

	m_attackArea = new QGraphicsPolygonItem(QPolygonF(points), this);


	// move the polygon
	QPointF poly_center(1.5, 1.5);
	poly_center *= SCALE_FACTOR;
	poly_center = mapToScene(poly_center);;
	QPointF tower_center(x() + 32, y() + 32);
	QLineF ln(poly_center, tower_center);
	m_attackArea->setPos(x() + ln.dx(), y() + ln.dy());

	// connect a timer to attack_target
	QTimer * timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(attack_target()));
	timer->start(1000);

	// set attack_dest
	attack_dest = QPointF(800, 0);
}

void Tower::attack_target()
{
	Bullet * bullet = new Bullet();
	bullet->setPos(x() + 32, y() + 32);

	QLineF ln(QPointF(x() + 32, y() + 32), attack_dest);
	int angle = -1 * ln.angle();

	bullet->setRotation(angle);
	game->getScene()->addItem(bullet);
}

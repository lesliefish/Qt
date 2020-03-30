#include "Game.h"
#include "Tower.h"
#include "Enemy.h"
#include "Bullet.h"
#include <QMouseEvent>

Game::Game(QWidget *parent)
	: QGraphicsView(parent)
{
	m_scene = new QGraphicsScene(this);
	m_scene->setSceneRect(0, 0, 800,600);
	setScene(m_scene);

	Tower * tower = new Tower();
	m_scene->addItem(tower);

	setFixedSize(800, 600);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	// create enemy
	Enemy * enemy = new Enemy();
	m_scene->addItem(enemy);
}

void Game::mousePressEvent(QMouseEvent *event)
{
	Bullet* bullet = new Bullet();
	bullet->setPos(event->pos());
	bullet->setRotation(40);

	scene()->addItem(bullet);
}

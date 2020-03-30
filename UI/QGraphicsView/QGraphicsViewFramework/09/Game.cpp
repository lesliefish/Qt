#include "Game.h"
#include "Tower.h"

Game::Game(QWidget *parent)
	: QGraphicsView(parent)
{
	m_scene = new QGraphicsScene(this);

	setScene(m_scene);

	Tower * tower = new Tower();
	m_scene->addItem(tower);

	setFixedSize(800, 600);
}

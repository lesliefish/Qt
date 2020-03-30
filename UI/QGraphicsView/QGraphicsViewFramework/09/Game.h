#pragma once

#include <QGraphicsView>

class Game : public QGraphicsView
{
	Q_OBJECT

public:
	Game(QWidget *parent = Q_NULLPTR);

private:
	// member attributes
	QGraphicsScene * m_scene;
};

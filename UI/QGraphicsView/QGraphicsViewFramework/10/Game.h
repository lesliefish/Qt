#pragma once

#include <QGraphicsView>

class Game : public QGraphicsView
{
	Q_OBJECT

public:
	Game(QWidget *parent = Q_NULLPTR);

	void mousePressEvent(QMouseEvent *event);

	QGraphicsScene* getScene() { return m_scene; }
private:
	// member attributes
	QGraphicsScene * m_scene;
};

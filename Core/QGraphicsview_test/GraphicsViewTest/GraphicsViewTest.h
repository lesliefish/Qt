
#ifndef GRAPHICSVIEWTEST_H
#define GRAPHICSVIEWTEST_H

#include <QtWidgets/QDialog>
#include <QGraphicsScene>
#include "ui_GraphicsViewTest.h"
#include "MainScene.h"
#include <QWheelEvent>

class GraphicsViewTest : public QDialog
{
	Q_OBJECT

public:
	explicit GraphicsViewTest(QDialog *parent = 0);
	~GraphicsViewTest();

private:
	Ui::GraphicsViewTestClass ui;

	MainScene* m_scene;
};

#endif // GRAPHICSVIEWTEST_H
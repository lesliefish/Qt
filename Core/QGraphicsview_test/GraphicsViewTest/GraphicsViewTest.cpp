#include "GraphicsViewTest.h"
#include <QDebug>
float XXX = 1;
GraphicsViewTest::GraphicsViewTest(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	m_scene = new MainScene(this);
	ui.bottomGraphicsView->setScene(m_scene);
	this->resize(1366, 768);
	ui.bottomGraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.bottomGraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.bottomGraphicsView->setCursor(Qt::PointingHandCursor);
	ui.bottomGraphicsView->setRenderHint(QPainter::Antialiasing);
}

GraphicsViewTest::~GraphicsViewTest()
{

}
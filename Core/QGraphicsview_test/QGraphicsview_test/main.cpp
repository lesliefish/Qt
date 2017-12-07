#include "QGraphicsviewTest.h"
#include <QtWidgets/QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPen>
#include <QLineF>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QGraphicsScene* scene = new QGraphicsScene();
	scene->addText("hello world");
	QLineF* line = new QLineF();
	QPen*   pen = new QPen();
	QGraphicsView* view = new QGraphicsView(scene);
	view->show();

	//QGraphicsviewTest w;
	//w.show();
	return a.exec();
}

#include "GraphicsViewTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GraphicsViewTest w;
	w.show();
	return a.exec();
}

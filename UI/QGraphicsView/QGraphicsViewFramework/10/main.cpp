#include <QtWidgets/QApplication>
#include "Game.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	Game g;
	g.show();
	
	return a.exec();
}

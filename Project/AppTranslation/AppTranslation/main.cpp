#include <QtWidgets/QApplication>
#include "MainWindow.h"

#include "Widget1.h"
#include "Widget2.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);



	Widget1 w1;
	Widget2 w2;

	w1.show();
	w2.show();

	MainWindow w;
	w.show();


	return a.exec();
}

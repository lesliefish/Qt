#include "MainWindow.h"
#include "MainApplication.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    MainApplication a(argc, argv, "MainApplication1.0");

    MainWindow w;
    w.show();

    return a.exec();
}

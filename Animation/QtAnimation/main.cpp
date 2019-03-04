#include "ui/MainWindow/MainWindow.h"
#include <QtWidgets/QApplication>
using namespace animation;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

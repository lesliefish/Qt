#include "StaticCallBackTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StaticCallBackTest w;
    w.start();

    return a.exec();
}

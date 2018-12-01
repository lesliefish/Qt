#include "WebTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WebTest w;
    w.show();
    return a.exec();
}

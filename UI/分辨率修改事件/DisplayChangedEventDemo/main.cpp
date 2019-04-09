#include "DisplayChangedEventDemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DisplayChangedEventDemo w;
    w.show();
    return a.exec();
}

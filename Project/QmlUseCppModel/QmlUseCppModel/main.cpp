#include "QmlUseCppModel.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QmlUseCppModel w;
    w.show();
    return a.exec();
}

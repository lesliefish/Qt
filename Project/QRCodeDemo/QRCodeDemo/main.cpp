#include "QRCodeDemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRCodeDemo w;
    w.setCodeString("https://blog.csdn.net/y396397735");
    w.show();
    return a.exec();
}

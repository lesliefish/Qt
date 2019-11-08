#include "MyWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWindow w;
    //w.setType(LeftTop);
    //w.setType(RightTop);
    //w.setType(LeftBottom);
    //w.setType(RightBottom);
    //w.setType(Top);
    //w.setType(Bottom);
    //w.setType(Left);
    //w.setType(Right);
    //w.setType(All);

    w.show();
    return a.exec();
}

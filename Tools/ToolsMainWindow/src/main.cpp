#include "MainWindow/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("未来之歌");
    MainWindow w;
    w.show();
    return a.exec();
}

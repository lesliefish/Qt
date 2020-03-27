#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "MyRect.h"
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    MyRect* player = new MyRect();
    player->setRect(0, 0, 100, 100);

    scene.addItem(player);

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    QGraphicsView view;
    view.setScene(&scene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view.show();
    view.setFixedSize(800, 600);
    scene.setSceneRect(0, 0, 800, 600);

    // ¾ÓÖÐµ×²¿ÏÔÊ¾
    player->setPos((view.width() - player->rect().width()) / 2, view.height() - player->rect().height());


    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&] { player->spawn(); });
    timer.start(2000);

    return a.exec();
}

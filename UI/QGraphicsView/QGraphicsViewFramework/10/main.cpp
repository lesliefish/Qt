#include <QApplication>
#include "Game.h"

/*
Tutorial topics:
QGraphicsItem::collidingItems()
dynamic_cast<>()
*/

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}

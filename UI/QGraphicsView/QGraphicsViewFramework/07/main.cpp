#include <QtWidgets/QApplication>
#include "Game.h"

Game* gGame;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    gGame = new Game;
    gGame->show();

    return a.exec();
}

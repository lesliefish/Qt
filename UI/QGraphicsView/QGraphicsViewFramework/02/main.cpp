#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "MyRect.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    MyRect* rect = new MyRect();
    rect->setRect(0, 0, 100, 100);

    scene.addItem(rect);

    // make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    QGraphicsView view;
    view.setScene(&scene);

    view.show();

    return a.exec();
}

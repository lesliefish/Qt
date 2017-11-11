#include "MainWindow.h"
#include "ui_MainWindow.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QGraphicsScene scene;
    QGraphicsRectItem *rect = scene.addRect(QRectF(0, 0, 100, 100));

    scene.
//    QGraphicsItem *item = scene.itemAt(50, 50);
    // item == rect
}

Widget::~Widget()
{
    delete ui;
}

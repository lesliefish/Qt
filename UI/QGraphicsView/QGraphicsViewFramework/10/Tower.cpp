#include "Tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include "Bullet.h"
#include <QPointF>
#include <QLineF>
#include "Game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include "Enemy.h"

extern Game * game;

Tower::Tower(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){
    // set the graphics
    setPixmap(QPixmap(":/images/tower.png"));

    // create points vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
               << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    // scale points
    int SCALE_FACTOR = 75;
    for (size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE_FACTOR;
    }

    // create the QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);

    // move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);;
    QPointF tower_center(x()+27,y()+27);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    // connect a timer to attack_target
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);

    // set attack_dest
    attack_dest = QPointF(800,0);
}

double Tower::distanceTo(QGraphicsItem *item){
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void Tower::fire(){
    Bullet * bullet = new Bullet();
    bullet->setPos(x()+25,y()+25);

    QLineF ln(QPointF(x()+25,y()+25),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void Tower::aquire_target(){
    // get a list of all items colliding with attack_area
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();

    if (colliding_items.size() == 1){
        has_target = false;
        return;
    }

    double closest_dist = 300;
    QPointF closest_pt = QPointF(0,0);
    for (size_t i = 0, n = colliding_items.size(); i < n; i++){
        Enemy * enemy = dynamic_cast<Enemy *>(colliding_items[i]);
        if (enemy){
            double this_dist = distanceTo(enemy);
            if (this_dist < closest_dist){
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
    }

    attack_dest = closest_pt;
    fire();

}

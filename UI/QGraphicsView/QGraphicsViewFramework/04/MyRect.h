#pragma once

#include <QGraphicsRectItem>

class MyRect : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    void keyPressEvent(QKeyEvent *event);

};

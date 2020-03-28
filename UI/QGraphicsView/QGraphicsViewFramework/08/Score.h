#pragma once

#include <QGraphicsTextItem>
#include <QGraphicsItem>

class Score : public QGraphicsTextItem
{

public:
    Score(QGraphicsItem *parent = Q_NULLPTR);

    void increase();

    int getScore();

private:
    int m_score;
};

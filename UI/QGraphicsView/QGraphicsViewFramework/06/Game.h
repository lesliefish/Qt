#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game : public QGraphicsView
{
    Q_OBJECT

public:
    Game(QWidget *parent = Q_NULLPTR);

public:
    Score& getScore() { return m_score; };
    Player& getPlayer() { return m_player; };
    Health& getHealth() { return m_health; };

private:
    QGraphicsScene m_scene;
    Player m_player;
    Score m_score;
    Health m_health;
};

#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{
    m_player.setMedia(QUrl("file:///C:\\Users\\Public\\Music\\Sample Music\\Sleep Away.mp3"));
    setPixmap(QPixmap(":/pic/player.png"));
}

Player::~Player()
{
}

void Player::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Left:
    {
        if (pos().x() > 0)
        {
            setPos(x() - 10, y());
        }
    }
    break;
    case Qt::Key_Right:
    {
        if (pos().x() + 100 < 800)
        {
            setPos(x() + 10, y());
        }
    }
    break;
    case Qt::Key_Space:
    {
        Bullet* bullet = new Bullet;
        bullet->setPos(x(), y());
        scene()->addItem(bullet);

        // play bulletsound
        if (m_player.state() == QMediaPlayer::PlayingState)
        {
            m_player.setPosition(0);
        }
        else if (m_player.state() == QMediaPlayer::StoppedState)
        {
            m_player.play();
        }
    }
    default:
        break;
    }
}

void Player::spawn()
{
    Enemy * enemy = new Enemy;
    scene()->addItem(enemy);
}

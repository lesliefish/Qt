#include "Game.h"
#include <QTimer>
#include <QMediaPlayer>

Game::Game(QWidget *parent)
    : QGraphicsView(parent)
{
    m_scene.setSceneRect(0, 0, 800, 600);

    setScene(&m_scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(800, 600);

    m_player.setRect(0, 0, 100, 100);
    m_player.setPos(350, 500);

    m_player.setFlag(QGraphicsItem::ItemIsFocusable);
    m_player.setFocus();
    m_scene.addItem(&m_player);

    m_scene.addItem(&m_score);

    m_health.setPos(m_health.x(), m_health.y() + 25);
    m_scene.addItem(&m_health);

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [&] { m_player.spawn(); });
    timer->start(2000);

    QMediaPlayer * mediaPlayer = new QMediaPlayer;
    mediaPlayer->setMedia(QUrl("file:///C:\\Users\\Public\\Music\\Sample Music\\Sleep Away.mp3"));
    mediaPlayer->play();
}
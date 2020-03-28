#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent /*= Q_NULLPTR*/)
    : QGraphicsTextItem(parent)
{
    m_health = 3;

    setPlainText(tr("Health: ") + QString::number(m_health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decrease()
{
    m_health--;
    setPlainText(tr("Health: ") + QString::number(m_health));
}

int Health::getHealth()
{
    return m_health;
}

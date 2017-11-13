#ifndef HEADERVIEW_H
#define HEADERVIEW_H

#include <QObject>
#include <QHeaderView>
#include <QPainter>

class HeaderView : public QHeaderView
{
public:
    HeaderView(Qt::Orientation orientation, QWidget* parent = 0);

protected:
    void paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const;

    void mousePressEvent(QMouseEvent* event);

private:
    bool isOn;
};

#endif // HEADERVIEW_H

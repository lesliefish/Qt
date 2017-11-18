#ifndef FRAMELESSWIDGET_H
#define FRAMELESSWIDGET_H

#include <QWidget>

namespace Ui {
class FramelessWidget;
}

class FramelessWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FramelessWidget(QWidget *parent = 0);
    ~FramelessWidget();

private:
    Ui::FramelessWidget *ui;

    void InitUI();
protected:
    QPoint m_pointMove;
    bool m_bMouseIsPressed;
    //实现鼠标对无边框窗口拖动
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // FRAMELESSWIDGET_H

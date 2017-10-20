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
    //实现鼠标对无边框窗口拖动
    QPoint m_pointMove;
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
};

#endif // FRAMELESSWIDGET_H

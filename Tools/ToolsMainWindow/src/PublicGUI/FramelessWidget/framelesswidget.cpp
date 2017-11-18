#include "framelesswidget.h"
#include "ui_framelesswidget.h"
#include <QMouseEvent>

FramelessWidget::FramelessWidget(QWidget *parent) :
    QWidget(parent)
  , ui(new Ui::FramelessWidget)
  , m_bMouseIsPressed(false)
{
    ui->setupUi(this);
    InitUI();
}

FramelessWidget::~FramelessWidget()
{
    delete ui;
}

void FramelessWidget::InitUI()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
}


//以下为无边框窗口可拖动功能
void FramelessWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        this->setMouseTracking(true);
        m_bMouseIsPressed = true;
        m_pointMove = event->pos();
    }
}

void FramelessWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_bMouseIsPressed = false;
}

void FramelessWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bMouseIsPressed)
    {
        QPoint pointPos = event->globalPos();
        this->move(pointPos - m_pointMove);
    }
}

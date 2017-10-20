#include "framelesswidget.h"
#include "ui_framelesswidget.h"
#include <QMouseEvent>

FramelessWidget::FramelessWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FramelessWidget)
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

void FramelessWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        m_pointMove = e->globalPos() - pos();
        e->accept();
    }
}

void FramelessWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(this->isMaximized())
        return;
    if (e->buttons() & Qt::LeftButton)
    {
        move(e->globalPos() - m_pointMove);
        e->accept();
    }
}

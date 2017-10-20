#include "warningdlg.h"
#include "ui_warningdlg.h"

WarningDlg::WarningDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarningDlg)
{
    ui->setupUi(this);
    this->setWindowTitle(ui->m_titleTextBtn->text().trimmed());
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(ui->m_closeBtn, &QPushButton::clicked,[=](){this->close();});
    connect(ui->m_cancleBtn,&QPushButton::clicked,[=](){this->close();});
    connect(ui->m_OKBtn, &QPushButton::clicked, this, &WarningDlg::Exit);
}

WarningDlg::~WarningDlg()
{
    delete ui;
}

void WarningDlg::Exit()
{
    this->close();
    emit SigExit();
}
void WarningDlg::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        m_pointMove = e->globalPos() - pos();
        e->accept();
    }
}

void WarningDlg::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton)
    {
        move(e->globalPos() - m_pointMove);
        e->accept();
    }
}

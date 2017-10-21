#include "aboutdlg.h"
#include "ui_aboutdlg.h"
#include <QMouseEvent>
#include <QDesktopServices>

AboutDlg::AboutDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDlg)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowTitle(ui->m_aboutTitleBtn->text());
    connect(ui->m_aboutCloseBtn, &QPushButton::clicked, this, &AboutDlg::close);
    connect(ui->m_openBtn, &QPushButton::clicked,
            [=]()
    {
        QString filePath = QApplication::applicationDirPath();
        QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    });

}

AboutDlg::~AboutDlg()
{
    delete ui;
}

void AboutDlg::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        m_pointMove = e->globalPos() - pos();
        e->accept();
    }
}

void AboutDlg::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton)
    {
        move(e->globalPos() - m_pointMove);
        e->accept();
    }
}

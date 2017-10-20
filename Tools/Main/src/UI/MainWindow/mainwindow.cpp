#include <QFile>
#include <QDir>
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    FramelessWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitUI();
    InitConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitUI()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowTitle(tr("title"));
    ui->m_appNameBtn->setText(tr("title"));

    QString stylePath = QDir::currentPath() + "/main.qss";
    QFile fileQss(stylePath);
    if(!fileQss.open(QFile::ReadOnly))
        return;
    this->setStyleSheet(fileQss.readAll());
}

void MainWindow::InitConnect()
{
    connect(ui->m_helpBtn, &QPushButton::clicked, [=](){this->close();});
    connect(ui->m_minBtn, &QPushButton::clicked, [=](){this->showMinimized();});
    connect(ui->m_maxBtn, &QPushButton::clicked, [=](){this->isMaximized() ? this->showNormal() : this->showMaximized();});
    connect(ui->m_closeBtn, &QPushButton::clicked,[=](){m_warningDlg.exec();});
    connect(&m_warningDlg, &WarningDlg::SigExit, [=](){this->close();});
}



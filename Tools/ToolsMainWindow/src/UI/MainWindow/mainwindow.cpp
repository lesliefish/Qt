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
    this->setWindowTitle(ui->m_appNameBtn->text());

    QString stylePath = QDir::currentPath() + "/res/main.qss";
    QFile fileQss(stylePath);
    if(!fileQss.open(QFile::ReadOnly))
        return;
    this->setStyleSheet(fileQss.readAll());
}

void MainWindow::InitConnect()
{
    connect(ui->m_helpBtn, &QPushButton::clicked, [=](){m_aboutDlg.exec();});
    connect(ui->m_minBtn, &QPushButton::clicked, [=](){this->showMinimized();});
    connect(ui->m_maxBtn, &QPushButton::clicked, [=](){this->isMaximized() ? this->showNormal() : this->showMaximized();});
    connect(ui->m_closeBtn, &QPushButton::clicked,[=](){m_exitDlg.exec();});
    connect(&m_exitDlg, &WarningDlg::SigExit,
            [=]()
    {
        if(!m_aboutDlg.isHidden())
            m_aboutDlg.close();
        this->close();
    });
}



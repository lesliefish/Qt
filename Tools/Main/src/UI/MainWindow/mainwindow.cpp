#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
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

    QString stylePath = QDir::currentPath() + "/main.qss";
    QFile fileQss(stylePath);
    if(!fileQss.open(QFile::ReadOnly))
        return;
    this->setStyleSheet(fileQss.readAll());
}

void MainWindow::InitConnect()
{
    connect(ui->m_closeBtn, &QPushButton::clicked, [=](){this->close();});
    connect(ui->m_minBtn, &QPushButton::clicked, [=](){this->showMinimized();});
    connect(ui->m_maxBtn, &QPushButton::clicked, [=]()
    {
        if(this->isMaximized())
            this->showNormal();
        else
            this->showMaximized();
    }
    );
}

#include "MyWindow.h"
#include "ui_MyWindow.h"

MyWindow::MyWindow(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::MyWindow();
    ui->setupUi(this);

    setWindowFlags(windowFlags() | Qt::Window);
    connect(qApp, SIGNAL(signalLanguageChange()), this, SLOT(onLanguageChange()));
}

MyWindow::~MyWindow()
{
    delete ui;
}

void MyWindow::onLanguageChange()
{
    ui->retranslateUi(this);
}

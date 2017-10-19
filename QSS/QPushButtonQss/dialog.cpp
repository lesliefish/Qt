#include "dialog.h"
#include "ui_dialog.h"
#include <QFile>
#include <Qdir>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //加载Style
    QString path = QDir::currentPath() + "/../QPushButtonQss/button.qss";
    QFile qssFile(path);
    qssFile.open(QFile::ReadOnly);
    qApp->setStyleSheet(qssFile.readAll());
    qssFile.close();
}

Dialog::~Dialog()
{
    delete ui;
}

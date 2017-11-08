#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_tableModel = new TableModel();
    ui->tableView->setModel(m_tableModel);
}

Widget::~Widget()
{
    delete ui;
}

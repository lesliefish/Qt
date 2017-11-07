#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_tableModel = new TableModel(this);
    ui->tableView->setModel(m_tableModel);
    m_tableModel->Init();
}

Widget::~Widget()
{
    delete ui;
}

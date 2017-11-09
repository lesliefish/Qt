#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //初始化
    Init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Init()
{
    QStringList strHeader;
    strHeader << "name"
              << "age"
              << "sex";

    if(NULL == m_model)
    {
        m_model = new QStandardItemModel();
    }

    m_model->setHorizontalHeaderLabels(strHeader);
    m_model->setColumnCount(strHeader.size());
    m_model->setRowCount(2);
    ui->tableView->verticalHeader()->hide();

    ui->tableView->setModel(m_model);

    QString strHeaderQss;
    strHeaderQss = "QHeaderView::section { background:green; color:white;min-height:3em;}";
    ui->tableView->setStyleSheet(strHeaderQss);
    //设置最后一列表头填充整个控件
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    //均分填充整个控件
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

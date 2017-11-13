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
    strHeader << " "
              << "name"
              << "age"
              << "sex";

    if(NULL == m_model)
    {
        m_model = new QStandardItemModel();
    }

    ui->filterEdit->setVisible(false);
    ui->filterLabel->setVisible(false);

    //表头增加复选框方法
    HeaderView *header = new HeaderView(Qt::Horizontal, ui->tableView);
    ui->tableView->setHorizontalHeader(header);


    //添加表头数据
    //m_model->setHorizontalHeaderLabels(strHeader);
    //设置列数
    m_model->setColumnCount(strHeader.size());
    //设置行数
    m_model->setRowCount(2);
    //隐藏列表头
    ui->tableView->verticalHeader()->hide();

    //setModel
    ui->tableView->setModel(m_model);

    //表头qss设置
    QString strHeaderQss;
    strHeaderQss = "QHeaderView::section { background:green; color:white;min-height:3em;}";
    ui->tableView->setStyleSheet(strHeaderQss);

    //表头设置最后一列数据填充整个控件
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    //表头内容均分填充整个控件
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

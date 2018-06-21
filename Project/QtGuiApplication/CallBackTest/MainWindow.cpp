#include "MainWindow.h"
#include "ui_MainWindow.h"

QLineEdit * MainWindow::line1;
QLineEdit * MainWindow::line2;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::MainWindow();
    ui->setupUi(this);
    
    // 初始化QLineEdit
    line1 = new QLineEdit();
    line2 = new QLineEdit();

    // 把两个line 放进gridLayout
    ui->gridLayout->addWidget(line1, 0, 1);
    ui->gridLayout->addWidget(line2, 0, 2);

    m_scene = new QGraphicsScene();       // 初始化图形场景
    ui->graphicsView->setScene(m_scene);  // 设置场景到 graphicsView
    m_scene->setSceneRect(0, 0, 300, 300);
    m_square = new Square();
    m_square->setCallbackFunc(getPosition);   // 将getPosition设置回调  接收m_square传入的数据
    m_square->setPos(100, 100);
    m_scene->addItem(m_square);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/** 
 * @fn     MainWindow::getPosition
 * @brief  回调函数接收正方形位置 写入两个lineEdit
 * @param  QPointF point
 * @return void
 */
void MainWindow::getPosition(QPointF point)
{
    line1->setText(QString::number(point.x()));
    line2->setText(QString::number(point.y()));
}

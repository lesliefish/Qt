#pragma once

#include <QWidget>
#include <QGraphicsScene>
#include <QLineEdit>
#include "Square.h"
namespace Ui { class MainWindow; };

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();

private:
    Ui::MainWindow* ui;

    QGraphicsScene* m_scene;
    Square *m_square;           // 声明正方形 传输回调
    static QLineEdit *line1;    // 声明一个静态QLineEdit, 执行回调
    static QLineEdit *line2;    // 声明一个静态QLineEdit, 执行回调

private:
    // 声明一个回调函数
    static void getPosition(QPointF point);
};

/** @file   ThreadTest.h
  * 
  * @brief  使用std::thread线程解决Qt界面卡死问题
  * @author lesliefish
  * @date   2018/08/31
  */
#pragma once

#include <QPushButton>
#include <QEventLoop>
#include <QtWidgets/QWidget>
#include "ui_ThreadTest.h"

class ThreadTest : public QWidget
{
    Q_OBJECT

public:
    explicit ThreadTest(QWidget *parent = Q_NULLPTR);

signals:
    // 线程结束信号
    void signalRunOver();

private:
    // 测试函数
    void test();

private:
    Ui::ThreadTestClass ui;
};

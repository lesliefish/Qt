/** @file   Toast.h
 *  @brief  Qt模拟安卓移动客户端Toast提示消息
 *  @note   qss set in ui file
 *  @author lesliefish
 *  @date   2019/05/31
 */
#pragma once

#include <QtWidgets/QWidget>
#include "ui_Toast.h"

class Toast : public QWidget
{
    Q_OBJECT

public:
    Toast(QWidget *parent = Q_NULLPTR);
    ~Toast();

    void setText(const QString& text);

    void showAnimation(int timeout = 2000);// 动画方式show出，默认2秒后消失

public:
    // 静态调用
    static void showTip(const QString& text, QWidget* parent = nullptr);

protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    Ui::ToastClass ui;
};

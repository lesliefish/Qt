#pragma once

#include <QtWidgets/QWidget>
#include "ui_MyWindow.h"

enum Type
{
    LeftTop = 0, // 左上角圆角
    RightTop,    // 右上角圆角
    LeftBottom,  // 左下角圆角
    RightBottom, // 右下角圆角
    Top,         // 上两个圆角
    Bottom,      // 下两个圆角
    Left,        // 左两个圆角
    Right,       // 右两个圆角
    All          // 四个角圆角
};

class MyWindow : public QWidget
{
    Q_OBJECT

public:
    MyWindow(QWidget *parent = Q_NULLPTR);

public:
    void setType(Type t);

protected:
    virtual void paintEvent(QPaintEvent* event);

private:
    Ui::MyWindowClass ui;

    Type m_type{ All };
};

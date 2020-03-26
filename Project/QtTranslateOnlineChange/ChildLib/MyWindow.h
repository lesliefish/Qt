/** @file   MyWindow.h
 *
 *  @brief  test.dll 库里的窗口类 MyWindow
 *  @note
 *  @author lesliefish
 *  @date   2020/03/26
 */
#pragma once

#include <QtWidgets/QWidget>
#include "childlib_global.h"

namespace Ui { class MyWindow; };

class CHILDLIB_EXPORT MyWindow : public QWidget
{
    Q_OBJECT

public:
    MyWindow(QWidget *parent = Q_NULLPTR);
    ~MyWindow();

private slots:
    void onLanguageChange();

private:
    Ui::MyWindow *ui;
};

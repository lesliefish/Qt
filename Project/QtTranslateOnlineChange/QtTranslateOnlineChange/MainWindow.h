/** @file   MainWindow.h
 *
 *  @brief  Ö÷´°¿Ú
 *  @note
 *  @author lesliefish
 *  @date   2020/03/26
 */
#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWindow.h"

class MyWindow;
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private slots:
    void onLanguageChange();

private:
    Ui::MainWindowClass ui;

    MyWindow* m_pChildWindow{ nullptr };
};

#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWindow.h"

namespace animation
{
    class MainWindow : public QWidget
    {
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = Q_NULLPTR);

    private:
        void initUi();
        void initConnection();

    private:
        Ui::MainWindowClass ui;
    };
}


#pragma once

#include <QtWidgets/QWidget>
#include "ui_App.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
    Ui::AppClass ui;
};

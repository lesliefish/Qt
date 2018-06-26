#pragma once

#include <QtWidgets/QWidget>
#include "ui_SingleAppTest.h"

class SingleAppTest : public QWidget
{
    Q_OBJECT

public:
    SingleAppTest(QWidget *parent = Q_NULLPTR);

private:
    Ui::SingleAppTestClass ui;
};

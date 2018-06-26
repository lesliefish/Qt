#pragma once

#include <QtWidgets/QWidget>
#include "ui_SingleAppTest2.h"

class SingleAppTest2 : public QWidget
{
    Q_OBJECT

public:
    SingleAppTest2(QWidget *parent = Q_NULLPTR);

private:
    Ui::SingleAppTest2Class ui;
};

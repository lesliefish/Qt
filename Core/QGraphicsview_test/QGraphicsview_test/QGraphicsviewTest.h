#pragma once

#include <QtWidgets/QWidget>
#include "ui_QGraphicsviewTest.h"

class QGraphicsviewTest : public QWidget
{
	Q_OBJECT

public:
	QGraphicsviewTest(QWidget *parent = Q_NULLPTR);

private:
	Ui::QGraphicsviewTestClass ui;
};

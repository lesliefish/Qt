#include "Widget1.h"
#include "ui_Widget1.h"

Widget1::Widget1(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::Widget1();
	ui->setupUi(this);

	setFixedSize(300, 200);
}

Widget1::~Widget1()
{
	delete ui;
}

void Widget1::retranslate()
{
	ui->retranslateUi(this);
}

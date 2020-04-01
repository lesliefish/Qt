#include "Widget2.h"
#include "ui_Widget2.h"

Widget2::Widget2(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::Widget2();
	ui->setupUi(this);

	setFixedSize(300, 200);
}

Widget2::~Widget2()
{
	delete ui;
}

void Widget2::retranslate()
{
	ui->retranslateUi(this);
}

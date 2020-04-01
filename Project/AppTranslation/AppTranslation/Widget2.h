#pragma once

#include <QWidget>
#include "TranslationSupport.h"

namespace Ui { class Widget2; };

class Widget2 : public QWidget, public TranslationSupport
{
	Q_OBJECT

public:
	Widget2(QWidget *parent = Q_NULLPTR);
	~Widget2();

public:
	virtual void retranslate();

private:
	Ui::Widget2 *ui;
};

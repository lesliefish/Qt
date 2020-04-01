#pragma once

#include <QWidget>
#include "TranslationSupport.h"

namespace Ui { class Widget1; };

class Widget1 : public QWidget, public TranslationSupport
{
	Q_OBJECT

public:
	Widget1(QWidget *parent = Q_NULLPTR);
	~Widget1();

public:
	virtual void retranslate();

private:
	Ui::Widget1 *ui;
};

#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWindow.h"

#include "TranslationSupport.h"

class MainWindow : public QWidget, public TranslationSupport
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

public:
	virtual void retranslate();
private:
	Ui::MainWindowClass ui;
};

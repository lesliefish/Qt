#include "MainWindow.h"
#include <QCoreApplication>
#include <QTranslator>

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setFixedSize(300, 200);

	connect(ui.pushButton, &QPushButton::clicked, [&] 
	{
		static int i = 0;
		QTranslator* trans = new QTranslator();
		auto path = (++i % 2) == 0 ? "apptranslation_en.qm" : "apptranslation_zh.qm";
		bool b= trans->load(path);
		QApplication::installTranslator(trans);

		// ÇÐ»»·­Òë×Ö´®
		for (auto pIterWidget : QApplication::allWidgets())
		{
			if (auto pWidget = dynamic_cast<TranslationSupport*>(pIterWidget))
			{
				pWidget->retranslate();
			}
		}
	});
}

void MainWindow::retranslate()
{
	ui.retranslateUi(this);
}

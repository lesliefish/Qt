#include "MainWindow.h"
#include <QTranslator>
#include "MainApplication.h"
#include "../Childlib//MyWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    m_pChildWindow = new MyWindow(this);
    m_pChildWindow->show();

    connect(ui.pushButton, &QPushButton::clicked, [&]
    {
        static bool bcn{ false };
        static_cast<MainApplication*>(MainApplication::instance())->changeTranslate(bcn ? "en" : "cn");
        bcn = !bcn;
    });

    // 根据主程序app换翻译信号 执行相应的翻译字串更换处理
    connect(qApp, SIGNAL(signalLanguageChange()), this, SLOT(onLanguageChange()));
}

/*
 * @func   MainWindow::onLanguageChange
 * @brief  收到换翻译消息后，重新加载翻译字串处理槽函数
 * @return void
 */
void MainWindow::onLanguageChange()
{
    ui.retranslateUi(this);
}

#include <QQuickWidget>
#include <QQuickItem>
#include <QWidget>
#include <QPushButton>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQuickWidget w;
    w.setSource(QUrl(QStringLiteral("qrc:/QtAppCallQml/Resources/main.qml")));
    w.setResizeMode(QQuickWidget::SizeRootObjectToView);
    w.show();

    QPushButton btn(&w);
    btn.setText("Change Page 1 Color to lightblue");
    btn.show();
    auto swipeView = w.rootObject()->findChild<QObject*>("swipeViewObj");
    auto page1 = w.rootObject()->findChild<QObject*>("page1Obj"); // 点击按钮设置page1背景色lightblue

    if (swipeView != nullptr)
    {
        if (page1 != nullptr)
        {
            QObject::connect(&btn, &QPushButton::clicked, [&]
            {
                QMetaObject::invokeMethod(page1, "setColor", Q_ARG(QVariant, "lightblue"));
                // 或者 			page1->setProperty("color", "lightblue");
            });
        }

        // qml的swipeView页面切换时，最大化显示
        QObject::connect(swipeView, SIGNAL(currentIndexChanged()), &w, SLOT(showMaximized()));
    }


    return a.exec();
}
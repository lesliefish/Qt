#include "Toast.h"
#include <QtWidgets/QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QStringList texts{};
    texts << QStringLiteral("真理惟一可靠的标准就是永远自相符合。")
        << QStringLiteral("Saying and doing are two different things.")
        << QStringLiteral("Two heads are better than one.")
        << QStringLiteral("Time flies.")
        << QStringLiteral("勿谓言之不预！")
        << QStringLiteral("Good company on the road is the shortest cut.")
        << QStringLiteral("Time to go.")
        << QStringLiteral("It is never too late to learn.")
        << QStringLiteral("贸易战中国必胜！");

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]
    {
        static int i = 0;
        Toast::showTip(texts[i%texts.size()], nullptr);
        i++;
    });
    Toast::showTip(QString("Let's go."), nullptr);
    timer.start(4000);

    return app.exec();
}

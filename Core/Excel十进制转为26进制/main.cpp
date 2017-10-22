#include <QCoreApplication>
#include <QDebug>

QString ConvertFromNumber(int number)
{
    QString resultStr = "";
    while(number > 0)
    {
        int k = number % 26;
        if(k == 0)
            k = 26;
        resultStr.push_front(QChar(k + 64));
        number = (number - k) / 26;
    }

    qDebug() << resultStr;
    return resultStr;
}




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    ConvertFromNumber(6);
    return a.exec();
}

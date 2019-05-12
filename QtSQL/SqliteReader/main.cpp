#include <QtCore/QCoreApplication>
#include "SqliteReader.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto info = SqliteReader::read("mytest.db");

    return a.exec();
}

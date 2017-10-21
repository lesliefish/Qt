#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QDir>
#include "ExcelManger.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString strPath = QDir::currentPath() + "/test.xlsx";
    QFile file(strPath);
    if(!file.exists())
    {
        qDebug() << "文件不存在";
        return a.exec();
    }
    else
    {
        //文件类型粗略检查
        if(!strPath.right(4).contains("xls"))
        {
            qDebug() << "只操作xlsx、xls文件";
            return a.exec();
        }
    }

    ExcelManger em;
    em.Test(strPath);

    return a.exec();
}

#include "SqliteReader.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QDebug>
#include <QSQLError>

QSqlDatabase SqliteReader::s_db;

/************************************
 *@func:   SqliteReader::read
 *@brief:  返回值中已拿到表名 列名 单元格数据信息
 *@params: const QString & name 数据库名
 *@return: std::map<QString, std::vector<std::vector<std::tuple<QVariant::Type, QString, QString>>>>
************************************/
std::map<QString, std::vector<std::vector<std::tuple<QVariant::Type, QString, QString>>>>
SqliteReader::read(const QString& name)
{
    std::map<QString, std::vector<std::vector<std::tuple<QVariant::Type, QString, QString>>>> values{};

    // 打开数据库
    s_db = QSqlDatabase::addDatabase("QSQLITE");
    s_db.setDatabaseName(name);
    if (!s_db.open())
    {
        qDebug() << s_db.lastError().text();
        return values;
    }

    // 读数据
    for (const auto& tableName : s_db.tables())
    {
        QString selectSql = QString("select * from %1;").arg(tableName);
        QSqlQuery query{};
        if (!query.exec(selectSql))
        {
            qDebug() << query.lastError().text();
            continue;
        }

        std::vector<std::vector<std::tuple<QVariant::Type, QString, QString>>> tableDatas;
        while (query.next())
        {
            std::vector<std::tuple<QVariant::Type, QString, QString>> singleResultInfos{}; // 单条数据信息
            for (int i = 0; i < query.record().count(); ++i)
            {
                auto type = query.record().field(i).type();
                auto name = query.record().fieldName(i);
                auto value = query.record().value(i).toString();
                singleResultInfos.emplace_back(std::make_tuple(type, name, value));
            }

            tableDatas.emplace_back(std::move(singleResultInfos));
        }
        values[tableName] = std::move(tableDatas);
    }

    return std::move(values);
}
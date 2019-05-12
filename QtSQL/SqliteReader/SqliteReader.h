/*!
 * \file SqliteReader.h
 *
 * \author lesliefish
 * 
 */
#pragma once

#include <QObject>
#include <QVariant>

class QSqlDatabase;
class SqliteReader
{
public:
	static std::map<QString, std::vector<std::vector<std::tuple<QVariant::Type, QString, QString>>>> read(const QString& name);
				// 	 表名	  //表数据vector	 //每一条数据每一列的信息vector   类型   列名      值
	static QSqlDatabase s_db;
};
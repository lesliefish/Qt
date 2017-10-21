#ifndef EXCELMANGER_H
#define EXCELMANGER_H

#include <QObject>
#include <QString>
#include <QAxObject>

class ExcelManger : public QObject
{
    Q_OBJECT
public:
    explicit ExcelManger(QObject *parent = 0);

    bool Test(QString& path);
signals:

public slots:
};

#endif // EXCELMANGER_H

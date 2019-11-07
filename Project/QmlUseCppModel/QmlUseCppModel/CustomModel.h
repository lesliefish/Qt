/** @file   CustomModel.h
 * 
 *
 *  @brief  ×Ô¶¨Òåmodel
 *  @note
 *  @author lesliefish
 *  @date   2019/11/07
 */
#pragma once

#include <QAbstractListModel>

struct Student
{
    QString strName;
    int iAge{ 0 };
};


class CustomModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit CustomModel(QObject *parent);
    ~CustomModel();

public:
    // add
    Q_INVOKABLE void insert(int index, const Student& student);
    // remove
    Q_INVOKABLE void remove(int index);
    // update
    Q_INVOKABLE void update(int index, const Student& student);

    int count() const;

protected:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QHash<int, QByteArray> roleNames() const;

private:
    QList<Student> m_studentList;
};

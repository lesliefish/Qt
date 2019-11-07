#include "CustomModel.h"

CustomModel::CustomModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

CustomModel::~CustomModel()
{
}

int CustomModel::rowCount(const QModelIndex &parent /*= QModelIndex()*/) const
{
    Q_UNUSED(parent);
    return m_studentList.count();
}

QVariant CustomModel::data(const QModelIndex &index, int role /*= Qt::DisplayRole*/) const
{

}

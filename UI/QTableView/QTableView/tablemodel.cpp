#include "tablemodel.h"

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    Init();
}

bool TableModel::Init()
{
    insertColumns(0, HeaderItem::ColumnCountItem);
    setHeaderData(IDItem, Qt::Horizontal,"ID",Qt::DisplayRole);
    setHeaderData(NameItem, Qt::Horizontal, "ID", Qt::DisplayRole);
    setHeaderData(AgeItem, Qt::Horizontal, "AAA", Qt::DisplayRole);
    return true;
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    //headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole);
    //section:位置    orientation:竖直或者水平   role:类型ItemDataRole

    switch (role) {
    case Qt::DisplayRole:
        //水平表头
        if(orientation == Qt::Horizontal)
        {
            if(section == IDItem)
                return QString("ID");
        }
        else if(orientation == Qt::Vertical)
        {

        }
        break;
    default:
        break;
    }

    return QVariant();
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}

bool TableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
}

bool TableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endInsertColumns();
}

bool TableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
}

bool TableModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endRemoveColumns();
}

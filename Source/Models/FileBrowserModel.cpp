#include "Header/Models/FileBrowserModel.h"

FileBrowserModel::FileBrowserModel(ISizeMapper* mapper, QObject *parent) {}

FileBrowserModel::rowCount(const QModelIndex &parent) const
{
    return 0;
}

FileBrowserModel::columnCount(const QModelIndex &parent) const
{
    return 0;
}

QVariant FileBrowserModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}

QVariant FileBrowserModel::data(const QModelIndex &index, int role) const
{
    return QVariant();
}

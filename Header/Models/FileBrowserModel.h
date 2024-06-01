#ifndef FILEBROWSERMODEL_H
#define FILEBROWSERMODEL_H

#include "Header/Models/TableEntryModel.h"
#include "Header/Strategy/ISizeMapper.h"
#include <QAbstractTableModel>

class FileBrowserModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    ISizeMapper* mapper;
    QList<TableEntryModel> entrances;
    void resetEntrances();
public:
    FileBrowserModel(ISizeMapper* mapper, QObject* parent = nullptr);
    qint32 rowCount(const QModelIndex &parent) const;
    qint32 columnCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // FILEBROWSERMODEL_H

#ifndef FILEBROWSERMODEL_H
#define FILEBROWSERMODEL_H

#include "Header/Strategy/ISizeMapper.h"
#include <QAbstractTableModel>
#include <QList>

class FileBrowserModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    ISizeMapper* mapper;
    inline static const QList<QString> HEADER
    { "Name", "Size", "Percent" };
    QList<QList<QString>> entrances;
public:
    FileBrowserModel(QObject* parent = nullptr);
    qint32 rowCount(const QModelIndex& parent) const;
    qint32 columnCount(const QModelIndex& parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex& index, int role) const;
    void setRootPath(const QString& rootPath);
public slots:
    void setStrategy(ISizeMapper* mapper);
};

#endif // FILEBROWSERMODEL_H

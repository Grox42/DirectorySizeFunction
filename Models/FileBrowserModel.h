#ifndef FILEBROWSERMODEL_H
#define FILEBROWSERMODEL_H

#include <QAbstractTableModel>
#include <QList>

class FileBrowserModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    inline static const QList<QString> HEADER { "Name", "Size", "Percent" };
    QList<QList<QString>> entrances;
    QString uint64ToPercent(quint64 part, qreal whole, quint32 precision = 2);
    QString uint64ToSmart(quint64 size);
public:
    FileBrowserModel(QObject* parent = nullptr);
    void setData(const QMap<QString, quint64>& sizesMap);
    qint32 rowCount(const QModelIndex& parent) const override;
    qint32 columnCount(const QModelIndex& parent) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    QVariant data(const QModelIndex& index, int role) const override;
};

#endif // FILEBROWSERMODEL_H

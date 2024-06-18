#include "FileBrowserModel.h"

FileBrowserModel::FileBrowserModel(QObject* parent) : QAbstractTableModel(parent) {}

QString FileBrowserModel::uint64ToPercent(quint64 part, qreal whole, quint32 precision)
{
    if (part == 0) return QString("0%");

    qreal shift {1};
    for (quint32 i {0}; i < precision; i++)
        shift *= 10;

    qreal percent {part / whole * 100};
    percent = qRound64(percent * shift) / shift;

    if (percent < 1 / shift) return QString("<0.01%");

    return QString::number(percent) + '%';
}

QString FileBrowserModel::uint64ToSmart(quint64 size)
{
    QChar prefix[] { 'K', 'M', 'G', 'T', 'P', 'E' };
    qint32 index {-1};
    qreal newSize {static_cast<qreal>(size)};
    while (newSize >= 1024) {
        newSize /= 1024;
        index++;
    }
    if (index > -1 && index < 6)
        return QString::number(newSize, 'd', 1) + ' ' + prefix[index] + 'b';
    else
        return QString::number(newSize, 'd', 1) + " b";
}

void FileBrowserModel::setData(const QMap<QString, quint64>& sizesMap)
{
    quint64 whole {0};
    foreach (const QString& key, sizesMap.keys())
        whole += sizesMap.value(key);

    beginResetModel();

    entrances.clear();
    foreach (const QString& key, sizesMap.keys())
        entrances.append(QList<QString> {
            key,
            uint64ToSmart(sizesMap.value(key)),
            uint64ToPercent(sizesMap.value(key), whole)
        });

    endResetModel();
}

qint32 FileBrowserModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return entrances.size();
}

qint32 FileBrowserModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return HEADER.size();
}

QVariant FileBrowserModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) return QVariant();

    if (orientation == Qt::Vertical) return section + 1;

    if (section < HEADER.size()) return HEADER.at(section);

    return QVariant();
}

QVariant FileBrowserModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() >= entrances.size() || index.column() >= HEADER.size() ||
        (role != Qt::DisplayRole && role != Qt::EditRole)) return QVariant();

    return entrances[index.row()][index.column()];
}

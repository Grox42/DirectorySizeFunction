#include "Header/Models/FileBrowserModel.h"
#include <QElapsedTimer>
#include <QDebug>

FileBrowserModel::FileBrowserModel(QObject* parent) : QAbstractTableModel(parent) {}

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

void FileBrowserModel::setRootPath(const QString& rootPath)
{
    this->rootPath = rootPath;
    entrances.clear();

    QElapsedTimer timer;
    timer.start();

    QMap<QString, quint64> sizesMap = mapper->getSizesMap(QDir(rootPath));
    QMap<QString, QString> percentMap = mapper->getPercentagesMap(sizesMap);
    QMap<QString, QString> smartSizesMap = mapper->getSmartSizesMap(sizesMap);

    qDebug() << rootPath << ':' << timer.elapsed() << "ms";

    foreach (const QString& key, percentMap.keys())
        entrances.append(QList<QString> { key, smartSizesMap.value(key), percentMap.value(key) });

    emit headerDataChanged(Qt::Vertical, 0, entrances.size());
}

void FileBrowserModel::setStrategy(ISizeMapper *mapper)
{
    this->mapper = mapper;

    if (rootPath.size() != 0) setRootPath(rootPath);
}

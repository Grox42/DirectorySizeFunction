#include "Header/Strategy/DirSizeMapper.h"

quint64 DirSizeMapper::getDirSize(const QFileInfo& fileInfo) const
{
    if (fileInfo.isDir()) {
        QDir dir = fileInfo.dir();
        dir.cd(fileInfo.fileName());

        quint64 sum = 0;
        foreach (const QFileInfo& entry, dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::Hidden | QDir::NoDotAndDotDot))
            sum += getDirSize(entry);

        return sum;
    } else return fileInfo.size();
}

QSharedPointer<QMap<QString, quint64>> DirSizeMapper::getSizesMap(const QDir& dir) const
{
    QMap<QString, quint64>* map = new QMap<QString, quint64>();

    foreach (const QFileInfo& fileInfo, dir.entryInfoList(QDir::Dirs | QDir::Hidden | QDir::NoDotAndDotDot))
        map->insert(fileInfo.fileName(), getDirSize(fileInfo));

    quint64 sum = 0;
    foreach (const QFileInfo& fileInfo, dir.entryInfoList(QDir::Files | QDir::Hidden))
        sum += getDirSize(fileInfo);
    map->insert("files", sum);

    return QSharedPointer<QMap<QString, quint64>>(map);
}

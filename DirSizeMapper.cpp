#include "DirSizeMapper.h"

quint64 DirSizeMapper::getDirSize(const QFileInfo& fileInfo) const
{
    if (fileInfo.isDir()) {
        QDir dir = fileInfo.dir();
        dir.cd(fileInfo.fileName());

        quint64 sum = 0;
        foreach (const QFileInfo& entry, dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot))
            sum += getDirSize(entry);

        return sum;
    } else return fileInfo.size();
}

QMap<QString, quint64>& DirSizeMapper::getSizesMap(const QDir& dir) const
{
    QMap<QString, quint64>* map = new QMap<QString, quint64>();

    foreach (const QFileInfo& fileInfo, dir.entryInfoList(QDir::Dirs | QDir::NoDotDot))
        map->insert(fileInfo.fileName(), getDirSize(fileInfo));

    quint64 sum = 0;
    foreach (const QFileInfo& fileInfo, dir.entryInfoList(QDir::Files))
        sum += getDirSize(fileInfo);
    map->insert("fiels", sum);

    return *map;
}

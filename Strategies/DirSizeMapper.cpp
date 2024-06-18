#include "DirSizeMapper.h"
#include <QDir>

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

void DirSizeMapper::getSizesMap(const QString& dirPath) const
{
    QMap<QString, quint64>* map = new QMap<QString, quint64>();
    QDir dir(dirPath);

    foreach (const QFileInfo& fileInfo, dir.entryInfoList(QDir::Dirs | QDir::Hidden | QDir::NoDotAndDotDot))
        map->insert(fileInfo.fileName(), getDirSize(fileInfo));

    quint64 sum = 0;
    foreach (const QFileInfo& fileInfo, dir.entryInfoList(QDir::Files | QDir::Hidden))
        sum += getDirSize(fileInfo);
    map->insert("files", sum);

    selectionEvent(*map);

    delete map;
}

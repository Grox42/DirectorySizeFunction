#include "TypeSizeMapper.h"

void TypeSizeMapper::addTypeSizePairs(const QFileInfo& fileInfo, QMap<QString, quint64>& map) const
{
    if (fileInfo.isDir()) {
        QDir dir = fileInfo.dir();
        dir.cd(fileInfo.fileName());

        foreach (const QFileInfo& entry, dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::Hidden | QDir::NoDotAndDotDot))
            addTypeSizePairs(entry, map);
    } else {
        QString suffix = '.' + fileInfo.completeSuffix();
        if (map.contains(suffix)) map[suffix] += fileInfo.size();
        else map.insert(suffix, fileInfo.size());
    }
}

QMap<QString, quint64>& TypeSizeMapper::getSizesMap(const QDir& dir) const
{
    QMap<QString, quint64>* map = new QMap<QString, quint64>();

    addTypeSizePairs(QFileInfo(dir.path()), *map);

    return *map;
}

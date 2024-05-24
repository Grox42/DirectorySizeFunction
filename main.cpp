#include "ISizeMapper.h"
#include "DirSizeMapper.h"
#include "TypeSizeMapper.h"
#include <QDebug>

int main()
{
    QDir rootDir("../MicroGit");
    ISizeMapper* mapper = new DirSizeMapper();

    QMap<QString, quint64> sizeMap = mapper->getSizesMap(rootDir);
    foreach (const QString& key, sizeMap.keys())
        qDebug() << key << sizeMap.value(key);

    qDebug() << '\n';

    QMap<QString, QString> percentMap = mapper->getPercentagesMap(sizeMap);
    foreach (const QString& key, percentMap.keys())
        qDebug() << key << percentMap.value(key);

    return 0;
}

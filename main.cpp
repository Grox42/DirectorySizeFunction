#include "Context.h"
#include "DirSizeMapper.h"
#include "TypeSizeMapper.h"
#include <QDebug>

int main()
{
    QDir rootDir("../MicroGit");
    Context context(new DirSizeMapper);

    QMap<QString, quint64> sizeMap = context.getSizesMap(rootDir);
    foreach (const QString& key, sizeMap.keys())
        qDebug() << key << sizeMap.value(key);

    qDebug() << '\n';

    QMap<QString, QString> percentMap = context.getPercentagesMap(rootDir);
    foreach (const QString& key, percentMap.keys())
        qDebug() << key << percentMap.value(key);

    return 0;
}

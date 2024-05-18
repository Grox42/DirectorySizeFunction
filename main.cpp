#include "ISizeMapper.h"
#include "DirSizeMapper.h"
#include "TypeSizeMapper.h"
#include <QDebug>

int main()
{
    QDir rootDir("../MicroGit");
    ISizeMapper* mapper = new DirSizeMapper();
    QMap<QString, quint64> map = mapper->getSizesMap(rootDir);

    foreach (const QString& key, map.keys())
        qDebug() << key << map.value(key);

    return 0;
}

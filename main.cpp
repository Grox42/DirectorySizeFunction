#include "Context.h"
#include "DirSizeMapper.h"
#include "TypeSizeMapper.h"
#include <QDebug>

void output(const Context& context, const QDir& rootDir)
{
    QMap<QString, quint64> sizeMap = context.getSizesMap(rootDir);
    foreach (const QString& key, sizeMap.keys())
        qDebug() << key << sizeMap.value(key);

    qDebug() << '\n';

    QMap<QString, QString> percentMap = context.getPercentagesMap(rootDir);
    foreach (const QString& key, percentMap.keys())
        qDebug() << key << percentMap.value(key);

    qDebug() << "\n\n";
}

int main()
{
    QDir rootDir("Tests/test1");

    output(Context(new DirSizeMapper), rootDir);

    output(Context(new TypeSizeMapper), rootDir);

    return 0;
}

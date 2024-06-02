#include "Header/Strategy/ISizeMapper.h"

QString ISizeMapper::uint64ToPercent(quint64 part, qreal whole, quint32 precision)
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

QString ISizeMapper::uint64ToSmart(quint64 size)
{
    QChar prefix[] { 'K', 'M', 'G', 'T', 'P', 'E' };
    qint32 index = -1;
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

QMap<QString, QString>& ISizeMapper::getPercentagesMap(const QMap<QString, quint64>& sizesMap)
{
    QMap<QString, QString>* map = new QMap<QString, QString>();

    qreal whole {0};
    foreach (const QString& key, sizesMap.keys())
        whole += sizesMap.value(key);

    foreach (const QString& key, sizesMap.keys())
        map->insert(key, uint64ToPercent(sizesMap.value(key), whole));

    return *map;
}

QMap<QString, QString>& ISizeMapper::getSmartSizesMap(const QMap<QString, quint64>& sizesMap)
{
    QMap<QString, QString>* map = new QMap<QString, QString>();

    foreach (const QString& key, sizesMap.keys())
        map->insert(key, uint64ToSmart(sizesMap.value(key)));

    return *map;
}

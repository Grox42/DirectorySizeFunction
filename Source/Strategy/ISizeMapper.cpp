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

    return QString().number(percent) + '%';
}


QMap<QString, QString>& ISizeMapper::getPercentagesMap(const QMap<QString, quint64>& sizesMap) const
{
    QMap<QString, QString>* map = new QMap<QString, QString>();

    qreal whole = 0;
    foreach (const QString& key, sizesMap.keys())
        whole += sizesMap.value(key);

    foreach (const QString& key, sizesMap.keys())
        if (key != ".") map->insert(key, uint64ToPercent(sizesMap.value(key), whole));

    return *map;
}

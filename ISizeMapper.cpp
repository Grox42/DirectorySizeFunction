#include "ISizeMapper.h"

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

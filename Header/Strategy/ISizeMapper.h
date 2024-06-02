#ifndef ISIZEMAPPER_H
#define ISIZEMAPPER_H

#include <QMap>
#include <QDir>

class ISizeMapper
{
protected:
    static QString uint64ToPercent(quint64 part, qreal whole, quint32 precision = 2);
public:
    virtual ~ISizeMapper() = default;
    virtual QMap<QString, quint64>& getSizesMap(const QDir& dir) const = 0;
    virtual QMap<QString, QString>& getPercentagesMap(const QMap<QString, quint64>& sizesMap) const = 0;
};

#endif // ISIZEMAPPER_H

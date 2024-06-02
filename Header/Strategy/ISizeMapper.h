#ifndef ISIZEMAPPER_H
#define ISIZEMAPPER_H

#include <QMap>
#include <QDir>

class ISizeMapper
{
protected:
    static QString uint64ToPercent(quint64 part, qreal whole, quint32 precision = 2);
    static QString uint64ToSmart(quint64 size);
public:
    virtual ~ISizeMapper() = default;
    virtual QMap<QString, quint64>& getSizesMap(const QDir& dir) const = 0;
    static QMap<QString, QString>& getPercentagesMap(const QMap<QString, quint64>& sizesMap);
    static QMap<QString, QString>& getSmartSizesMap(const QMap<QString, quint64>& sizesMap);
};

#endif // ISIZEMAPPER_H

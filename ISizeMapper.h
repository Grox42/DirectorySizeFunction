#ifndef ISIZEMAPPER_H
#define ISIZEMAPPER_H

#include <QString>
#include <QMap>
#include <QDir>

class ISizeMapper
{
public:
    virtual ~ISizeMapper() = default;
    virtual QMap<QString, quint64>& getSizesMap(const QDir& dir) const = 0;
};

#endif // ISIZEMAPPER_H

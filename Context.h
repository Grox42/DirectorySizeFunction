#ifndef CONTEXT_H
#define CONTEXT_H

#include "ISizeMapper.h"

class Context
{
private:
    ISizeMapper* mapper;
public:
    Context(ISizeMapper* mapper);
    QMap<QString, quint64> getSizesMap(const QDir& dir) const;
    QMap<QString, QString> getPercentagesMap(const QDir& dir) const;
};

#endif // CONTEXT_H

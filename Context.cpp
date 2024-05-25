#include "Context.h"

Context::Context(ISizeMapper* mapper)
{
    this->mapper = mapper;
}

void Context::setMapper(ISizeMapper* mapper)
{
    this->mapper = mapper;
}

QMap<QString, quint64> Context::getSizesMap(const QDir &dir) const
{
    return mapper->getSizesMap(dir);
}

QMap<QString, QString> Context::getPercentagesMap(const QDir &dir) const
{
    return mapper->getPercentagesMap(getSizesMap(dir));
}

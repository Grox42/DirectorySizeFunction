#ifndef TYPESIZEMAPPER_H
#define TYPESIZEMAPPER_H

#include "Header/Strategy/ISizeMapper.h"

class TypeSizeMapper : public ISizeMapper
{
private:
    void addTypeSizePairs(const QFileInfo& fileInfo, QMap<QString, quint64>& map) const;
public:
    virtual ~TypeSizeMapper() override = default;
    virtual QSharedPointer<QMap<QString, quint64>> getSizesMap(const QDir& dir) const override;
};

#endif // TYPESIZEMAPPER_H
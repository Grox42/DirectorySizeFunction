#ifndef TYPESIZEMAPPER_H
#define TYPESIZEMAPPER_H

#include "ISizeMapper.h"

class TypeSizeMapper : public ISizeMapper
{
private:
    void addTypeSizePairs(const QFileInfo& fileInfo, QMap<QString, quint64>& map) const;
public:
    virtual ~TypeSizeMapper() override = default;
    virtual QMap<QString, quint64>& getSizesMap(const QDir& dir) const override;
    virtual QMap<QString, QString>& getPercentagesMap(const QMap<QString, quint64>& sizesMap) const override;
};

#endif // TYPESIZEMAPPER_H

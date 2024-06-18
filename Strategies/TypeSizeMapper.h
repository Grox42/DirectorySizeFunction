#ifndef TYPESIZEMAPPER_H
#define TYPESIZEMAPPER_H

#include "ISizeMapper.h"
#include <QFileInfo>

class TypeSizeMapper : public ISizeMapper
{
private:
    void addTypeSizePairs(const QFileInfo& fileInfo, QMap<QString, quint64>& map) const;
public:
    virtual ~TypeSizeMapper() override = default;
    virtual void getSizesMap(const QString& dirPath) const override;
};

#endif // TYPESIZEMAPPER_H

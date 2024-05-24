#ifndef DIRSIZEMAPPER_H
#define DIRSIZEMAPPER_H

#include "ISizeMapper.h"
#include <QFileInfo>

class DirSizeMapper : public ISizeMapper
{
private:
    quint64 getDirSize(const QFileInfo& fileInfo) const;
public:
    virtual ~DirSizeMapper() override = default;
    virtual QMap<QString, quint64>& getSizesMap(const QDir& dir) const override;
    virtual QMap<QString, QString>& getPercentagesMap(const QMap<QString, quint64>& sizesMap) const override;
};

#endif // DIRSIZEMAPPER_H

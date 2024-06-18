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
    virtual void getSizesMap(const QString& dirPath) const override;
};

#endif // DIRSIZEMAPPER_H

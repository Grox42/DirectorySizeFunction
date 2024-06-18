#ifndef ISIZEMAPPER_H
#define ISIZEMAPPER_H

#include "Observer/Observable.h"

class ISizeMapper : public Observable
{
public:
    virtual ~ISizeMapper() = default;
    virtual void getSizesMap(const QString& dirPath) const = 0;
    virtual void selectionEvent(const QMap<QString, quint64> &sizesMap) const override;
};

#endif // ISIZEMAPPER_H

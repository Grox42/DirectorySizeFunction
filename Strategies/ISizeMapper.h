#ifndef ISIZEMAPPER_H
#define ISIZEMAPPER_H

#include "Observer/IObservable.h"

class ISizeMapper : public IObservable
{
public:
    virtual ~ISizeMapper() = default;
    virtual void getSizesMap(const QString& dirPath) const = 0;
    virtual void selectionEvent(const QMap<QString, quint64> &sizesMap) const override;
};

#endif // ISIZEMAPPER_H

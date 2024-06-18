#ifndef IOBSERVABLE_H
#define IOBSERVABLE_H

#include "IObserver.h"

class IObservable
{
protected:
    QList<IObserver*> observers;
public:
    bool addObserver(IObserver* observer);
    bool delObserver(IObserver* observer);
    virtual void selectionEvent(const QMap<QString, quint64>& sizesMap) const = 0;
};

#endif // IOBSERVABLE_H

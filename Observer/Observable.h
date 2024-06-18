#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "Observer.h"

class Observable
{
protected:
    QList<Observer*> observers;
public:
    bool addObserver(Observer* observer);
    bool delObserver(Observer* observer);
    virtual void selectionEvent(const QMap<QString, quint64>& sizesMap) const = 0;
};

#endif // OBSERVABLE_H

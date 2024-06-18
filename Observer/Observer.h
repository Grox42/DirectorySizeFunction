#ifndef OBSERVER_H
#define OBSERVER_H

#include <QMap>

class Observer
{
public:
    virtual void updateDisplay(const QMap<QString, quint64>& sizesMap) = 0;
};

#endif // OBSERVER_H

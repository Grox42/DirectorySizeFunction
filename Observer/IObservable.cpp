#include "IObservable.h"

bool IObservable::addObserver(IObserver* observer)
{
    foreach (const IObserver* _observer, observers)
        if(_observer == observer) return false;

    observers.append(observer);
    return true;
}

bool IObservable::delObserver(IObserver* observer)
{
    return observers.removeOne(observer);
}

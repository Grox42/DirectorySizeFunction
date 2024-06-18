#include "Observable.h"

bool Observable::addObserver(Observer* observer)
{
    foreach (const Observer* _observer, observers)
        if(_observer == observer) return false;

    observers.append(observer);
    return true;
}

bool Observable::delObserver(Observer* observer)
{
    return observers.removeOne(observer);
}

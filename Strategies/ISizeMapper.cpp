#include "ISizeMapper.h"

void ISizeMapper::selectionEvent(const QMap<QString, quint64> &sizesMap) const
{
    foreach (IObserver* observer, observers)
        observer->updateDisplay(sizesMap);
}

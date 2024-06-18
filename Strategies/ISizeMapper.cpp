#include "ISizeMapper.h"

void ISizeMapper::selectionEvent(const QMap<QString, quint64> &sizesMap) const
{
    foreach (Observer* observer, observers)
        observer->updateDisplay(sizesMap);
}

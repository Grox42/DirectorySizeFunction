#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <QMap>

class IObserver
{
public:
    virtual void updateDisplay(const QMap<QString, quint64>& sizesMap) = 0;
};

#endif // IOBSERVER_H

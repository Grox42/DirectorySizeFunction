#ifndef TABLEENTRYMODEL_H
#define TABLEENTRYMODEL_H

#include <QString>

class TableEntryModel
{
private:
    QString name;
    quint64 size;
    QString percent;
public:
    TableEntryModel(const QString& name, quint64 size, const QString& percent);
    QString getName() const;
    quint64 getSize() const;
    QString getPercent() const;
};

#endif // TABLEENTRYMODEL_H

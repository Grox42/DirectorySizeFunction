#include "Header/Models/TableEntryModel.h"

TableEntryModel::TableEntryModel(const QString &name, quint64 size, const QString &percent)
{
    this->name = name;
    this->size = size;
    this->percent = percent;
}

QString TableEntryModel::getName() const { return name; }
quint64 TableEntryModel::getSize() const { return size; }
QString TableEntryModel::getPercent() const { return percent; }

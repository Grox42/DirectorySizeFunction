#ifndef PIECHART_H
#define PIECHART_H

#include "Header/View/Charts/IChart.h"

class PieChart : public IChart
{
private:
    virtual QtCharts::QAbstractSeries* getSeries(const QMap<QString, quint64>& sizesMap) const override;
};

#endif // PIECHART_H

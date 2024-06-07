#ifndef BARCHART_H
#define BARCHART_H

#include "Header/View/Charts/IChart.h"

class BarChart : public IChart
{
private:
    virtual QtCharts::QAbstractSeries* getSeries(const QMap<QString, quint64>& sizesMap) const override;
};

#endif // BARCHART_H

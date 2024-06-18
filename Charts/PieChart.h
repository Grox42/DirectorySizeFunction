#ifndef PIECHART_H
#define PIECHART_H

#include "IChart.h"

class PieChart : public IChart
{
private:
    virtual QtCharts::QAbstractSeries* getSeries(const QMap<QString, quint64>& sizesMap) const override;
public:
    virtual ~PieChart() override = default;
};

#endif // PIECHART_H

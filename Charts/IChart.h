#ifndef ICHART_H
#define ICHART_H

#include <QChart>
#include <QAbstractSeries>
#include <QLegend>

class IChart
{
protected:
    virtual QtCharts::QAbstractSeries* getSeries(const QMap<QString, quint64>& sizesMap) const = 0;
    void setLegend(QtCharts::QLegend* legend) const;
public:
    virtual ~IChart() = default;
    QtCharts::QChart* CreateChart(const QMap<QString, quint64>& sizesMap) const;
};

#endif // ICHART_H

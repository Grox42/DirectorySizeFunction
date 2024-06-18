#include "PieChart.h"
#include <QPieSeries>

using namespace QtCharts;

QAbstractSeries* PieChart::getSeries(const QMap<QString, quint64> &sizesMap) const
{
    QPieSeries* series = new QPieSeries();

    foreach (const QString& key, sizesMap.keys())
        series->append(key, static_cast<qreal>(sizesMap.value(key)));

    return series;
}

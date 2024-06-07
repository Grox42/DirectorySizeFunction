#include "Header/View/Charts/BarChart.h"
#include <QBarSet>
#include <QBarSeries>

using namespace QtCharts;

QAbstractSeries* BarChart::getSeries(const QMap<QString, quint64> &sizesMap) const
{
    QBarSeries* series = new QBarSeries();

    QBarSet* set;
    foreach (const QString& key, sizesMap.keys()) {
        set = new QBarSet(key);
        set->append(static_cast<qreal>(sizesMap.value(key)));
        series->append(set);
    }

    return series;
}

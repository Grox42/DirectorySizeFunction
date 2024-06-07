#include "Header/View/Charts/IChart.h"

using namespace QtCharts;

void IChart::setLegend(QLegend *legend) const
{
    legend->setVisible(true);
    legend->setAlignment(Qt::AlignRight);
}

QChart* IChart::CreateChart(const QMap<QString, quint64>& sizesMap) const
{
    QChart* chart = new QChart();

    chart->addSeries(getSeries(sizesMap));

    setLegend(chart->legend());

    chart->show();

    return chart;
}

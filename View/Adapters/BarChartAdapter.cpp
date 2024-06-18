#include "BarChartAdapter.h"
#include <QSplitter>
#include <QChartView>

using namespace QtCharts;

BarChartAdapter::BarChartAdapter(const QString& rootDirPath, QWidget* parent)
    : FileBrowser(rootDirPath, parent)
{
    QChartView* chartView = new QChartView(barChartFactory->CreateChart(QMap<QString, quint64>()));

    QSplitter* splitter = static_cast<QSplitter*>(centralWidget());
    splitter->addWidget(chartView);
    splitter->setSizes(QList<qint32>{ INT_MAX, INT_MAX });

    chartView->show();
}

void BarChartAdapter::updateDisplay(const QMap<QString, quint64>& sizesMap)
{
    QChartView* chartView = new QChartView(barChartFactory->CreateChart(sizesMap));
    delete static_cast<QSplitter*>(centralWidget())->replaceWidget(1, chartView);
    chartView->show();
}

#include "PieChartAdapter.h"
#include <QSplitter>
#include <QChartView>

using namespace QtCharts;

PieChartAdapter::PieChartAdapter(const QString& rootDirPath, QWidget* parent)
    : IFileBrowser(rootDirPath, parent)
{
    QChartView* chartView = new QChartView(pieChartFactory->CreateChart(QMap<QString, quint64>()));

    QSplitter* splitter = static_cast<QSplitter*>(centralWidget());
    splitter->addWidget(chartView);
    splitter->setSizes(QList<qint32>{ INT_MAX, INT_MAX });

    chartView->show();
}

void PieChartAdapter::updateDisplay(const QMap<QString, quint64>& sizesMap)
{
    QChartView* chartView = new QChartView(pieChartFactory->CreateChart(sizesMap));
    delete static_cast<QSplitter*>(centralWidget())->replaceWidget(1, chartView);
    chartView->show();
}

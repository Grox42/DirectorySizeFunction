#include "Strategies/DirSizeMapper.h"
#include "Strategies/TypeSizeMapper.h"
#include "View/Adapters/TableChartAdapter.h"
#include "View/Adapters/BarChartAdapter.h"
#include "View/Adapters/PieChartAdapter.h"
#include <QApplication>

void switchChart(IFileBrowser* charts[], qint32 oldIndex, qint32 newIndex)
{
    if (oldIndex == newIndex) return;

    charts[newIndex]->setStatus(charts[oldIndex]);
    charts[newIndex]->setGeometry(charts[oldIndex]->geometry());
    charts[newIndex]->show();
    charts[oldIndex]->hide();
}

void setMenuChart(IFileBrowser* charts[])
{
    for(qint32 index = 0; index < 3; index++) {
        QMenu* chart = new QMenu("Chart", charts[index]);

        QAction* tableChart = new QAction("Table", charts[index]);
        QObject::connect(tableChart, &QAction::triggered, charts[0], [charts, index](){ switchChart(charts, index, 0); });

        QAction* barChart = new QAction("Bar", charts[index]);
        QObject::connect(barChart, &QAction::triggered, charts[1], [charts, index](){ switchChart(charts, index, 1); });

        QAction* pieChart = new QAction("Pie", charts[index]);
        QObject::connect(pieChart, &QAction::triggered, charts[2], [charts, index](){ switchChart(charts, index, 2); });

        chart->addAction(tableChart);
        chart->addAction(barChart);
        chart->addAction(pieChart);
        charts[index]->menuBar()->addMenu(chart);
    }
}

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QString rootDirPath("D:/Programming/Qt");
    ISizeMapper* strategies[] { new DirSizeMapper, new TypeSizeMapper };
    IFileBrowser* charts[] {
        new TableChartAdapter(rootDirPath),
        new BarChartAdapter(rootDirPath),
        new PieChartAdapter(rootDirPath)
    };

    for (qint32 index {0}; index < 3; index++) {
        charts[index]->addStrategy("Group by dir", strategies[0]);
        charts[index]->addStrategy("Group by type", strategies[1]);
    }

    setMenuChart(charts);

    charts[0]->show();


    return a.exec();
}

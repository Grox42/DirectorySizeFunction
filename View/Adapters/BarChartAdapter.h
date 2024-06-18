#ifndef BARCHARTADAPTER_H
#define BARCHARTADAPTER_H

#include "../IFileBrowser.h"
#include "Charts/BarChart.h"

class BarChartAdapter : public IFileBrowser
{
private:
    IChart* barChartFactory = new BarChart();
public:
    BarChartAdapter(const QString& rootDirPath, QWidget* parent = nullptr);
    virtual void updateDisplay(const QMap<QString, quint64>& sizesMap) override;
    ~BarChartAdapter() { delete barChartFactory; }
};

#endif // BARCHARTADAPTER_H

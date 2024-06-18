#ifndef PIECHARTADAPTER_H
#define PIECHARTADAPTER_H

#include "../IFileBrowser.h"
#include "Charts/PieChart.h"

class PieChartAdapter : public IFileBrowser
{
private:
    IChart* pieChartFactory = new PieChart();
public:
    PieChartAdapter(const QString& rootDirPath, QWidget* parent = nullptr);
    virtual void updateDisplay(const QMap<QString, quint64>& sizesMap) override;
    ~PieChartAdapter() { delete pieChartFactory; }
};

#endif // PIECHARTADAPTER_H

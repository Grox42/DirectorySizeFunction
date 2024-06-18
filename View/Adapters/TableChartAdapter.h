#ifndef TABLECHARTADAPTER_H
#define TABLECHARTADAPTER_H

#include "../FileBrowser.h"
#include "Models/FileBrowserModel.h"
#include <QTableView>

class TableChartAdapter : public FileBrowser
{
private:
    FileBrowserModel* dirModel = nullptr;
    QTableView* dirView = nullptr;
public:
    TableChartAdapter(const QString& rootDirPath, QWidget* parent = nullptr);
    virtual void updateDisplay(const QMap<QString, quint64>& sizesMap) override;
};

#endif // TABLECHARTADAPTER_H

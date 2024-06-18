#include "TableChartAdapter.h"
#include <QSplitter>

TableChartAdapter::TableChartAdapter(const QString &rootDirPath, QWidget *parent)
    : IFileBrowser(rootDirPath, parent)
{
    dirModel = new FileBrowserModel(this);

    dirView = new QTableView();
    dirView->setModel(dirModel);

    static_cast<QSplitter*>(centralWidget())->addWidget(dirView);

    dirView->show();
}

void TableChartAdapter::updateDisplay(const QMap<QString, quint64>& sizesMap)
{
    dirModel->setData(sizesMap);
}

#include "Header/View/MainWindow.h"
#include "Header/Strategy/DirSizeMapper.h"
#include <QSplitter>
#include <QMenu>
#include <QMenuBar>
#include <QItemSelectionModel>

MainWindow::MainWindow(const QString& rootDirPath, QWidget* parent) : QMainWindow(parent)
{
    setGeometry(200, 200, 1600, 800);

    QMenu* group = new QMenu("Group", parent);

    QAction* groupByDir = new QAction("Group By Dir", parent);
    QObject::connect(groupByDir, &QAction::triggered, this, &MainWindow::setGroupByDir);

    QAction* groupByType = new QAction("Group By Type", parent);
    QObject::connect(groupByType, &QAction::triggered, this, &MainWindow::setGroupByType);

    group->addAction(groupByDir);
    group->addAction(groupByType);
    menuBar()->addMenu(group);

    QSplitter* splitter = new QSplitter(parent);

    fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setRootPath(rootDirPath);
    fileSystemModel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);

    fileSystemView = new QTreeView();
    fileSystemView->setModel(fileSystemModel);
    fileSystemView->expandAll();

    dirModel = new FileBrowserModel(this);
    dirModel->setStrategy(new DirSizeMapper());
    dirModel->setRootPath(rootDirPath);

    dirView = new QTableView();
    dirView->setModel(dirModel);

    splitter->addWidget(fileSystemView);
    splitter->addWidget(dirView);
    setCentralWidget(splitter);

    QItemSelectionModel* selectionModel = fileSystemView->selectionModel();
    QObject::connect(selectionModel, &QItemSelectionModel::selectionChanged, this, &MainWindow::selectionChanged);
}

void MainWindow::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);

    dirModel->setRootPath(fileSystemModel->filePath(selected.indexes().constFirst()));
}

void MainWindow::setGroupByDir()
{
    if (dirModel) dirModel->~QAbstractTableModel();
    dirModel->setStrategy(new DirSizeMapper());
}

void MainWindow::setGroupByType() const
{
    if (dirModel) dirModel->~QAbstractTableModel();
    //dirModel->setStrategy();
}

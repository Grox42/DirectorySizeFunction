#include "Header/View/MainWindow.h"
#include <QSplitter>
#include <QMenu>
#include <QMenuBar>
#include <QItemSelectionModel>
#include <QHeaderView>

MainWindow::MainWindow(const QString& rootDirPath, QWidget* parent) : QMainWindow(parent)
{
    setGeometry(200, 200, 1200, 600);

    QMenu* group = new QMenu("Group", this);

    QAction* groupByDir = new QAction("Group By Dir", this);
    QObject::connect(groupByDir, &QAction::triggered, this, &MainWindow::setGroupByDir);

    QAction* groupByType = new QAction("Group By Type", this);
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
    fileSystemView->header()->hideSection(1);
    fileSystemView->header()->hideSection(2);
    fileSystemView->header()->hideSection(3);

    dirModel = new FileBrowserModel(this);
    dirModel->setStrategy(strategies[0]);
    dirModel->setRootPath(rootDirPath);

    dirView = new QTableView();
    dirView->setModel(dirModel);

    splitter->addWidget(fileSystemView);
    splitter->addWidget(dirView);
    setCentralWidget(splitter);

    QObject::connect(fileSystemView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &MainWindow::selectionChanged);
}

MainWindow::~MainWindow()
{
    for (qint32 index = 0; index < strategies.size(); index++)
        delete strategies[index];
}

void MainWindow::setGroupByDir() { dirModel->setStrategy(strategies[0]); }

void MainWindow::setGroupByType() { dirModel->setStrategy(strategies[1]); }

void MainWindow::selectionChanged(const QItemSelection& selected, const QItemSelection& deselected)
{
    Q_UNUSED(deselected);
    dirModel->setRootPath(fileSystemModel->filePath(selected.indexes().constFirst()));
}

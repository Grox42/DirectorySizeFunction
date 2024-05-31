#include "MainWindow.h"
#include <QSplitter>
#include <QMenu>
#include <QMenuBar>

MainWindow::MainWindow(const QString& rootDirPath, QWidget* parent) : QMainWindow(parent)
{
    setGeometry(200, 200, 1600, 800);

    QMenu* group = new QMenu("Group", parent);

    QAction* groupByDir = new QAction(tr("&Group By Dir"), parent);
    QObject::connect(groupByDir, &QAction::triggered, this, &MainWindow::setGroupByDir);

    QAction* groupByType = new QAction(tr("&Group By Type"), parent);
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

    dirModel = new FileBrowserModel(nullptr, this);

    dirView = new QTableView();
    dirView->setModel(dirModel);

    splitter->addWidget(fileSystemView);
    splitter->addWidget(dirView);
    setCentralWidget(splitter);
}

void MainWindow::setGroupByDir() const
{

}

void MainWindow::setGroupByType() const
{

}

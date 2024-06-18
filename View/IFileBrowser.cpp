#include "IFileBrowser.h"
#include <QSplitter>
#include <QItemSelectionModel>
#include <QHeaderView>

IFileBrowser::IFileBrowser(const QString& rootDirPath, QWidget* parent)
    : QMainWindow(parent)
{
    this->rootDirPath = rootDirPath;

    setGeometry(200, 200, 1200, 600);

    group = new QMenu("Group", this);
    menuBar()->addMenu(group);

    QSplitter* splitter = new QSplitter(this);

    fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setRootPath(rootDirPath);
    fileSystemModel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);

    fileSystemView = new QTreeView();
    fileSystemView->setModel(fileSystemModel);
    fileSystemView->expandAll();
    fileSystemView->header()->hideSection(1);
    fileSystemView->header()->hideSection(2);
    fileSystemView->header()->hideSection(3);

    splitter->addWidget(fileSystemView);
    setCentralWidget(splitter);

    QObject::connect(fileSystemView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &IFileBrowser::selectionChanged);
}

bool IFileBrowser::addStrategy(const QString& name, ISizeMapper* mapper)
{
    if (strategies.contains(name)) return false;

    strategies.insert(name, mapper);
    mapper->addObserver(this);

    QAction* action = new QAction(name, group);
    QObject::connect(action, &QAction::triggered, action, [action, this](){
        currentMapper = strategies.value(action->text());
        currentMapper->getSizesMap(rootDirPath);
    });
    group->addAction(action);

    return true;
}

bool IFileBrowser::delStrategy(const QString& name)
{
    if (!strategies.contains(name)) return false;

    strategies.value(name)->delObserver(this);
    strategies.remove(name);

    foreach (QAction* action, group->actions())
        if (action->text() == name) {
            group->removeAction(action);
            break;
        }

    return true;
}

bool IFileBrowser::setStatus(IFileBrowser* fileBrowser)
{
    foreach (const QString& key, strategies.keys())
        if (strategies.value(key) == fileBrowser->currentMapper) {
            currentMapper = fileBrowser->currentMapper;
            return true;
        }

    return false;
}

void IFileBrowser::selectionChanged(const QItemSelection& selected, const QItemSelection& deselected)
{
    Q_UNUSED(deselected);
    rootDirPath = fileSystemModel->filePath(selected.constFirst().indexes().constFirst());
    if (currentMapper) currentMapper->getSizesMap(rootDirPath);
}

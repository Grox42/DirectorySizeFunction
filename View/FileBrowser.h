#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include "Strategies/ISizeMapper.h"
#include "Observer/Observer.h"
#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeView>
#include <QMenuBar>

class FileBrowser : public QMainWindow, public Observer
{
    Q_OBJECT
protected:
    QFileSystemModel* fileSystemModel = nullptr;
    QTreeView* fileSystemView = nullptr;
    QMenu* group = nullptr;
    QString rootDirPath;
    ISizeMapper* currentMapper = nullptr;
    QMap<QString, ISizeMapper*> strategies;
public:
    FileBrowser(const QString& rootDirPath, QWidget* parent = nullptr);
    virtual void updateDisplay(const QMap<QString, quint64>& sizesMap) = 0;
    bool addStrategy(const QString& name, ISizeMapper* mapper);
    bool delStrategy(const QString& name);
    bool setStatus(FileBrowser* fileBrowser);
private slots:
    void selectionChanged(const QItemSelection& selected, const QItemSelection& deselected);
};

#endif // FILEBROWSER_H

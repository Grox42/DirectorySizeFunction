#ifndef IFILEBROWSER_H
#define IFILEBROWSER_H

#include "Strategies/ISizeMapper.h"
#include "Observer/IObserver.h"
#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeView>
#include <QMenuBar>

class IFileBrowser : public QMainWindow, public IObserver
{
    Q_OBJECT
private:
    QFileSystemModel* fileSystemModel = nullptr;
    QTreeView* fileSystemView = nullptr;
    QMenu* group = nullptr;
    QString rootDirPath;
    ISizeMapper* currentMapper = nullptr;
    QMap<QString, ISizeMapper*> strategies;
public:
    IFileBrowser(const QString& rootDirPath, QWidget* parent = nullptr);
    virtual void updateDisplay(const QMap<QString, quint64>& sizesMap) = 0;
    bool addStrategy(const QString& name, ISizeMapper* mapper);
    bool delStrategy(const QString& name);
    bool setStatus(IFileBrowser* fileBrowser);
private slots:
    void selectionChanged(const QItemSelection& selected, const QItemSelection& deselected);
};

#endif // IFILEBROWSER_H

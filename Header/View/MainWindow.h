#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Header/Models/FileBrowserModel.h"
#include "Header/Strategy/DirSizeMapper.h"
#include "Header/Strategy/TypeSizeMapper.h"
#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTableView>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QFileSystemModel* fileSystemModel = nullptr;
    FileBrowserModel* dirModel = nullptr;
    QTreeView* fileSystemView = nullptr;
    QTableView* dirView = nullptr;
    QList<ISizeMapper*> strategies { new DirSizeMapper(), new TypeSizeMapper() };
public:
    MainWindow(const QString& rootDirPath, QWidget* parent = nullptr);
    ~MainWindow();
private slots:
    void selectionChanged(const QItemSelection& selected, const QItemSelection& deselected);
    void setGroupByDir();
    void setGroupByType();
    //void setTable();
    //void setBarChart();
    //void setPieChart();
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Header/Models/FileBrowserModel.h"
#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTableView>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QFileSystemModel* fileSystemModel;
    FileBrowserModel* dirModel;
    QTreeView* fileSystemView;
    QTableView* dirView;
public:
    MainWindow(const QString& rootDirPath, QWidget* parent = nullptr);
private slots:
    void setGroupByDir() const;
    void setGroupByType() const;
};

#endif // MAINWINDOW_H

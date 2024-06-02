#include <QApplication>
#include "Header/View/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWindow("D:/Programming/Qt");
    mainWindow.show();

    return a.exec();
}

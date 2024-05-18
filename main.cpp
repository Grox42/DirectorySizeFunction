#include <QCoreApplication>
#include <QString>
#include <QPair>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDebug>

enum class Group
{
    ByFolders, ByTypes
};

qint64 getSizeEntry(const QFileInfo &fileInfo)
{
    if (fileInfo.isDir()) {
        QDir dir = fileInfo.dir();
        dir.cd(fileInfo.fileName());

        qint64 sum = 0;
        foreach (QFileInfo entry, dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot))
            sum += getSizeEntry(entry);

        return sum;
    } else return fileInfo.size();
}

QPair<QString, qint64> getDirInfo(const QDir &dir, Group group)
{
    switch (group) {
        case Group::ByFolders: return QPair<QString, qint64>(dir.path(), getSizeEntry(QFileInfo(dir.path())));
        case Group::ByTypes:

            return QPair<QString, qint64>();
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir rootDir("Dir");

    qDebug() << getDirInfo(rootDir, Group::ByFolders);

    return a.exec();
}

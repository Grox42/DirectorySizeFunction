QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Source/Models/FileBrowserModel.cpp \
    MainWindow.cpp \
    Context.cpp \
    Source/Strategy/DirSizeMapper.cpp \
    Source/Strategy/ISizeMapper.cpp \
    Source/Strategy/TypeSizeMapper.cpp \
    main.cpp

HEADERS += \
    Header/Models/FileBrowserModel.h \
    MainWindow.h \
    Context.h \
    Header/Strategy/DirSizeMapper.h \
    Header/Strategy/ISizeMapper.h \
    Header/Strategy/TypeSizeMapper.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


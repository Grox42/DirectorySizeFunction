QT += core gui
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    View/Adapters/PieChartAdapter.cpp \
    View/Adapters/BarChartAdapter.cpp \
    View/Adapters/TableChartAdapter.cpp \
    View/FileBrowser.cpp \
    Charts/PieChart.cpp \
    Charts/BarChart.cpp \
    Charts/IChart.cpp \
    Observer/Observable.cpp \
    Models/FileBrowserModel.cpp \
    Strategies/TypeSizeMapper.cpp \
    Strategies/DirSizeMapper.cpp \
    Strategies/ISizeMapper.cpp \
    main.cpp

HEADERS += \
    View/Adapters/PieChartAdapter.h \
    View/Adapters/BarChartAdapter.h \
    View/Adapters/TableChartAdapter.h \
    View/FileBrowser.h \
    Charts/PieChart.h \
    Charts/BarChart.h \
    Charts/IChart.h \
    Observer/Observer.h \
    Observer/Observable.h \
    Models/FileBrowserModel.h \
    Strategies/TypeSizeMapper.h \
    Strategies/DirSizeMapper.h \
    Strategies/ISizeMapper.h
	

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


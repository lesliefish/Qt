#-------------------------------------------------
#
# Project created by QtCreator 2017-10-19T18:28:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Main
TEMPLATE = app

INCLUDEPATH += src/UI\
    src/PublicGUI\

SOURCES += \
    src/UI/MainWindow/mainwindow.cpp \
    src/PublicGUI/FramelessWidget/framelesswidget.cpp \
    src/UI/WarningDlg/warningdlg.cpp \
    src/UI/About/aboutdlg.cpp \
    src/main.cpp

HEADERS  += \
    src/UI/MainWindow/mainwindow.h \
    src/PublicGUI/FramelessWidget/framelesswidget.h \
    src/UI/WarningDlg/warningdlg.h \
    src/UI/About/aboutdlg.h

FORMS    += \
    src/UI/MainWindow/mainwindow.ui \
    src/PublicGUI/FramelessWidget/framelesswidget.ui \
    src/UI/WarningDlg/warningdlg.ui \
    src/UI/About/aboutdlg.ui

DISTFILES += \
    main.qss \
    res/main.qss

RESOURCES += \
    res/main.qrc

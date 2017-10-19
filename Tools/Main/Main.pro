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

SOURCES += main.cpp \
    src/UI/MainWindow/mainwindow.cpp

HEADERS  += \
    src/UI/MainWindow/mainwindow.h

FORMS    += \
    src/UI/MainWindow/mainwindow.ui

DISTFILES += \
    main.qss

QT += core axcontainer
QT -= gui

CONFIG += c++11

TARGET = QtExcel
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ExcelManger.cpp

HEADERS += \
    ExcelManger.h

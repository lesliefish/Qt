QT += core
QT -= gui

CONFIG += c++11

TARGET = QThreadPool
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    printtask.cpp

HEADERS += \
    printtask.h

QT += core
QT -= gui

TARGET = MyOwnHeap
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    chunk.cpp

HEADERS += \
    chunk.h


#-------------------------------------------------
#
# Project created by QtCreator 2016-11-19T08:22:27
#
#-------------------------------------------------

QT       -= gui

TARGET = ParadisEO
TEMPLATE = lib
CONFIG += staticlib

SOURCES += paradiseo.cpp

HEADERS += paradiseo.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

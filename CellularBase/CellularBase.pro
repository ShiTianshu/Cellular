#-------------------------------------------------
#
# Project created by QtCreator 2014-10-16T19:43:08
#
#-------------------------------------------------

QT       -= gui

TARGET = CellularBase
TEMPLATE = lib
CONFIG += staticlib

SOURCES +=

HEADERS += \
    cellular_ipc.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

DESTDIR = $$(MYIM_HOME)/lib

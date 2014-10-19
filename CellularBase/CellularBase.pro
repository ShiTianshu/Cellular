#-------------------------------------------------
#
# Project created by QtCreator 2014-10-16T19:43:08
#
#-------------------------------------------------

QT       -= gui

TARGET = CellularBase
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    cellular_module.cpp \
    cellular_common.cpp \
    cellular_engine.cpp

HEADERS += \
    cellular_ipc.h \
    cellular_common.h \
    cellular_exception.h \
    cellular_module.h \
    cellular_service.h \
    cellular_engine.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

DESTDIR = $$(MYIM_HOME)/lib

#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T22:42:19
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CellularServer
TEMPLATE = app


SOURCES += main.cpp \
    cellularserver.cpp

HEADERS  += \
    cellularserver.h

LIBS += -L $$(MYIM_HOME)/lib -lCellularBase

DESTDIR = $$(MYIM_HOME)/bin

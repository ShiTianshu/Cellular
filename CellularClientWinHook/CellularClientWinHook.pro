#-------------------------------------------------
#
# Project created by QtCreator 2014-10-16T20:14:24
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CellularClientWinHook
TEMPLATE = app


SOURCES += main.cpp \
    hook_cilent.cpp

HEADERS  += \
    hook_client.h

DESTDIR = $$(MYIM_HOME)/bin

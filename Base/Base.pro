#-------------------------------------------------
#
# Project created by QtCreator 2014-10-23T20:34:05
#
#-------------------------------------------------

QT       -= gui

TARGET = Base
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    iprocessor.cpp \
    imodule.cpp \
    isource.cpp \
    engine.cpp \
    inputmethod.cpp \
    service.cpp \
    exceptions.cpp

HEADERS += \
    iprocessor.h \
    imodule.h \
    isource.h \
    engine.h \
    common.h \
    inputmethod.h \
    service.h \
    exceptions.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

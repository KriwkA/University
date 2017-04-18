#-------------------------------------------------
#
# Project created by QtCreator 2016-04-13T23:46:17
#
#-------------------------------------------------

QT       -= gui

TARGET = RIS
TEMPLATE = lib

DEFINES += RIS_LIBRARY

SOURCES += RIS.cpp

HEADERS += RIS.h\
        ris_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

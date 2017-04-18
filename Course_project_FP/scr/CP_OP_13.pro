#-------------------------------------------------
#
# Project created by QtCreator 2015-12-07T09:45:38
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = CP_OP_13
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    Data.cpp \
    Factory.cpp \
    FactoryesData.cpp \
    Tree.cpp \
    Vector.cpp \
    Worker.cpp \
    WorkersData.cpp \
    workerdialog.cpp \
    searchdialog.cpp

HEADERS  += mainwindow.h \
    Data.h \
    Factory.h \
    FactoryesData.h \
    macro.h \
    Tree.h \
    Vector.h \
    Worker.h \
    WorkersData.h \
    workerdialog.h \
    searchdialog.h

FORMS += \
    workerdialog.ui \
    searchdialog.ui

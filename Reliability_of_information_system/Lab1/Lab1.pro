QT += core
QT -= gui

CONFIG += c++11

TARGET = Lab1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS +=

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../RIS/release/ -lRIS
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../RIS/debug/ -lRIS
else:unix: LIBS += -L$$OUT_PWD/../RIS/ -lRIS

INCLUDEPATH += $$PWD/../RIS
DEPENDPATH += $$PWD/../RIS

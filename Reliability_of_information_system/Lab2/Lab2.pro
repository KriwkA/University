TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../RIS/release/ -lRIS
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../RIS/debug/ -lRIS
else:unix: LIBS += -L$$OUT_PWD/../RIS/ -lRIS

INCLUDEPATH += $$PWD/../RIS
DEPENDPATH += $$PWD/../RIS

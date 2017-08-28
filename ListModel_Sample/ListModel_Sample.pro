#TEMPLATE = app

QT += qml quick
CONFIG += c++11

#CONFIG += qtquickcompiler

SOURCES += main.cpp \
    mytestclass.cpp \
    model/model.cpp \
    dataobject.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
#include(deployment.pri)

HEADERS += \
    mytestclass.h \
    model/model.h \
    dataobject.h

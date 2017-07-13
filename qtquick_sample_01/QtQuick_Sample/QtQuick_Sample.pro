#TEMPLATE = app

QT += qml quick
CONFIG += c++11

CONFIG += qtquickcompiler

# QMAKE_CXXFLAGS += -m32
# QMAKE_CFLAGS += -m32

SOURCES += main.cpp \
    mytestclass.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
#include(deployment.pri)

HEADERS += \
    mytestclass.h


QT += qml quick

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

INCLUDEPATH += ViewModel
INCLUDEPATH += Model

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp

HEADERS += \
    ViewModel/MainViewModel.h \
    Model/MainModel.h

DISTFILES += \
    qml/Controls/Button.qml \
    qml/Controls/TextBox.qml \
    qml/MainView.qml

RESOURCES += \
    qml.qrc

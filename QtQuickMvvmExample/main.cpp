#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include "MainViewModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView viewer;

    MainModel mainModel;

    viewer.rootContext()->setContextProperty("model", new MainViewModel(mainModel));
    viewer.setSource(QUrl("qrc:/qml/MainView.qml"));
    viewer.show();

    return app.exec();
}

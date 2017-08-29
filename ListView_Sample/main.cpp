#include <QGuiApplication>
#include <QQmlContext>
#include <QQuickView>
#include "mytestclass.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView viewer;

    MyTestClass * const mytest = new MyTestClass();

    viewer.rootContext()->setContextProperty("mytest", mytest);
    viewer.rootContext()->setContextProperty("myModel", QVariant::fromValue(mytest->m_dataList));

    viewer.setSource(QUrl("qrc:/qml/main.qml"));
    viewer.show();

    return app.exec();
}

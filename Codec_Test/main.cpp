#include <QGuiApplication>
#include <QtQml>
#include <QQuickView>
#include <QFont>

#include "codec_test.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView viewer;

    Codec_Test * const myCodecTest = new Codec_Test(&viewer);

    viewer.rootContext()->setContextProperty("myCodecTest", myCodecTest);
    viewer.setSource(QUrl("qrc:/main.qml"));

    viewer.show();

    return app.exec();
}

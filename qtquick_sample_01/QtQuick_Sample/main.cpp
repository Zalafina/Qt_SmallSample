#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>
//#include <QQuickView>
#include "mytestclass.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    //QQuickView viewer;

    QQmlApplicationEngine engine;

    MyTestClass * const mytest = new MyTestClass();

    engine.rootContext()->setContextProperty("mytest", mytest);

    // Move to a sub thread
    QThread * const appThread = new QThread();
    mytest->moveToThread(appThread);
    appThread->setObjectName("MyTestClass SubThread");
    static_cast<void>(QObject::connect(appThread, SIGNAL(started()), mytest, SLOT(threadStarted())));
    appThread->start();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //viewer.setSource(QUrl("qrc:/main.qml"));
    //viewer.show();

    qDebug("Main Thread ID:0x%08X", QThread::currentThreadId());

    return app.exec();
}

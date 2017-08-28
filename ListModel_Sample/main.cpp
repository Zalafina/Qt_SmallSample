#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>
#include <QQuickView>
#include "mytestclass.h"

#define USE_QQUICK_VIEW  (1)
//#define USE_QQMLAPPLICATION_ENGINE  (1)

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

#ifdef USE_QQUICK_VIEW
    QQuickView viewer;
#else
    QQmlApplicationEngine viewer;
#endif

    MyTestClass * const mytest = new MyTestClass();

#ifdef USE_QQUICK_VIEW
    viewer.rootContext()->setContextProperty("mytest", mytest);
    viewer.rootContext()->setContextProperty("myModel", QVariant::fromValue(mytest->m_dataList));
#else
    viewer.rootContext()->setContextProperty("mytest", mytest);
#endif

    // Move to a sub thread
//    QThread * const appThread = new QThread();
//    mytest->moveToThread(appThread);
//    appThread->setObjectName("MySubThread");
//    appThread->start();

#ifdef USE_QQUICK_VIEW
    viewer.setSource(QUrl("qrc:/qml/main.qml"));
    //viewer.setSource(QUrl("qrc:/qml/gridview-example.qml"));
    viewer.show();
#else
    viewer.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
#endif

    qDebug("Main Thread ID:0x%08X", (unsigned int)(QThread::currentThreadId()));

    return app.exec();
}

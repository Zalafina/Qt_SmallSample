#include "codec_test.h"

Codec_Test::Codec_Test(QQuickView *viewer, QObject *parent) :
    QObject(parent)
  , m_Viewer(viewer)
{
    qDebug() <<"AvailableCodecs List Start";
    for(auto codec : QTextCodec::availableCodecs()){
        qDebug().noquote() << codec;
    }
    qDebug() <<"AvailableCodecs List End";

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(timeOutUpdateString()));
    m_timer->start(1000);
}

void Codec_Test::timeOutUpdateString(void)
{
    QQuickItem * item = m_Viewer->rootObject();

    QList<QQuickItem *> itemList = item->childItems();

    QObject *text = item->findChild<QObject *>("qmlTestText");
    if(text != NULL) {
        QString timeString = QTime::currentTime().toString("hh:mm:ss.zzz");
        text->setProperty("text", timeString);
    }
    else{
        qDebug("qmlTestText has not been found");
    }
}

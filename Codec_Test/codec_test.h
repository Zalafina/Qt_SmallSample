#ifndef CODEC_TEST_H
#define CODEC_TEST_H

#include <QObject>
#include <QTextCodec>
#include <QList>
#include <QTimer>
#include <QTime>
#include <QQuickView>
#include <QQuickItem>

class Codec_Test : public QObject
{
    Q_OBJECT
public:
    explicit Codec_Test(QQuickView * viewer, QObject *parent = 0);

signals:

public slots:
    void timeOutUpdateString(void);

private:
    QTimer *m_timer;
    QQuickView * m_Viewer;
};

#endif // CODEC_TEST_H

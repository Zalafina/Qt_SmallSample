#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QObject>
#include <QProcess>
#include <QDebug>

class workerThread : public QObject
{
    Q_OBJECT
public:
    explicit workerThread(QObject *parent = nullptr);
    ~workerThread();

signals:
    void senddata_sign(QString);

public slots:
    void readSlot();
    void writeSlot(QString strWrite);
    void IniConsoleThreadSlot();

private:
    QProcess *consoleProcess;
};

#endif // WORKERTHREAD_H

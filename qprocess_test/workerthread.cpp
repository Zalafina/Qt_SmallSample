#include "workerthread.h"

static const qint64 READ_LEN_MAX  = 8192;

workerThread::workerThread(QObject *parent) : QObject(parent)
{

}

workerThread::~workerThread()
{
    consoleProcess->close();

    delete consoleProcess;

    consoleProcess = Q_NULLPTR;
    qDebug() << "consoleProcess End";

}

void workerThread::readSlot()
{
    while(consoleProcess->canReadLine())
    {
        char console_output[READ_LEN_MAX+1];
        qint64 readlineLength = consoleProcess->readLine(console_output, READ_LEN_MAX);
        if (readlineLength != -1) {
            QString tmpstr = QString::fromLocal8Bit(console_output);
            emit senddata_sign(tmpstr);
        }
    }
}

void workerThread::writeSlot(QString strWrite)
{
    qDebug() << "WriteCMD:" << strWrite.toStdString().c_str();
    QByteArray writeBArray = strWrite.toStdString().c_str();
    consoleProcess->write(writeBArray.constData());
    consoleProcess->waitForBytesWritten(2000);
}

void workerThread::IniConsoleThreadSlot()
{
    qDebug() << "IniConsoleThreadSlot()";
    consoleProcess = new QProcess(this);
    consoleProcess->setProcessChannelMode(QProcess::MergedChannels);
    QObject::connect(consoleProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(readSlot()));
    consoleProcess->start("D:/mytest.bat");
    if (!consoleProcess->waitForStarted())
        qDebug() << "Started failed:" << consoleProcess->errorString();
    else
    {
        qDebug() << "Console Process Started:";
        qDebug() << consoleProcess->readAll();
    }
}

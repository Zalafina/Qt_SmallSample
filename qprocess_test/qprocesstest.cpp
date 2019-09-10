#include "qprocesstest.h"
#include "ui_qprocesstest.h"

QProcessTest::QProcessTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QProcessTest),
    m_worker(Q_NULLPTR),
    m_workerthread(Q_NULLPTR)
{
    ui->setupUi(this);

    m_worker = new workerThread();
    m_workerthread = new QThread();
    m_worker->moveToThread(m_workerthread);
    connect(this, &QProcessTest::IniConsoleThread_sign, m_worker, &workerThread::IniConsoleThreadSlot);
    connect(m_workerthread,&QThread::finished, m_worker, &QObject::deleteLater);

    connect(this, &QProcessTest::write_sign, m_worker, &workerThread::writeSlot);
    connect(this, &QProcessTest::read_sign, m_worker, &workerThread::readSlot);
    connect(m_worker, &workerThread::senddata_sign, this, &QProcessTest::getdata_slot);
    connect(this, &QProcessTest::sendcmd_sign, m_worker, &workerThread::writeSlot);
    connect(this, &QProcessTest::attach_cmdwindow_sign, m_worker, &workerThread::attachConsoleSlot);

    m_workerthread->start();
    emit IniConsoleThread_sign();
    emit read_sign();
}

QProcessTest::~QProcessTest()
{
    delete ui;

    emit sendcmd_sign("exit\r\n");
    m_workerthread->quit();
    m_workerthread->wait();
}

void QProcessTest::on_pushButton_clicked()
{
    QString str_cmd = ui->lineEdit->text() + "\r\n";
    emit sendcmd_sign(str_cmd);
}

void QProcessTest::getdata_slot(QString info)
{
    qDebug() << info;
}

void QProcessTest::on_pushButton_2_clicked()
{
    if (false == ui->lineEdit->text().isEmpty()){
        QString pid_str = ui->lineEdit->text();
        bool check = false;
        quint64 pid = pid_str.toULong(&check);
        if (true == check){
            emit attach_cmdwindow_sign(pid);
        }
    }
}

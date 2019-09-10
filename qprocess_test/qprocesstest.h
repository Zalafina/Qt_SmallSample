#ifndef QPROCESSTEST_H
#define QPROCESSTEST_H

#include <QWidget>
#include <QThread>
#include "workerthread.h"

namespace Ui {
class QProcessTest;
}

class QProcessTest : public QWidget
{
    Q_OBJECT

public:
    explicit QProcessTest(QWidget *parent = nullptr);
    ~QProcessTest();

signals:
    void IniConsoleThread_sign();
    void read_sign();
    void write_sign(QString writedata);
    void sendcmd_sign(QString cmd);
    void attach_cmdwindow_sign(quint64 pid);

private slots:
    void on_pushButton_clicked();
    void getdata_slot(QString info);

    void on_pushButton_2_clicked();

private:
    Ui::QProcessTest *ui;
    workerThread *m_worker;
    QThread *m_workerthread;
};

#endif // QPROCESSTEST_H

#include <QDebug>
#include "qpushbutton_test.h"
#include "ui_qpushbutton_test.h"

QPushButton_Test::QPushButton_Test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QPushButton_Test)
{
    ui->setupUi(this);

    connect(ui->pushButtonA, &MyPushButton::enableStatusChanged, this, &QPushButton_Test::buttonStatusChangedProc);
    connect(ui->pushButtonB, &MyPushButton::enableStatusChanged, this, &QPushButton_Test::buttonStatusChangedProc);
    connect(ui->pushButtonC, &MyPushButton::enableStatusChanged, this, &QPushButton_Test::buttonStatusChangedProc);
}

QPushButton_Test::~QPushButton_Test()
{
    delete ui;
}

void QPushButton_Test::buttonStatusChangedProc(bool status, quint32 buttonindex)
{
    qDebug() << "ButtonIndex:" << buttonindex << "Status:" << status;

    if (false == status){
        ui->pushButtonA->setEnabled(false);
        ui->pushButtonB->setEnabled(false);
        ui->pushButtonC->setEnabled(false);
    }
    else{
        ui->pushButtonA->setEnabled(true);
        ui->pushButtonB->setEnabled(true);
        ui->pushButtonC->setEnabled(true);
    }
}

void QPushButton_Test::on_ButtonEnableA_stateChanged(int state)
{
    if (Qt::Unchecked == state){
        ui->pushButtonA->setEnabled(false);
    }
    else {
        ui->pushButtonA->setEnabled(true);
    }
}

void QPushButton_Test::on_ButtonEnableB_stateChanged(int state)
{
    if (Qt::Unchecked == state){
        ui->pushButtonB->setEnabled(false);
    }
    else {
        ui->pushButtonB->setEnabled(true);
    }
}

void QPushButton_Test::on_ButtonEnableC_stateChanged(int state)
{
    if (Qt::Unchecked == state){
        ui->pushButtonC->setEnabled(false);
    }
    else {
        ui->pushButtonC->setEnabled(true);
    }
}

#include "qpushbutton_test.h"
#include "ui_qpushbutton_test.h"

QPushButton_Test::QPushButton_Test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QPushButton_Test)
{
    ui->setupUi(this);
}

QPushButton_Test::~QPushButton_Test()
{
    delete ui;
}

void QPushButton_Test::on_ButtonEnableA_stateChanged(int arg1)
{

//    Qt::Unchecked

//    Qt::Checked
}

void QPushButton_Test::on_ButtonEnableB_stateChanged(int arg1)
{

}

void QPushButton_Test::on_ButtonEnableC_stateChanged(int arg1)
{

}

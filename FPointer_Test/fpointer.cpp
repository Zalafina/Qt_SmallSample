#include "fpointer.h"
#include "ui_fpointer.h"

FPointer::FPointer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FPointer)
{
    ui->setupUi(this);
}

FPointer::~FPointer()
{
    delete ui;
}

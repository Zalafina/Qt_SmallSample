#include "fpointer.h"
#include "ui_fpointer.h"

FPointer::FPointer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FPointer)
{
    ui->setupUi(this);
    m_fpmap = new FPMap(this);
    m_fpmap->start();
}

FPointer::~FPointer()
{
    delete ui;
    delete m_fpmap;
}

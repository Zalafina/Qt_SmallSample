#include "mfiledialog_sample.h"
#include "ui_mfiledialog_sample.h"
#include "mfiledialog.h"

MFileDialog_Sample::MFileDialog_Sample(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MFileDialog_Sample)
{
    ui->setupUi(this);
}

MFileDialog_Sample::~MFileDialog_Sample()
{
    delete ui;
}

void MFileDialog_Sample::on_mfileDialogButton_clicked()
{
    MFileDialog fileDialog;
    if (fileDialog.exec() == QDialog::Accepted)
    {
         for(const QString &filename : fileDialog.selectedFiles()){
            qDebug().noquote() << filename;
         }
    }
}

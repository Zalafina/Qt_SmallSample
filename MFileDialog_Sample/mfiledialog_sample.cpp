#include "mfiledialog_sample.h"
#include "ui_mfiledialog_sample.h"
#include "mfiledialog.h"

#ifdef OUT_ALL_ENTRYS_OF_DIR
QFileInfoList GetFileList(QString path)
{
    QFileInfoList final_list;
    QDir dir(path);
    dir.setSorting(QDir::IgnoreCase | QDir::DirsFirst | QDir::Name);
    QFileInfoList fileinfolist = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot| QDir::CaseSensitive | QDir::Files | QDir::Hidden | QDir::System);

    for (const QFileInfo &fileinfo : fileinfolist){
        final_list.append(fileinfo);

        if (true == fileinfo.isDir()){
            QFileInfoList child_file_list = GetFileList(fileinfo.absoluteFilePath());
            final_list.append(child_file_list);
        }
    }

    return final_list;
}
#endif

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
        QStringList selected_files = fileDialog.selectedFiles();
        selected_files.sort(Qt::CaseInsensitive);
        for(const QString &filename : selected_files){
            QFileInfo fileinfo_ori(filename);
            QString property;
            if (true == fileinfo_ori.isDir()){
                property = "Dir  |";
            }
            else{
                property = "File |";
            }
            qDebug().noquote() << QString("%1 %2").arg(property).arg(filename);

#ifdef OUT_ALL_ENTRYS_OF_DIR
            QFileInfo fileinfo(filename);
            if (true == fileinfo.isDir()){
                QFileInfoList list = GetFileList(filename);

                for (const QFileInfo &finfo : list){
                    if (true == finfo.isDir()){
                        property = "Dir  |";
                    }
                    else{
                        property = "File |";
                    }
                    qDebug().noquote() << QString("%1 %2").arg(property).arg(finfo.absoluteFilePath());
                }
            }
#endif
        }
    }
}

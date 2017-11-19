#ifndef LINKREADER_H
#define LINKREADER_H

#include <QDialog>
#include <QFileDialog>
#include <QDebug>
#include <windows.h>
#include <shobjidl.h>
#include <shlguid.h>
#include <strsafe.h>

namespace Ui {
class LinkReader;
}

class LinkReader : public QDialog
{
    Q_OBJECT

public:
    explicit LinkReader(QWidget *parent = 0);
    ~LinkReader();

private slots:
    void on_readlinkButton_clicked();

private:
    Ui::LinkReader *ui;
};

#endif // LINKREADER_H

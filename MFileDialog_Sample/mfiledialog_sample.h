#ifndef MFILEDIALOG_SAMPLE_H
#define MFILEDIALOG_SAMPLE_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class MFileDialog_Sample;
}

class MFileDialog_Sample : public QDialog
{
    Q_OBJECT

public:
    explicit MFileDialog_Sample(QWidget *parent = 0);
    ~MFileDialog_Sample();

private slots:
    void on_mfileDialogButton_clicked();

private:
    Ui::MFileDialog_Sample *ui;
};

#endif // MFILEDIALOG_SAMPLE_H

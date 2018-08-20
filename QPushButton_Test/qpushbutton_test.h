#ifndef QPUSHBUTTON_TEST_H
#define QPUSHBUTTON_TEST_H

#include <QDialog>

namespace Ui {
class QPushButton_Test;
}

class QPushButton_Test : public QDialog
{
    Q_OBJECT

public:
    explicit QPushButton_Test(QWidget *parent = 0);
    ~QPushButton_Test();

private slots:
    void buttonStatusChangedProc(bool status, quint32 buttonindex);

    void on_ButtonEnableA_stateChanged(int state);

    void on_ButtonEnableB_stateChanged(int state);

    void on_ButtonEnableC_stateChanged(int state);

private:
    Ui::QPushButton_Test *ui;
};

#endif // QPUSHBUTTON_TEST_H

#ifndef REGULARTEST_H
#define REGULARTEST_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class RegularTest;
}

class RegularTest : public QDialog
{
    Q_OBJECT

public:
    explicit RegularTest(QWidget *parent = 0);
    ~RegularTest();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RegularTest *ui;
};

#endif // REGULARTEST_H

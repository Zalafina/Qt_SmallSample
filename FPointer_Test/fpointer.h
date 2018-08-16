#ifndef FPOINTER_H
#define FPOINTER_H

#include <QDialog>

namespace Ui {
class FPointer;
}

class FPointer : public QDialog
{
    Q_OBJECT

public:
    explicit FPointer(QWidget *parent = 0);
    ~FPointer();

private:
    Ui::FPointer *ui;
};

#endif // FPOINTER_H

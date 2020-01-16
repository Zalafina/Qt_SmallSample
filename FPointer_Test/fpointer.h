#ifndef FPOINTER_H
#define FPOINTER_H

#include <QDialog>
#include "fpmap.h"

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
    FPMap *m_fpmap;
};

#endif // FPOINTER_H

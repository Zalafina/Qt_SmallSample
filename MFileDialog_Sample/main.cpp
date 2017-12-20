#include "mfiledialog_sample.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MFileDialog_Sample w;

    // Remove "?" Button from QDialog
    Qt::WindowFlags flags = Qt::Dialog;
    flags |= Qt::WindowCloseButtonHint;
    flags |= Qt::WindowMinimizeButtonHint;
    w.setWindowFlags(flags);

    w.show();

    return a.exec();
}

#include "fpointer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FPointer w;
    w.show();

    return a.exec();
}

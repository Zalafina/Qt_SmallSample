#include "regulartest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RegularTest w;
    w.show();

    return a.exec();
}

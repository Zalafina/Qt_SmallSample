#include "qprocesstest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QProcessTest w;
    w.show();

    return a.exec();
}

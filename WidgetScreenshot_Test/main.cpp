#include "screenshot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Screenshot w;
    w.show();

    return a.exec();
}

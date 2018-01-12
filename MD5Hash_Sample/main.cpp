#include "md5hashsample.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MD5HashSample w;
    w.show();

    return a.exec();
}

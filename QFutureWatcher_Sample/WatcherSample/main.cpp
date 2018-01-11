#include "watchersample.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WatcherSample w;
    w.show();

    union are
    {
        char a[9];
        short int b;
        double c;
    };
    are are_test;
    memset(&are_test, 0x00, sizeof(are_test));
    are_test.a[0] = 0x01;
    are_test.a[5] = 0x06;
    are_test.a[8] = 0x09;
    are_test.b = 0xAABB;
    are_test.c = 9.986;

    qDebug("union are: %d\n",sizeof(are_test));

    struct arew
    {
        char a[9];
        short int b;
        long int c;
        char e;
        union are d;
    };
    arew arew_test;
    memset(&arew_test, 0xFF, sizeof(arew_test));
    arew_test.a[0] = 0x01;
    arew_test.a[5] = 0x06;
    arew_test.a[8] = 0x09;
    arew_test.b = 0xAABB;
    arew_test.c = 0;
    arew_test.e = 0x36;
    arew_test.d.a[0] = 0x11;
    arew_test.d.a[5] = 0x16;
    arew_test.d.a[8] = 0x19;
    arew_test.d.b = 0xCCDD;
    arew_test.d.c = 257.986;
    qDebug("struct arew: %d\n",sizeof(arew_test));

    return a.exec();
}

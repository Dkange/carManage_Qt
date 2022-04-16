#include "mywindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWindow w;
    w.resize(720,640);
    w.show();
    return a.exec();
}

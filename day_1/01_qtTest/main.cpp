#include "mywidget.h"

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.setWindowTitle("*_*");
    QPushButton b1;
    b1.setText("^_^");
    b1.setParent(&w);
//    b1.show();
    b1.move(200,200);

    QPushButton b2(&w);
    b2.setText("^v^");
    b2.move(400,200);
    w.show();
    return a.exec();
}

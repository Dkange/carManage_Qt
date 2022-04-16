#include "widget.h"
#include "ui_widget.h"
#include <QBuffer>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QBuffer memFile;
    memFile.open(QIODevice::WriteOnly);

    memFile.write("sdgfeiewgefb iw");

    memFile.close();

    QString str = memFile.buffer();
    qDebug()<<str;
}

Widget::~Widget()
{
    delete ui;
}


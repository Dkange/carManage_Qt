#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QTextStream>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    writeData();
    readData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::writeData()
{
    QTextStream stm;
    QFile file;
    file.setFileName("../demo.txt");

    bool isOk = file.open(QIODevice::WriteOnly);

    if(isOk)
    {
        stm.setDevice(&file);

        stm << QString("测试一下")<<328;
        file.close();
    }

}
void Widget::readData()
{
    QTextStream stm;
    QFile file;
    file.setFileName("../demo.txt");

    bool isOk = file.open(QIODevice::ReadOnly);
    if(isOk)
    {
        stm.setDevice(&file);
        QString str;
        int num;
        stm >> str >> num;
        qDebug()<< str <<num;
    }
    file.close();

}

void Widget::on_writeData_clicked()
{
    QTextStream stm;
    QString path = QFileDialog::getOpenFileName(this,"Open","../");
    QFile file;
    file.setFileName(path);

    bool isOk = file.open(QIODevice::ReadOnly);

    if(isOk)
    {
        stm.setDevice(&file);

        QString str = stm.readAll();
        ui->textBrowser->setText(str);
        file.close();
    }
}

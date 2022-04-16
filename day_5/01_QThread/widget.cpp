#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    time = new QTimer(this);

    connect(time,&QTimer::timeout,this,&Widget::dis);
    connect(&thread,&MyThread::isDone,time,&QTimer::stop);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::dis()
{
    static int num = 0;
    num++;
    ui->lcdNumber->display(num);
}
void Widget::on_pushButton_clicked()
{
    if(time->isActive() == false)
    {
        time->start(100);
    }

    thread.start();
}

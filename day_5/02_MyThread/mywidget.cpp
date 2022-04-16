#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //动态分配空间
    myT = new Mythread;

    //创建子进程
    thread = new QThread(this);

    //将进程处理函数绑定到子进程
    myT->moveToThread(thread);

    connect(this,&MyWidget::myStart,myT,&Mythread::myTimer);
    connect(myT,&Mythread::myTimeout,this,&MyWidget::dis);

    qDebug()<<"主进程号： "<<QThread::currentThread();

    connect(this,&MyWidget::destroyed,this,&MyWidget::dealClose);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::dis()
{
    static int num = 0;
    ui->lcdNumber->display(num);
    num++;
}

void MyWidget::dealClose()
{
    on_buttonStop_clicked();
}

void MyWidget::on_buttonStart_clicked()
{
    if(thread->isRunning() == true)
    {
        return;
    }
    thread->start();
    myT->setFlag(false);
    emit myStart();
}

void MyWidget::on_buttonStop_clicked()
{
    if(thread->isRunning() == false)
    {
        return;
    }
    myT->setFlag(true);
    thread->quit();
    thread->wait();
}

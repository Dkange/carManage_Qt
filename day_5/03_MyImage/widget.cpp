#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    myT = new MyThread;

    thread = new QThread(this);

    myT->moveToThread(thread);

    thread->start();

    connect(ui->pushButton,&QPushButton::released,myT,&MyThread::drawImage);
    connect(myT,&MyThread::updataImage,this,&Widget::setImage);
    connect(this,&Widget::destroyed,this,&Widget::dealClose);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);//创建画家并指定窗口为绘图设备
    p.drawImage(50,50,image);
}

void Widget::setImage(QImage img)
{
    image = img;
    update();
}

void Widget::dealClose()
{
    thread->quit();

    thread->wait();

    delete myT;
}

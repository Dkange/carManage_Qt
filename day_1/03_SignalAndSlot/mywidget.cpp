#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setText("Close");
    b1.move(100,200);
    b1.setParent(this);

    b2 = new QPushButton(this);
    b2->setText(">_<");
    b2->move(300,200);

    connect(&b1,&QPushButton::pressed,this,&MyWidget::close);
    connect(b2,&QPushButton::released,this,&MyWidget::mySlot);
    connect(b2,&QPushButton::released,&b1,&QPushButton::hide);

    b3.setText("switch window");
    b3.setParent(this);
    b3.move(200,300);

    connect(&b3,&QPushButton::released,this,&MyWidget::changeWin);

    w.show();

    resize(500,500);
    void (SubWidget::*fp1)() = &SubWidget::mySignal;
    connect(&w,fp1,this,&MyWidget::changeAgn);
    void (SubWidget::*fp2)(int i,QString qs) = &SubWidget::mySignal;
    connect(&w,fp2,this,&MyWidget::testSlot);

    //lambda表达式
    b4 = new QPushButton(this);
    b4->setText("Lambda");
    b4->move(200,400);

    int a = 7;
    QString s = "clearlove";

    connect(b4,&QPushButton::clicked,
            [=]()//方括号内可以是 = & this
            {
                qDebug()<<s<<a;
            }
            );
}

void MyWidget::changeWin()
{
    w.show();
    this->hide();
}

void MyWidget::changeAgn()
{
    w.hide();
    this->show();
}

void MyWidget::testSlot(int i,QString qs)
{
    qDebug()<<"i = "<<i<<"Qstring = "<<qs<<endl;
}

void MyWidget::mySlot()
{
    b2->setText("<_>");
}

MyWidget::~MyWidget()
{
}


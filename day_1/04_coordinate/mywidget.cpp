#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    move(0,0);
    resize(500,500);
    QPushButton *b1 = new QPushButton(this);
    b1->setText("^_^");
    b1->resize(50,50);
    b1->move(250,250);

}

MyWidget::~MyWidget()
{
}


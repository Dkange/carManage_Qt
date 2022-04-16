#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    b.setText("Switch Window");
    b.setParent(this);
    b.move(200,300);
    resize(500,500);
    connect(&b,&QPushButton::released,this,&SubWidget::emSignl);
}

void SubWidget::emSignl()
{
    emit mySignal();
    emit mySignal(777,"Clearlove");
}

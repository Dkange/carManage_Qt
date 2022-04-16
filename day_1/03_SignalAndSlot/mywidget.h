#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QPushButton>
#include "subwidget.h"
#include <QDebug>
class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
    void mySlot();
    void changeWin();
    void changeAgn();
    void testSlot(int i,QString qs);
private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;
    QPushButton *b4;
    SubWidget w;
};
#endif // MYWIDGET_H

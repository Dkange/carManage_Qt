#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "mythread.h"
#include <QThread>
QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
    void dis();
    void dealClose();
private slots:
    void on_buttonStart_clicked();
    void on_buttonStop_clicked();

signals:
    void myStart();
private:
    Ui::MyWidget *ui;
    Mythread *myT;
    QThread *thread;
    bool flag;
};
#endif // MYWIDGET_H

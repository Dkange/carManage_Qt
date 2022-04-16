#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}
void MyThread::run()
{
    QThread thread;
    thread.sleep(5);

    emit isDone();
}

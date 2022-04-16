#include "mythread.h"

Mythread::Mythread(QObject *parent) : QObject(parent)
{

}

void Mythread::myTimer()
{
    if(isStop == false)
    {
        while(1)
        {
            QThread::sleep(1);
            emit myTimeout();
            qDebug()<<"子进程号： "<<QThread::currentThread();
            if(isStop == true)
                break;
        }
    }
}

void Mythread::setFlag(bool flag)
{
    isStop = flag;
}

#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
class Mythread : public QObject
{
    Q_OBJECT
public:
    explicit Mythread(QObject *parent = nullptr);

signals:
    void myTimeout();
public:
    void myTimer();
    void setFlag(bool flag);
private:
    bool isStop;
};

#endif // MYTHREAD_H

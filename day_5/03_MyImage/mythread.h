#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QImage>
#include <QObject>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

signals:
    void updataImage(QImage img);
public:
    void drawImage();
};

#endif // MYTHREAD_H

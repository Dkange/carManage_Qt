#include "mythread.h"
#include <QImage>
#include <QPainter>
#include <QPen>
#include <QBrush>
MyThread::MyThread(QObject *parent) : QObject(parent)
{

}

void MyThread::drawImage()
{
    QImage image(500,500,QImage::Format_ARGB32);

    QPainter p(&image);

    QPen pen;
    pen.setWidth(5);
    p.setPen(pen);
    QBrush brush;
    brush.setStyle(Qt::Dense2Pattern);
    brush.setColor(QColor(qrand()%255,qrand()%255,qrand()%255,qrand()%100));
    p.setBrush(brush);

    QPoint arr[5] = {
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500)
    };

    p.drawPolygon(arr,5);
    emit updataImage(image);
}

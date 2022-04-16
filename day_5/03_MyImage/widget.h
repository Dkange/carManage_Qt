#ifndef WIDGET_H
#define WIDGET_H
#include <QImage>
#include <QWidget>
#include <QThread>
#include "mythread.h"
#include <QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent *event) override;
    void setImage(QImage img);
    void dealClose();
private:
    Ui::Widget *ui;
    MyThread *myT;
    QImage image;
    QThread *thread;
};
#endif // WIDGET_H

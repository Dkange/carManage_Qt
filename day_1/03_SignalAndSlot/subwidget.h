#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    void emSignl();

signals:
    void mySignal();
    void mySignal(int i,QString qs);

private:
    QPushButton b;
};

#endif // SUBWIDGET_H

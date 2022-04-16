#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);

    QMenu *m = mBar->addMenu("对话框");

    QAction *a1 = m->addAction("模态");
    QAction *a2 = m->addAction("非模态");

    connect(a1,&QAction::triggered,
            [=]()
            {
                QDialog *d1 = new QDialog(this);
                d1->exec();
            }
            );
    connect(a2,&QAction::triggered,
            [=]()
            {
                QDialog *d2 = new QDialog(this);
                d2->setAttribute(Qt::WA_DeleteOnClose);
                d2->show();
            }
            );
    m->addSeparator();

    QAction *a3 = m->addAction("关于对话框");
    connect(a3,&QAction::triggered,
            [=]()
            {
                QMessageBox::about(this,"About","About Qt!");

            }
            );
    QAction *a4 = m->addAction("问题对话框");
    connect(a4,&QAction::triggered,
            [=]()
            {
                int ret = QMessageBox::question(this,"Question","Are you ok?");
                switch (ret)
                {
                    case QMessageBox::Yes:
                    qDebug()<<"I am ok!";
                    break;
                case QMessageBox::No:
                    qDebug()<<"No No No";
                    break;
                default:
                    break;
                }
            }
            );
    QAction *a5 = m->addAction("问题对话框");
    connect(a5,&QAction::triggered,
            [=]()
            {
                QString path = QFileDialog::getOpenFileName(this,"Open","../",
                                                            "source(*.cpp *.c *.h);;"
                                                            "text(*.txt *.html);  ;"
                                                            "all(*.*)");
                qDebug()<<path;
            }
            );
}

MainWindow::~MainWindow()
{
}


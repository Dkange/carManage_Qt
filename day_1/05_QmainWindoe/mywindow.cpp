#include "mywindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QDebug>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
MyWindow::MyWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 菜单栏
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    //菜单
    QMenu *mFile = mBar->addMenu("File");
    //菜单项
    QAction *pNew = mFile->addAction("New");
    //lambda表达式
    connect(pNew,&QAction::triggered,
            []()
            {
                qDebug()<<"Pressed New";
            }
            );
    QAction *pOpen = mFile->addAction("Open");
    mFile->addSeparator();
    QAction *pSave = mFile->addAction("Save");
    QAction *pSaveAs = mFile->addAction("SaveAs");
    //工具栏
    QToolBar *toolBar = addToolBar("Toolbar");

    //按钮
    QPushButton *b1 = new QPushButton(this);
    b1->setText("New");
    //添加按钮
    toolBar->addWidget(b1);

    //lambda表达式
    connect(b1,&QPushButton::released,
            [=]()
            {
                b1->setText("Open");
            }
            );

    //状态栏
    QStatusBar *Sbar = statusBar();
    QLabel *Lb1 = new QLabel(this);
    Lb1->setText("Type to locate");
    Sbar->addWidget(Lb1);
    QLabel *Lb2 = new QLabel(this);
    Lb2->setNum(1);
    Sbar->addPermanentWidget(Lb2);

    //核心控件
    QTextEdit *texE1 = new QTextEdit(this);
    setCentralWidget(texE1);

    //浮动窗口
    QDockWidget *Dow = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,Dow);

    QTextEdit *texE2 = new QTextEdit(this);
    Dow->setWidget(texE2);

}

MyWindow::~MyWindow()
{
}


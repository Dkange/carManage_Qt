/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QGridLayout *gridLayout;
    QLCDNumber *lcdNumber;
    QPushButton *buttonStart;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonStop;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(480, 320);
        gridLayout = new QGridLayout(MyWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lcdNumber = new QLCDNumber(MyWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        gridLayout->addWidget(lcdNumber, 0, 0, 1, 3);

        buttonStart = new QPushButton(MyWidget);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));

        gridLayout->addWidget(buttonStart, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(287, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        buttonStop = new QPushButton(MyWidget);
        buttonStop->setObjectName(QString::fromUtf8("buttonStop"));

        gridLayout->addWidget(buttonStop, 1, 2, 1, 1);


        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QCoreApplication::translate("MyWidget", "MyWidget", nullptr));
        buttonStart->setText(QCoreApplication::translate("MyWidget", "Start", nullptr));
        buttonStop->setText(QCoreApplication::translate("MyWidget", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H

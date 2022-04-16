/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCar;
    QAction *actionCalc;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *pageTitle;
    QSpacerItem *horizontalSpacer_2;
    QStackedWidget *stackedWidget;
    QWidget *car;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *sell;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *factory;
    QComboBox *comboBoxFactory;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *brand;
    QComboBox *comboBoxBrand;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *price;
    QLineEdit *lineEditPrice;
    QLabel *priceUnit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *count;
    QSpinBox *spinBoxCount;
    QLabel *remain;
    QLabel *remainNum;
    QHBoxLayout *horizontalLayout_5;
    QLabel *money;
    QLineEdit *lineEditMoney;
    QLabel *moneyUnit;
    QWidget *newcar;
    QTextBrowser *statistical;
    QWidget *calc;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionCar = new QAction(MainWindow);
        actionCar->setObjectName(QString::fromUtf8("actionCar"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        actionCar->setFont(font);
        actionCalc = new QAction(MainWindow);
        actionCalc->setObjectName(QString::fromUtf8("actionCalc"));
        actionCalc->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(324, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        pageTitle = new QLabel(centralwidget);
        pageTitle->setObjectName(QString::fromUtf8("pageTitle"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\261\211\344\273\252\347\273\274\350\211\272\344\275\223\347\256\200"));
        font1.setPointSize(22);
        pageTitle->setFont(font1);
        pageTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(pageTitle, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(324, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        car = new QWidget();
        car->setObjectName(QString::fromUtf8("car"));
        gridLayout_2 = new QGridLayout(car);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        splitter = new QSplitter(car);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        toolBox->setMinimumSize(QSize(280, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\345\205\211\347\273\274\350\211\272_CNKI"));
        toolBox->setFont(font2);
        sell = new QWidget();
        sell->setObjectName(QString::fromUtf8("sell"));
        sell->setGeometry(QRect(0, 0, 280, 430));
        gridLayout_3 = new QGridLayout(sell);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        factory = new QLabel(sell);
        factory->setObjectName(QString::fromUtf8("factory"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\215\216\345\205\211\346\267\241\345\217\244\345\215\260_CNKI"));
        factory->setFont(font3);

        horizontalLayout->addWidget(factory);

        comboBoxFactory = new QComboBox(sell);
        comboBoxFactory->setObjectName(QString::fromUtf8("comboBoxFactory"));

        horizontalLayout->addWidget(comboBoxFactory);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        brand = new QLabel(sell);
        brand->setObjectName(QString::fromUtf8("brand"));
        brand->setFont(font3);

        horizontalLayout_2->addWidget(brand);

        comboBoxBrand = new QComboBox(sell);
        comboBoxBrand->setObjectName(QString::fromUtf8("comboBoxBrand"));

        horizontalLayout_2->addWidget(comboBoxBrand);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        price = new QLabel(sell);
        price->setObjectName(QString::fromUtf8("price"));
        price->setFont(font3);

        horizontalLayout_3->addWidget(price);

        lineEditPrice = new QLineEdit(sell);
        lineEditPrice->setObjectName(QString::fromUtf8("lineEditPrice"));

        horizontalLayout_3->addWidget(lineEditPrice);

        priceUnit = new QLabel(sell);
        priceUnit->setObjectName(QString::fromUtf8("priceUnit"));
        priceUnit->setFont(font3);

        horizontalLayout_3->addWidget(priceUnit);


        gridLayout_3->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        count = new QLabel(sell);
        count->setObjectName(QString::fromUtf8("count"));
        count->setFont(font3);

        horizontalLayout_4->addWidget(count);

        spinBoxCount = new QSpinBox(sell);
        spinBoxCount->setObjectName(QString::fromUtf8("spinBoxCount"));

        horizontalLayout_4->addWidget(spinBoxCount);

        remain = new QLabel(sell);
        remain->setObjectName(QString::fromUtf8("remain"));
        remain->setFont(font3);

        horizontalLayout_4->addWidget(remain);

        remainNum = new QLabel(sell);
        remainNum->setObjectName(QString::fromUtf8("remainNum"));
        remainNum->setFont(font3);

        horizontalLayout_4->addWidget(remainNum);


        gridLayout_3->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        money = new QLabel(sell);
        money->setObjectName(QString::fromUtf8("money"));
        money->setFont(font3);

        horizontalLayout_5->addWidget(money);

        lineEditMoney = new QLineEdit(sell);
        lineEditMoney->setObjectName(QString::fromUtf8("lineEditMoney"));

        horizontalLayout_5->addWidget(lineEditMoney);

        moneyUnit = new QLabel(sell);
        moneyUnit->setObjectName(QString::fromUtf8("moneyUnit"));

        horizontalLayout_5->addWidget(moneyUnit);


        gridLayout_3->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        toolBox->addItem(sell, QString::fromUtf8("\345\207\272\345\224\256\350\275\246\350\276\206"));
        newcar = new QWidget();
        newcar->setObjectName(QString::fromUtf8("newcar"));
        newcar->setGeometry(QRect(0, 0, 280, 430));
        toolBox->addItem(newcar, QString::fromUtf8("\346\226\260\350\275\246\345\205\245\345\272\223"));
        splitter->addWidget(toolBox);
        statistical = new QTextBrowser(splitter);
        statistical->setObjectName(QString::fromUtf8("statistical"));
        splitter->addWidget(statistical);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);

        stackedWidget->addWidget(car);
        calc = new QWidget();
        calc->setObjectName(QString::fromUtf8("calc"));
        stackedWidget->addWidget(calc);

        gridLayout->addWidget(stackedWidget, 1, 0, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_2->setFont(font);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(actionCar);
        menu->addAction(actionCalc);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCar->setText(QCoreApplication::translate("MainWindow", "\350\275\246\350\276\206\347\256\241\347\220\206", nullptr));
        actionCalc->setText(QCoreApplication::translate("MainWindow", "\351\224\200\345\224\256\347\273\237\350\256\241", nullptr));
        pageTitle->setText(QCoreApplication::translate("MainWindow", "\350\275\246\350\276\206\347\256\241\347\220\206", nullptr));
        factory->setText(QCoreApplication::translate("MainWindow", "\345\216\202\345\256\266\357\274\232", nullptr));
        brand->setText(QCoreApplication::translate("MainWindow", "\345\223\201\347\211\214\357\274\232", nullptr));
        price->setText(QCoreApplication::translate("MainWindow", "\346\212\245\344\273\267\357\274\232", nullptr));
        priceUnit->setText(QCoreApplication::translate("MainWindow", "\344\270\207", nullptr));
        count->setText(QCoreApplication::translate("MainWindow", "\346\225\260\351\207\217\357\274\232", nullptr));
        remain->setText(QCoreApplication::translate("MainWindow", "\345\211\251\344\275\231\346\225\260\351\207\217\357\274\232", nullptr));
        remainNum->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        money->setText(QCoreApplication::translate("MainWindow", "\351\207\221\351\242\235\357\274\232", nullptr));
        moneyUnit->setText(QCoreApplication::translate("MainWindow", "\344\270\207", nullptr));
        toolBox->setItemText(toolBox->indexOf(sell), QCoreApplication::translate("MainWindow", "\345\207\272\345\224\256\350\275\246\350\276\206", nullptr));
        toolBox->setItemText(toolBox->indexOf(newcar), QCoreApplication::translate("MainWindow", "\346\226\260\350\275\246\345\205\245\345\272\223", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\351\241\265\351\235\242\347\256\241\347\220\206", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

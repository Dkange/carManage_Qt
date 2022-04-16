#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "domxml.h"
#include "plotseries.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //初始化默认页面为车辆管理
    on_actionCar_triggered();
    connectDB();//连接数据库
    initData();//初始化数据
    DomXML::creatXML("../test.xml");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCar_triggered()
{
    //切换到车辆管理页面
    ui->stackedWidget->setCurrentWidget(ui->car);
    //修改页面标题
    ui->pageTitle->setText("车辆管理");
}

void MainWindow::on_actionCalc_triggered()
{
    //切换到销售统计页面
    ui->stackedWidget->setCurrentWidget(ui->calc);
    //修改页面标题
    ui->pageTitle->setText("销售统计");

    QSqlQueryModel *model = new QSqlQueryModel(this);//创建模型

    model->setQuery("select name from factory");//通过模型执行数据库语句

    ui->comboBoxFactory_1->setModel(model);//使用UI显示模型
}

void MainWindow::connectDB()
{
    qDebug()<<QSqlDatabase::drivers();//打印所支持的数据库（本机只有64位编译有MYSQL）

    //打开数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");//添加数据库
    db.setHostName("127.0.0.1");//设置主机IP
    db.setUserName("root");//设置用户名
    db.setPassword("dangke");//设置密码
    db.setDatabaseName("car");//选定数据库

    if(!db.open())
    {
        QMessageBox::about(this,"error","打开数据库错误！");
        return;
    }
}

void MainWindow::initData()
{
    /* 数据库可视化操作
     * 通过Model-View模式
     * Model用于数据库操作，执行数据库语句（后端数据操作）
     * View用于显示Model（前端界面显示）
    */
    QSqlQueryModel *model = new QSqlQueryModel(this);//创建模型

    model->setQuery("select name from factory");//通过模型执行数据库语句

    ui->comboBoxFactory->setModel(model);//使用UI显示模型

    ui->remainNum->setText("0");

    ui->lineEditMoney->setEnabled(false);

    ui->ButtonSure->setEnabled(false);
}

void MainWindow::on_comboBoxFactory_currentIndexChanged(const QString &selectFactory)
{
    if(selectFactory == "请选择厂家")
    {
        ui->comboBoxBrand->clear();
        ui->lineEditPrice->clear();
        ui->spinBoxCount->setValue(0);
        ui->lineEditMoney->clear();
        ui->remainNum->setNum(0);
        ui->spinBoxCount->setEnabled(false);
    }
    else
    {
        ui->comboBoxBrand->clear();
        QSqlQuery query;
        QString sql = QString("select name from brand where factory = '%1'").arg(selectFactory);//获取
        query.exec(sql);//执行sql语句
        while(query.next())
        {
            QString name = query.value("name").toString();//获取所选项
            ui->comboBoxBrand->addItem(name);//添加条目
        }
    }
}

void MainWindow::on_comboBoxBrand_currentIndexChanged(const QString &selectBrand)
{
    QSqlQuery query;
    QString sql = QString("select price,last from brand where factory = '%1' and name = '%2'").arg(ui->comboBoxFactory->currentText()).arg(selectBrand);//获取
    query.exec(sql);//执行sql语句
    while(query.next())
    {
        int price = query.value("price").toInt();
        ui->lineEditPrice->setText(QString::number(price));
        int last = query.value("last").toInt();
        ui->remainNum->setNum(last);
    }
    ui->spinBoxCount->setEnabled(true);
}

void MainWindow::on_spinBoxCount_valueChanged(int num)
{
    if(num > 0)
        ui->ButtonSure->setEnabled(true);
    else
        ui->ButtonSure->setEnabled(false);
    QSqlQuery query;
    QString factoryStr = ui->comboBoxFactory->currentText();
    QString brandStr = ui->comboBoxBrand->currentText();

    //从数据库获取最新剩余数量
    QString sql = QString("select sum,last from brand where factory = '%1' and name = '%2'")
            .arg(factoryStr).arg(brandStr);

    query.exec(sql);
    int last;
    while(query.next())
    {
        last = query.value("last").toInt();
    }

    if(num > last)//如果数字越界
    {
        ui->spinBoxCount->setValue(last);//设定为最大值
        return;
    }
    //更新剩余数量
    int newLast = last - num;
    ui->remainNum->setNum(newLast);

    //计算总价
    int money = ui->lineEditPrice->text().toInt() * num;
    ui->lineEditMoney->setText(QString::number(money));
}



void MainWindow::on_ButtonCancel_clicked()
{
    ui->comboBoxFactory->setCurrentText("请选择厂家");//初始化
//    on_comboBoxFactory_currentIndexChanged("请选择厂家");
}


void MainWindow::on_ButtonSure_clicked()
{
    QSqlQuery query;
    QString sql = QString("select sell from brand where factory = '%1' and name = '%2'")
            .arg(ui->comboBoxFactory->currentText())
            .arg(ui->comboBoxBrand->currentText());

    query.exec(sql);


    int sell;
    while(query.next())
    {
        sell = query.value("sell").toInt();
    }

    int num = ui->spinBoxCount->value();//获取数量
    int last = ui->remainNum->text().toInt();//获取剩余量
    sell += num;//计算销量

    qDebug()<<sell;
    //更新数据库
    sql = QString("update brand set sell = %1,last = %2 where factory = '%3' and name = '%4'")
            .arg(sell)
            .arg(last)
            .arg(ui->comboBoxFactory->currentText())
            .arg(ui->comboBoxBrand->currentText());

    query.exec(sql);

    QStringList list;
    list<<ui->comboBoxFactory->currentText()
        <<ui->comboBoxBrand->currentText()
        <<ui->lineEditPrice->text()
        <<QString::number(num)
        <<ui->lineEditMoney->text();
    DomXML::appendXML("../test.xml",list);

//    QStringList list;
//    list << "厂家" << "品牌" << "价格" << "数量" << "总价" ;
//    DomXML::appendXML("../test.xml",list);

    QStringList fList;
    QStringList bList;
    QStringList pList;
    QStringList nList;
    QStringList mList;
    DomXML::readXML("../test.xml",fList,bList,pList,nList,mList);

    for(int i=0; i<fList.size(); i++)
    {
        QString str = QString("%1-%2 : 卖出 %3 辆 单价为: %4 共 %5 元")
                .arg(fList.at(i))
                .arg(bList.at(i))
                .arg(nList.at(i))
                .arg(pList.at(i))
                .arg(mList.at(i));
        ui->statistical->append(str);
        qDebug()<<str<<endl;
    }

    on_ButtonCancel_clicked();//初始化
}




void MainWindow::on_comboBoxFactory_1_currentIndexChanged(const QString &selectFactory)
{

    if(selectFactory == "请选择厂家")
    {
        ui->comboBoxBrand_1->clear();
//        ui->widgetPie->setEnabled(false);
    }
    else
    {
        ui->comboBoxBrand_1->clear();
//        ui->widgetPie->setEnabled(false);
        QSqlQuery query;
        QString sql = QString("select name from brand where factory = '%1'").arg(selectFactory);//获取
        query.exec(sql);//执行sql语句
        while(query.next())
        {
            QString name = query.value("name").toString();//获取所选项
            ui->comboBoxBrand_1->addItem(name);//添加条目
        }
//        ui->widgetPie->setEnabled(true);
    }

    //绘制柱状图
    QBarSet *setB = new QBarSet(selectFactory);//新建数据集
    setB->setColor(QColor(qrand()%255,qrand()%255,qrand()%255,qrand()%51+50));//设置数据集颜色
    QSqlQuery query;
    QString sql = QString("select name,last from brand where factory = '%1'").arg(selectFactory);//获取所选厂家的所有品牌
    query.exec(sql);//执行sql语句

    QStringList categoriesB;//存放各项名称（品牌名）
    while(query.next())
    {
        *setB << query.value("last").toInt();//存放剩余量
        categoriesB << query.value("name").toString();//存放名称
    }

    QBarSeries *seriesB = new QBarSeries();

    seriesB->append(setB);

    QChart * chartB = plotSeries::plotBar(seriesB,categoriesB);

    ui->widgetBar->setChart(chartB);

}

void MainWindow::on_comboBoxBrand_1_currentIndexChanged(const QString &selectBrand)
{
    //绘制饼状图

    QSqlQuery query;
    QString sql = QString("select sell,last from brand where factory = '%1' and name = '%2'")
            .arg(ui->comboBoxFactory_1->currentText())
            .arg(selectBrand);//获取
    query.exec(sql);//执行sql语句

    QPieSeries *seriesP = new QPieSeries();

    while(query.next())
    {
        int sell = query.value("sell").toInt();
        seriesP->append("sell", sell);
        int last = query.value("last").toInt();
        seriesP->append("last", last);
    }

    QChart *chartP = plotSeries::plotPie(seriesP);

    ui->widgetPie->setChart(chartP);
}

/*
 当切换厂家时，会报错，提示越界
 通过调试可以发现是绘制饼状图的问题
 切换厂家时，295行的selectBrand为空
 在plotPie中增加大于零的判断，可以解决
*/

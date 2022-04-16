#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug()<<QSqlDatabase::drivers();//打印所支持的数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    //设置数据库参数
    db.setDatabaseName("info.db");

    if(!db.open())//如果打开失败
    {
        QMessageBox::warning(this,"error",db.lastError().text());
        return;
    }
    else
        QMessageBox::about(this,"open Database","success!");

    QSqlQuery query;//用于执行数据库语句
    query.exec("create table `student`(id int primary key, name varchar(255),age int,score int);");

    //ODBC风格插入
    query.prepare("insert into student(id,name,age,score) value(?,?,?,?)");
    QVariantList idList;
    idList<<0<<1<<2;
    QVariantList nameList;
    nameList<<"A"<<"B"<<"C";
    QVariantList ageList;
    ageList<<0<<1<<2;
    QVariantList scoreList;
    scoreList<<99<<88<<77;

    query.addBindValue(idList);
    query.addBindValue(nameList);
    query.addBindValue(ageList);
    query.addBindValue(scoreList);

//    query.exec("insert into student(id,name,age,score) value(1,'dk',20,90)");
//    query.exec("insert into student(id,name,age,score) value(2,'dkk',19,80)");
//    query.exec("insert into student(id,name,age,score) value(3,'dkkk',18,70)");

    query.exec("select * from student;");

    while(query.next())
    {
        qDebug() << query.value(0).toInt()
                 << query.value(1).toString()
                 << query.value("age").toInt()
                 << query.value("score").toInt();
    }
}

Widget::~Widget()
{
    delete ui;
}


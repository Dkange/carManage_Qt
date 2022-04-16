#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    qDebug()<<QSqlDatabase::drivers();//打印所支持的数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    //设置数据库参数
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("dangke");
    db.setDatabaseName("info");

    if(!db.open())//如果打开失败
    {
        QMessageBox::warning(this,"error",db.lastError().text());
        return;
    }
    else
        QMessageBox::about(this,"open Database","success!");

    QSqlQuery query;//用于执行数据库语句
    query.exec("CREATE TABLE `student`(id int primary key auto_increment, name varchar(255),age int,score int);");

    query.exec("insert into student(id,name,age,score) value(1,'dk',20,90)");
    query.exec("insert into student(id,name,age,score) value(2,'dkk',19,80)");
    query.exec("insert into student(id,name,age,score) value(3,'dkkk',18,70)");

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


void Widget::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();//获取输入框中的信息
    QString sql = QString("delete from student where name = '%1';").arg(name);//创建数据库语句

    QSqlDatabase::database().transaction();//新建事务
    //执行语句
    QSqlQuery query;
    query.exec(sql);

}


void Widget::on_pushButton_2_clicked()
{
    QSqlDatabase::database().commit();//确认删除
}

void Widget::on_pushButton_3_clicked()
{
    QSqlDatabase::database().rollback();
}

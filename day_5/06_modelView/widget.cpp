#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
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

    model = new QSqlTableModel(this);
    model->setTable("student");

    ui->tableView->setModel(model);

    model->select();

    model->setHeaderData(0,Qt::Horizontal,"学号");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
    model->setHeaderData(2,Qt::Horizontal,"年龄");
    model->setHeaderData(3,Qt::Horizontal,"得分");

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);//修改编辑策略为手动提交

//    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//将界面设置为不可修改
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_addButton_clicked()
{
    QSqlRecord record = model->record();//创建新记录

    int row = model->rowCount();//获取行

    model->insertRecord(row,record);//插入记录

}

void Widget::on_deleteButton_clicked()
{
    QItemSelectionModel *item = ui->tableView->selectionModel();

    QModelIndexList list = item->selectedRows();

    for(int i=0; i<list.size(); i++)
    {
        model->removeRow(list.at(i).row());
    }
}

void Widget::on_confirmButton_clicked()
{
    model->submitAll();//提交
}

void Widget::on_cancelButton_clicked()
{
    model->revert();//取消操作
    model->submitAll();//提交取消操作
}

void Widget::on_searchButton_clicked()
{
    QString name = ui->lineEdit->text();
    QString sql = QString("name = '%1'").arg(name);

    model->setFilter(sql);
//    model->select();
}

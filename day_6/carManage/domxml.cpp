#include "domxml.h"
#include <QFile>
#include <QDebug>
#include <QDomDocument>//创建xml文件
#include <QDomProcessingInstruction>//创建文件头
#include <QDomElement>//创建节点元素
#include <QTextStream>
#include <QDomAttr>
#include <QDateTime>

#define cout qDebug()<< "[" << __FILE__ <<":"<< __LINE__  <<"]"
DomXML::DomXML()
{

}

void DomXML::creatXML(QString filePath)
{
    QFile file(filePath);
    if(file.exists() == true)
    {
        cout<<"文件已存在!"<<endl;
        return;
    }
    else
    {
        bool isOk = file.open(QIODevice::WriteOnly);

        if(true == isOk)
        {
            QDomDocument doc;//创建文件

            QDomProcessingInstruction ins;//创建头
            ins = doc.createProcessingInstruction("xml","version=\'1.0\' encoding=\'utf-8\'");
            doc.appendChild(ins);//xml添加头

            QDomElement root;//创建节点
            root = doc.createElement("日销售清单");
            doc.appendChild(root);//xml添加元素节点

            QTextStream stream(&file);
            doc.save(stream,4);//缩进为4

            file.close();
        }
        else
        {
            cout<<"文件打开失败!"<<endl;
        }
    }
}


void DomXML::appendXML(QString filePath,QStringList list)
{
    QFile file(filePath);

    bool isOk = file.open(QIODevice::ReadOnly);

    if(isOk)
    {
        QDomDocument doc;
        isOk = doc.setContent(&file);//关联文件

        if(isOk)
        {
            file.close();

            QDateTime timeData = QDateTime::currentDateTime();
            QString dateStr = timeData.toString("yyyy-MM-dd");

            QDomElement root = doc.documentElement();//获取根节点
            //判断是否有子节点
            isOk = root.hasChildNodes();
            if(isOk)//根节点如果有子节点
            {
                QDomElement lastElement = root.lastChildElement();
                if(lastElement.attribute("date") == dateStr)//判断有没有当前日期
                {
                    DomXML::wirteXML(doc,lastElement,list);
                }
                else
                {
                    QDomElement dateElement;
                    dateElement = doc.createElement("日期");//创建时间子节点元素

                    QDomAttr dateAttr;
                    dateAttr = doc.createAttribute("date");//创建属性

                    dateAttr.setNodeValue(dateStr);//设置属性的值

                    dateElement.setAttributeNode(dateAttr);//节点与属性关联

                    root.appendChild(dateElement);//将时间节点追加到根节点下

                    DomXML::wirteXML(doc,dateElement,list);

                }
            }
            else//如果没有
            {
                QDomElement dateElement;
                dateElement = doc.createElement("日期");//创建时间子节点元素

                QDomAttr dateAttr;
                dateAttr = doc.createAttribute("date");//创建属性

                dateAttr.setNodeValue(dateStr);//设置属性的值

                dateElement.setAttributeNode(dateAttr);//节点与属性关联

                root.appendChild(dateElement);//将时间节点追加到根节点下

                DomXML::wirteXML(doc,dateElement,list);
            }

            isOk = file.open(QIODevice::WriteOnly);
            if(isOk)
            {
                QTextStream stream(&file);//创建文件流
                doc.save(stream,4);//保存文件
                file.close();//关闭文件
            }
            else
            {
                cout<<"文件打开失败！"<<endl;
                return;
            }
        }
        else
        {
            cout<<"文件关联失败！"<<endl;
            return;
        }
    }
    else
    {
        cout<<"文件打开失败！"<<endl;
        return;
    }
}

void DomXML::wirteXML(QDomDocument &doc,QDomElement &root,QStringList &list)
{
    //获取当前时间
    QDateTime timeData = QDateTime::currentDateTime();
    QString dateStr = timeData.toString("hh-mm-ss");

    QDomElement timeElement = doc.createElement("时间");//创建时间元素节点
    QDomAttr timeAttr = doc.createAttribute("time");//创建时间节点属性
    timeAttr.setValue(dateStr);//设置属性的值

    timeElement.setAttributeNode(timeAttr);//关联属性

    root.appendChild(timeElement);//追加时间节点

    QDomElement factory = doc.createElement("厂家");
    QDomElement brand = doc.createElement("品牌");
    QDomElement price = doc.createElement("厂家");
    QDomElement num = doc.createElement("数量");
    QDomElement money = doc.createElement("总价");


    QDomText textFactory = doc.createTextNode(list.at(0));
    factory.appendChild(textFactory);
    QDomText textBrand = doc.createTextNode(list.at(1));
    brand.appendChild(textBrand);
    QDomText textPrice = doc.createTextNode(list.at(2));
    price.appendChild(textPrice);
    QDomText textNum = doc.createTextNode(list.at(3));
    num.appendChild(textNum);
    QDomText textMoney = doc.createTextNode(list.at(4));
    money.appendChild(textMoney);

    timeElement.appendChild(factory);
    timeElement.appendChild(brand);
    timeElement.appendChild(price);
    timeElement.appendChild(num);
    timeElement.appendChild(money);

}

void DomXML::readXML(QString filePath,
                     QStringList &flist,
                     QStringList &blist,
                     QStringList &plist,
                     QStringList &nlist,
                     QStringList &mlist)
{
    QFile file(filePath);
    bool isOk = file.open(QIODevice::ReadOnly);//打开文件

    if(isOk)
    {
        QDomDocument doc;
        isOk = doc.setContent(&file);//设定内容

        if(isOk)
        {
            QDomElement root = doc.documentElement();
            file.close();

            QDateTime timeData = QDateTime::currentDateTime();
            QString dateStr = timeData.toString("yyyy-MM-dd");//获取当前日期

            QDomElement lastElement = root.lastChildElement();
            if(lastElement.attribute("date") == dateStr)//如果有当天节点
            {
                QDomNodeList list = lastElement.childNodes();

                for(int i=0; i<list.size(); i++)
                {
                    QDomNodeList subList = list.at(i).toElement().childNodes();

                    QString factory = subList.at(0).toElement().text();
                    flist.append(factory);
                    QString brand = subList.at(1).toElement().text();
                    blist.append(brand);
                    QString price = subList.at(2).toElement().text();
                    plist.append(price);
                    QString num = subList.at(3).toElement().text();
                    nlist.append(num);
                    QString money = subList.at(4).toElement().text();
                    mlist.append(money);
                }
            }
            else
            {
                cout<<"没有当天节点"<<endl;
                return;
            }
        }
        else
        {
            cout <<"关联失败"<<endl;
            return;
        }
    }
    else
    {
        cout <<"打开失败"<<endl;
        return;
    }
}













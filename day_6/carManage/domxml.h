#ifndef DOMXML_H
#define DOMXML_H
#include <QString>
#include <iostream>
#include <QStringList>
#include <QDomDocument>
#include <QDomElement>

using namespace std;
class DomXML
{
public:
    DomXML();

    static void creatXML(QString filePath);//创建XML文件，定义为静态成员函数，不需要通过对象调用

    static void appendXML(QString filePath,QStringList list);

    static void wirteXML(QDomDocument &doc,QDomElement &root,QStringList &list);

    static void readXML(QString filePath,
                        QStringList &flist,
                        QStringList &blist,
                        QStringList &plist,
                        QStringList &nlist,
                        QStringList &mlist);
};

#endif // DOMXML_H

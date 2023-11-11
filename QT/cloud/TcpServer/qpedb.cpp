#include "qpedb.h"
#include <QMessageBox>
#include <QDebug>
#include <QFile>
QpeDB::QpeDB(QObject *parent)
    : QObject{parent}
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
}

QpeDB &QpeDB::getInstance()
{
    static QpeDB instance;
    return instance;

}

void QpeDB::init()
{
    m_db.setHostName("localhost");

    QString str = "E:\\云文件\\BaiduNetdiskWorkspace\\代码\\QT\\cloud file\\TcpServer\\cloud.db";

    m_db.setDatabaseName(str);


    if(m_db.open())
    {

        QSqlQuery query;

    query.exec("select * from usrInfo");
                while (query.next())
                {
                    QString data = QString("%1,%2,%3").arg(query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString());
                    qDebug() << data;
                }



    }
    else
    {
        QMessageBox::critical(NULL,"打开数据库", "打开数据库失败");
    }
}

bool QpeDB::handleRegist(const char *name, const char *pwd)
{
    if(name == nullptr&& pwd == nullptr)
    {
        qDebug()<<"name | pwd is NULL";
                  return false;
    }
    QString data = QString("insert into usrInfo(name,pwd) values(\'%1\',\'%2\')").arg(name).arg(pwd);

    QSqlQuery query;

    return query.exec(data);
}

bool QpeDB::handleLogin(const char *name, const char *pwd)
{
    if(name == nullptr&& pwd == nullptr)
    {
        qDebug()<<"name | pwd is NULL";
                  return false;
    }
    QString data = QString("select * from usrInfo where name=\'%1\' and pwd=\'%2\'").arg(name).arg(pwd);
    qDebug() << data;
    QSqlQuery query;
    query.exec(data);
    if(query.next())
    {
        data = QString("update usrInfo set online=1 where name=\'%1\' and pwd=\'%2\'").arg(name).arg(pwd);
        qDebug() << data;
        QSqlQuery  queryup;
        queryup.exec(data);
        return true;
    }
    else {
        return false;
    }
}

bool QpeDB::handexit(const char *name)
{
    if(name == nullptr)
    {
        qDebug()<<"name | pwd is NULL";
                  return false;
    }

        QString data = QString("update usrInfor set online=0 where name=\'%1\'").arg(name);
        qDebug() << data;
        QSqlQuery  queryup;
        queryup.exec(data);
        return true;



}

QStringList QpeDB::handleALLOnline()
{
QString data = QString("select name from usrInfo where online=1");
qDebug()<<"db__";
QSqlQuery query;
query.exec(data);
QStringList result;
result.clear();
while(query.next())
{
    result.append(query.value(0).toString());
    qDebug()<<query.value(0).toString();
}
qDebug()<<"----------";
return result;
}

int QpeDB::handleSearchUsr(const char *name)
{
    if(name  ==nullptr)
    {
        return -1;
    }
    QString data = QString("select online from usrInfo where name = \'%1\'").arg(name);
    QSqlQuery query;
    query.exec(data);
    if(query.next())
    {
        int ret = query.value(0).toInt();
        if(ret == 0)
        {
            return 0;
        }
        else if( ret != 0)
        {
            return 1;
        }
    }
    else {
        return -1;
    }
}

int QpeDB::handleAddFriend(const char *perName, const char *name)
{
    if(perName == nullptr || name == nullptr)
    {
        return -1;
    }
    QString data = QString("select * from friend where (id=(select id from usrInfo where name=\'%1\') and friendId = (select id from usrInfo where name=\'%2\'))or (id=(select id from usrInfo where name=\'%3\') and friendId = (select id from usrInfo where name=\'%4\'))"
                           ).arg(perName).arg(name).arg(name).arg(perName);
    qDebug()<<data;
    QSqlQuery query;
    query.exec(data);
    if(query.next())
    {
        return 0;
    }
    data  = QString("select online from usrInfo where name=\'%1\'").arg(perName);
    query.exec(data);
    if(query.next())
    {
        int ret = query.value(0).toInt();
        if(ret == 1)
        {
            return 1;
        }
        else if(ret == 0)
        {
            return 2;
        }
        else {
            return 3;
        }

    }
}

void QpeDB::handleAgreeAddFriend(const char *perName, const char *name)
{
    if(perName == nullptr || name == nullptr)
    {
        return ;
    }
   QString data = QString("insert into friend(id, friendId) values((select id from usrInfo where name=\'%1\'), (select id from usrInfo where name=\'%2\'))").arg(perName).arg(name);
   QSqlQuery query;
   query.exec(data);


}

QStringList QpeDB::handleFlushFriend(const char *name)
{
    QStringList strFriendlist;
    strFriendlist.clear();
    if(name == nullptr)
       {
        return strFriendlist;
    }
    QString data = QString("select name from usrInfo where online=1 and id in (select id from friend where friendId=(select id from usrInfo where name=\'%1\'))").arg(name);
    QSqlQuery query;
    query.exec(data);
    while(query.next())
    {
        strFriendlist.append(query.value(0).toString());
    }
    data = QString("select name from usrInfo where online=1 and id in (select friendId from friend where id=(select id from usrInfo where name=\'%1\'))").arg(name);
    query.exec(data);
    while(query.next())
    {
        strFriendlist.append(query.value(0).toString());
    }
    return strFriendlist;
}

bool QpeDB::handleDelFriend(const char *perName, const char *name)
{
    if(perName == nullptr||name == nullptr)
    {
        return false;
    }
    QString data  = QString("delete from friend where id=(select id from usrInfo where name=\'%1\') and friendId=(select id from usrInfo where name=\'%2\')").arg(name).arg(perName);
    QSqlQuery query;
    query.exec(data);
    data = QString("delete from friend where id=(select id from usrInfo where name=\'%1\') and friendId=(select id from usrInfo where name=\'%2\')").arg(perName).arg(name);
    query.exec(data);
    return true;
}

QpeDB::~QpeDB()
{
    m_db.close();
}

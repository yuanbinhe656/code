#ifndef QPEDB_H
#define QPEDB_H

#include <QObject>
#include  <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>

class QpeDB : public QObject
{
    Q_OBJECT
public:
    explicit QpeDB(QObject *parent = nullptr);
    static QpeDB &getInstance();
    void init();
    bool handleRegist(const char *name, const char * pwd );
    bool handleLogin(const char *name, const char * pwd);
    bool handexit(const char * name);
    QStringList handleALLOnline();
    int handleSearchUsr(const char *name);
    int handleAddFriend(const char *perName, const char * name);
    void  handleAgreeAddFriend(const char *perName, const char * name);
    QStringList handleFlushFriend(const char *name);
    bool handleDelFriend(const char *perName, const char * name);

    ~QpeDB();



signals:

public slots:
private:
    QSqlDatabase m_db;

};

#endif // QPEDB_H

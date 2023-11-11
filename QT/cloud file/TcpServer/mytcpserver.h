#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>
#include <QList>
#include "mytcpsocket.h"
#include <QObject>

class MyTcpServer : public QTcpServer
{
     Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    static MyTcpServer& getInstance();
    void incomingConnection( qintptr socketDescriptor);
    void resend (const char * pername , PDU * pdu);
public slots:
    void deleteSocket(mytcpsocket *mysocket);
private:
    QList<mytcpsocket *> m_tcpSocketList;


};

#endif // MYTCPSERVER_H

#include "mytcpserver.h"
#include <QDebug>

MyTcpServer::MyTcpServer(QObject *parent)
    : QTcpServer{parent}

{

}
MyTcpServer &MyTcpServer::getInstance()
{
    static MyTcpServer instance;
    return instance;
}

void MyTcpServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "new client connected";
    mytcpsocket *pTcpSocket = new mytcpsocket;

    pTcpSocket->setSocketDescriptor(socketDescriptor);
    m_tcpSocketList.append(pTcpSocket);
    connect(pTcpSocket, SIGNAL(offline(mytcpsocket*)),this , SLOT(deleteSocket(mytcpsocket*)));

}

void MyTcpServer::resend(const char *pername, PDU *pdu)
{
    if(pername == nullptr || pdu == nullptr)
    {
        return ;
    }
    QString strName = pername;
    for (int i = 0; i < m_tcpSocketList.size();i++)
    {
        if (m_tcpSocketList.at(i)->getName() == strName)
        {
            m_tcpSocketList.at(i)->write((char*)pdu, pdu->uiPDULen);
            break;
        }
    }

}

void MyTcpServer::deleteSocket(mytcpsocket *mysocket)
{
    QList<mytcpsocket*> ::iterator iter = m_tcpSocketList.begin();
    for(; iter != m_tcpSocketList.end(); iter++)
    {
        if(mysocket == *iter)
        {


            m_tcpSocketList.erase(iter);
            break;
        }
    }
    for (int i = 0; i < m_tcpSocketList.size(); i++)
    {
        qDebug()<< m_tcpSocketList.at(i)->getName();
    }
}

#include "tcpserver.h"
#include "ui_tcpserver.h"
#include <QByteArray>
#include <QDebug>
#include <QMessageBox>
#include <QHostAddress>
Tcpserver::Tcpserver(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tcpserver)
{
    ui->setupUi(this);
    QpeDB::getInstance().init();
    loadConfig();
    MyTcpServer ::getInstance().listen(QHostAddress(m_strIP),m_usPort);

}

Tcpserver::~Tcpserver()
{
    delete ui;
}

void Tcpserver::loadConfig()
{
    QFile file(":/server.config");

    if(file.open(QIODevice::ReadOnly))
    {

        QByteArray baDate = file.readAll();
        QString strDate = baDate.toStdString().c_str();
        file.close();
        strDate.replace("\r\n"," ");
        QStringList strList = strDate.split(" ");

        m_strIP = strList.at(0);
        m_usPort = strList.at(1).toUShort();
        qDebug() << "ip:"<<m_strIP << "port:" << m_usPort;
    }
    else {
        QMessageBox::critical(this, "open config", "open config failed");
        }

}


#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QTcpSocket>
#include <QObject>
#include "protocol.h"
#include "qpedb.h"
#include <QDIr>
#include <QFile>
#include <QTImer>
class mytcpsocket : public QTcpSocket
{
      Q_OBJECT
public:
    explicit mytcpsocket(QObject *parent = nullptr);
    QString getName();
        void copyDir(QString strSrcDir,QString strDesDir);
        PDU* writeUPD();

    signals:
        void offline(mytcpsocket *mysocket);
    public slots:
        void recvMsg();
        void clientOffline();
       void sendFileToClient();
    private:
        QString m_strName ;
        QFile m_file;
        qint64 m_iTotal;
        qint64 m_iRecved;
        bool m_bUpload;
        QTimer *m_pTimer;
   };

   #endif // MYTCPSOCKET_H

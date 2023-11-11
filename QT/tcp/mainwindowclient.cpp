#include "mainwindowclient.h"
#include "ui_mainwindowclient.h"

#include <QByteArray>
#include <QTcpSocket>
#include <QHostAddress>
MainWindowclient::MainWindowclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowclient)
{
    ui->setupUi(this);
    ui->lineEdit->setText("127.0.0.1");
    ui->lineEdit_2->setText("8888");
    socke = NULL;
    this->setWindowTitle("客户端");
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        QString host = ui->lineEdit->text();
        qint16 port = ui->lineEdit_2->text().toInt();
        socke = new QTcpSocket(this);

        socke->connectToHost(QHostAddress(host),port);
        //socke->setProxy(QNetworkProxy::NoProxy);
        connect(socke,&QTcpSocket::hostFound,[=](){
            qDebug()<<"hostfound";
        });
                    connect(socke,&QTcpSocket::connected,[=](){
                qDebug()<<"connectd";
            }) ;
                    connect(socke,&QTcpSocket::error,[=](){
                      //  qDebug()<<"erro";
                    });
//        if(socke->peerAddress().toString() =="")
//        {
//            return;
//        }
                    QString str=QString("[%1:%2]成功和服务器[%3:%4]建立连接").arg(socke->localAddress().toString()).arg(socke->localPort()).arg(socke->peerAddress().toString()).arg(socke->peerPort());
        ui->textEdit->append(str);
       qDebug()<<socke->peerAddress().toString();
        connect(ui->pushButton,&QPushButton::clicked,[=](){
            QString s = ui->textEdit_2->toPlainText();

            socke->write(s.toUtf8().data());
            ui->textEdit->append("client: "+s);
            ui->textEdit_2->clear();
        });
        connect(socke,&QTcpSocket::readyRead,[=](){
            QByteArray array = socke->readAll();
            ui->textEdit->append("host: "+array);

        });

    });



}

MainWindowclient::~MainWindowclient()
{
    delete ui;
}

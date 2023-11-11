#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QByteArray>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("主机");
    ui->plainTextEdit->setReadOnly(true);
    sockserver = new QTcpServer(this);
    sockserver->listen(QHostAddress::Any, 8888);

    connect(sockserver,&QTcpServer::newConnection,[=](){
        qDebug()<<"lala";
        sock = sockserver->nextPendingConnection();
        QString peadr = sock->peerAddress().toString();
        qint16 peport = sock->peerPort();
        QString hoadr = sock->localAddress().toString();
        qint16 hoport = sock->localPort();
        QString temp = QString("[%1,%2]成功连接[%3:%4]！").arg(peadr).arg(peport).arg(hoadr).arg(hoport);
        ui->plainTextEdit->appendPlainText(temp);
        connect (ui->pushButton,&QPushButton::clicked,[=](){
            if(ui->textEdit->toPlainText()=="")
            {
                return ;
            }
            sock->write(ui->textEdit->toPlainText().toUtf8().data());
            ui->plainTextEdit->appendPlainText("host: "+ui->textEdit->toPlainText());
            ui->textEdit->clear();
        });
        connect(sock,&QTcpSocket::readyRead,[=](){
            QByteArray array = sock->readAll();
            ui->plainTextEdit->appendPlainText("client:"+array);
        });
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


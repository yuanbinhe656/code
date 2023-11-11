#include "mycoin.h"
#include<QPushButton>
#include<QTimer>
//mycoin::mycoin(QWidget *parent)
//    : QWidget{parent}
//{

//}
mycoin::mycoin(QString btnImg)
{
    QPixmap pix;
    bool res = pix.load(btnImg);
    if(res == NULL)
    {
        qDebug() <<"图片加载失败";
    }
   this->setFixedSize(pix.width()*1.4,pix.height()*1.4);
    this->setStyleSheet("QPushButton{border:0px");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    connect(timer1,&QTimer::timeout,[=](){
        QString str = QString (":/new/Coin000%1.png").arg(this->min++);
        QPixmap pix;
        pix.load(str);
        this->setFixedSize(pix.width()*1.4,pix.height()*1.4);
         this->setStyleSheet("QPushButton{border:0px");
         this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
        if(this->min >this->max)
        {
            this->min = 1;
        this->isAnimation = false;
        timer1->stop();
        }

    });
    connect(timer2,&QTimer::timeout,[=](){
        QString str = QString (":/new/Coin000%1.png").arg(this->max--);
        qDebug()<<"zheng:"<<this->flag;
        qDebug()<<"path:"<<str;
       // QString str = QString (":/new/Coin0001.png");//.arg(this->max--);
        QPixmap pix;
        pix.load(str);
        this->setFixedSize(pix.width()*1.4,pix.height()*1.4);
         this->setStyleSheet("QPushButton{border:0px");
         this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
        if(this->min >this->max)
        {
            this->max = 8;
        this->isAnimation = false;
        timer2->stop();
        }


    });
}
void mycoin::changeFlag(int ms)
{
    if(this->flag){
        timer1->start(5);
        this->isAnimation = true;
        this->flag = false;
    }
    else {
        timer2 ->start(5);
        this->isAnimation = true;
        this->flag = true;
    }
}

void mycoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation||this->notPress)
    {
        return;
    }
   return QPushButton::mousePressEvent(e);
}

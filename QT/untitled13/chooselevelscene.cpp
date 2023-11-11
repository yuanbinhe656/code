#include "chooselevelscene.h"

chooselevelscene::chooselevelscene(QWidget *parent)
    : QMainWindow{parent}
{

    this->setFixedSize(420,680);
      this->setWindowIcon(QPixmap(":/new/Coin0001.png"));
    this->setWindowTitle("level");

    QMenuBar * menbar = new QMenuBar();
    setMenuBar(menbar);
    QMenu *startmenu = menbar->addMenu("start");
    QAction *quitaction = startmenu->addAction("exit");
    connect(quitaction,&QAction::triggered,this,[=](){this->close();emit chooseBackScene();});


    //back
    Button  *backbtn =new Button(":/new/BackButton.png",":/new/BackButtonSelected.png");
    backbtn->setParent(this);
    backbtn->move(this->width()*0.5-backbtn->width()*0.5,this->height()-backbtn->height()-100);
   // backbtn->setFixedSize(backbtn->width()*5,backbtn->height()*5);
    connect(backbtn,&QPushButton::clicked,[=](){
        emit this->chooseBackScene();
      //  this->close();
    });
    //关卡界面
    for (int i = 0;i < 20 ; i++)
    {
        Button * selectbtn = new Button(":/new/LevelIcon.png");
        selectbtn->setParent(this);
        selectbtn->move(70+i%4 *70,180 +i/4 *70);
        connect(selectbtn,&Button::clicked,this,[=](){
            QString str = QString("NO.%1 was selected").arg(i+1);

            this ->playsence=new Playscene(i+1);
            this->playsence->setGeometry(this->geometry());
            this -> hide();
            playsence->show();
            connect(this->playsence,&Playscene::selectLevelScene,[=](){
                this->setGeometry(playsence->geometry());
                sleep(100);
                playsence->close();
                this->show();
                delete playsence;
                playsence = NULL;
        });
        });
        QLabel *lable = new QLabel;
        lable->setParent(selectbtn);
        lable->setFixedSize(selectbtn->width(),selectbtn->height());
        lable->setText(QString ::number(i+1));
        lable->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        lable->setAttribute(Qt::WA_TransparentForMouseEvents);
  }

}
void chooselevelscene::closeEvent ( QCloseEvent * e )
{

    emit this->chooseBackScene();
    return QMainWindow::closeEvent(e);
}
void chooselevelscene::paintEvent (QPaintEvent *event)
{
    QPixmap pix;
    pix.load(":/new/OtherSceneBg.png");
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/new/Title.png");
    painter.drawPixmap(this->width()*0.5-pix.width()*0.6,40,pix.width()*1.2,pix.height()*1.2,pix);

}
chooselevelscene::~chooselevelscene()
{
    //qDebug()<<"这是第";
}

void chooselevelscene::sleep( int  ms)
{
    QTime reachTime = QTime::currentTime().addMSecs(ms);
    while(QTime::currentTime()< reachTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,50);
    }
}
// void chooselevelscene::chooseBackScene()
// {

// }

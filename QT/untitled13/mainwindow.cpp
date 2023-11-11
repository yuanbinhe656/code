#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include <Button.h>
#include <QDebug>
#include <Qtimer>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QAudioDevice>
#include <chooselevelscene.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //配置

       //setWindowTitle("laaaaa");
    setFixedSize(320,588);
    setWindowIcon(QIcon(":/new/Coin0001.png"));
    //music
   /// QAudioDevice adiv ;
  //  QAudioOutput *aot = new QAudioOutput();
   // aot->bindingStorage()
   QSoundEffect *startSound = new QSoundEffect();
    startSound->setSource(QUrl::fromLocalFile(":/new/LevelWinSound.wav"));
    startSound->play();
    Button *startbtn = new Button(QString(":/new/MenuSceneStartButton.png"),":/new/MenuSceneStartButton.png");
    startbtn->setParent(this);

//    Button *btns = new Button(":/new/MenuSceneStartButton.png");
//    btns->setParent(this);
//    btns->move(100,200);
//    connect(btns,&QPushButton::clicked,[=](){
//        choice->setGeometry(this->geometry());
//           this->hide();
//           choice->show();
//    });

    chooselevelscene *choice= new chooselevelscene(this);
   // chooselevelscene* cho = new chooselevelscene(this);
   // choice = cho;


    startbtn->move(this->width()*0.5-startbtn->width()*0.5,this->height()*0.5);
    connect(startbtn,&QPushButton::clicked,[=]()->void{
        qDebug()<<"wu"<<choice;




        startbtn->downBounce();
        startbtn->upBounce();
       // sleep(50);
        choice->setGeometry(this->geometry());
        this->hide();
          choice->show();


    });
    connect(choice,&MainWindow::close,this,[=](){qDebug()<<"haa";this->show();});
    connect(choice,&chooselevelscene::chooseBackScene,[=]()->void{
        sleep(100);
        this->setGeometry(choice->geometry());
        qDebug()<<choice->isActiveWindow();
        choice->close();
        this->show();
    });
//    connect(ui->actiontuicu,&QAction::triggered,this,[=](){
//        this->close();
//    });
    //connect(ui->actiontuicu,&QAction::triggered,[=](){this->close();});
   // choice->setAttribute(Qt::WA_DeleteOnClose);


}
void MainWindow::sleep(int ms)
{
    QTime reachTime = QTime::currentTime().addMSecs(ms);
    while(QTime::currentTime()< reachTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,50);
    }
}
void MainWindow::paintEvent(QPaintEvent *)
{
    //卓屏幕
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/new/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/new/Title.png");
    pix.scaled(pix.width()*0.8,pix.height()*0.8);
    painter.drawPixmap(10,30,pix);

}
 MainWindow::~MainWindow()
{
    delete ui;
}


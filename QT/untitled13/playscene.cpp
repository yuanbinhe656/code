#include "playscene.h"
#include <dataconfig.h>
//Playscene::Playscene(QWidget *parent)
//    : QMainWindow{parent}
//{

//}
Playscene::Playscene(int leveNum)
{
    this->levelIndex = leveNum;
    QString str = QString("关卡%1").arg(leveNum);
    qDebug()<<str;
    // windows information
    this->setFixedSize(420,680);
    this->setWindowTitle(str);
    this->setWindowIcon(QPixmap(":/new/Coin0001.png"));
   // 2.creat menu
    QMenuBar * menubar = menuBar();
    setMenuBar(menubar);
    QMenu * Stratmenu = menubar->addMenu("Start");
    QAction * quitaction = Stratmenu->addAction("Exit");

    connect(quitaction,&QAction::triggered,[=](){this->close();});
    QSoundEffect *flipsound = new QSoundEffect();
    flipsound->setSource(QUrl::fromLocalFile(":/new/ConFlipSound.wav"));
    QSoundEffect *winsound = new QSoundEffect();
    winsound->setSource(QUrl::fromLocalFile(":/new/LevelWinSound.wav"));
    QSoundEffect *backsound = new QSoundEffect();
    backsound->setSource(QUrl::fromLocalFile(":/new/BackButtonSound.wav"));

      Button * backbtn = new Button(":/new/BackButton.png",":/new/BackButtonSelected.png");
      backbtn->setParent(this);
    backbtn->move(this->width()*0.5-backbtn->width()*0.5,this->height()-backbtn->height()-100);
    connect(backbtn,&Button::clicked,[=](){emit this->selectLevelScene();});

    //7.show leve i
    QLabel *lable = new QLabel;
    lable ->setParent(this);

    QFont font;
    font.setFamily("楷体");;
    font.setPointSize(26);
    lable->setFont(font);

    QString leveltxt = QString("level:%1").arg(leveNum);
    lable->setText(leveltxt);

    lable ->setGeometry(30,this->height()-66,200,50);
    dataconfig config;
    for (int i = 0;i < 4;i++)
    {
        for (int j = 0; j < 4;j++)
        {
            this->gameArry[i][j]=config.mData[this->levelIndex][i][j];
        }
    }
    QLabel *winlabel = new QLabel(this);
    QPixmap tmppix;
    tmppix.load(":/new/LevelCompletedDialogBg.png");
    winlabel->setGeometry((this->width()-tmppix.width())*0.5,-tmppix.height(),tmppix.width(),tmppix.height());
    winlabel->setPixmap(tmppix);
    //winlabel->move((this->width()-tmppix.height())*0.5,-tmppix.height());

    for(int i = 0; i < 4;i++)
    {
         for (int j = 0; j<4;j++)
         {
             QPixmap pix = QPixmap(":/new/BoardNode.png");
     //            pix.scaledToWidth(pix.width()*2);
     //            pix.scaledToHeight(pix.height()*2);

                 QLabel* label = new QLabel;
                 label->setScaledContents(true);
                 label->setGeometry(0,0,pix.width()*1.2,pix.height()*1.2);

                 label->setPixmap(pix);
                 label->setParent(this);
                 label->move(80+i*60,200+j*60);

                 QString str =  this->gameArry[i][j] == 1 ? ":/new/Coin0001.png" : ":/new/Coin0008.png";
                 mycoin* coin = new mycoin(str);
                 coin->setParent(label);

                 // 给金币属性赋值
                 coin->posX = i;
                 coin->posY = j;
                 coin->flag = this->gameArry[i][j]; // 1正面 0反面
                 coin->notPress = false;

                 coinBtn[i][j] = coin;

                 // 点击金币，进行反转
                 connect(coin, &mycoin::clicked, [=](){

                     // 点击的过程中，默认为赢，防止恶意卡bug，在点击的同时点其他按钮
     //                for(int i = 0; i < 4; i++){
     //                    for(int j = 0; j < 4; j++){
     //                        this->isWin = true;
     //                    }
     //                }
                     //flipSound->play();
                     coin->changeFlag(9);
                     // 点击金币之后，需要更新一下数组，如果存的是正面，点击后是反面
                     this->gameArry[i][j] = this->gameArry[i][j] == 0 ? 1 : 0;

                     // 反转周围的金币
                     //this->sleep(2000);
                     //上
                     if(coin->posY-1 >= 0){
                         coinBtn[coin->posX][coin->posY-1]->changeFlag(9);
                         this->gameArry[coin->posX][coin->posY-1] = this->gameArry[coin->posX][coin->posY-1] == 0 ? 1 : 0;
                     }

                     //下
                     if(coin->posY+1 <= 3){
                         coinBtn[coin->posX][coin->posY+1]->changeFlag(9);
                         this->gameArry[coin->posX][coin->posY+1] = this->gameArry[coin->posX][coin->posY+1] == 0 ? 1 : 0;
                     }

                     //左
                     if(coin->posX-1 >= 0){
                         coinBtn[coin->posX-1][coin->posY]->changeFlag(9);
                         this->gameArry[coin->posX-1][coin->posY] = this->gameArry[coin->posX-1][coin->posY] == 0 ? 1 : 0;
                     }

                     //右
                     if(coin->posX+1 <= 3){
                         coinBtn[coin->posX+1][coin->posY]->changeFlag(9);
                         this->gameArry[coin->posX+1][coin->posY] = this->gameArry[coin->posX+1][coin->posY] == 0 ? 1 : 0;
                     }
                     // 翻完金币，默认还未胜利，继续判断
     //                for(int i = 0; i < 4; i++){
     //                    for(int j = 0; j < 4; j++){
     //                        this->isWin = true;
     //                    }
     //                }

                     this->isWin = true;
                     // 判断是否有银币，如果有说明游戏还没胜利
                     for(int i = 0; i < 4; i++){
                         for(int j = 0; j < 4; j++){
                             if(!this->coinBtn[i][j]->flag){
                                 this->isWin = false;
                                 break;
                             }
                         }
                     }
                     // 没有银币了，那么游戏胜利！
                     if(this->isWin){
                         //winSound->play();
                         qDebug() << "游戏胜利！";
                         // 禁用按钮
                         for(int i = 0; i < 4; i++){
                             for(int j = 0; j < 4; j++){
                                 this->coinBtn[i][j]->notPress = true;
                             }
                         }

                         QSoundEffect * winsound = new QSoundEffect();
                         winsound->setSource(QUrl::fromLocalFile(":/new/LevelWinSound.wav"));
                        // winsound->setLoopCount(5);
                           winsound->play();
//                         QSoundEffect  winsoun;
//                         QSoundEffect * sinsound = new QSoundEffect();
//                         winsoun = *sinsound;
//                         winsound.setSource(QUrl::fromLocalFile(":/new/LevelWinSound.wav"));
//                         winsound.play();
                         QPropertyAnimation* ani = new QPropertyAnimation(winlabel, "geometry");
                         ani->setDuration(1000);
                         ani->setStartValue(QRect(winlabel->x(),winlabel->y(),winlabel->width(),winlabel->height()));
                         ani->setEndValue(QRect(winlabel->x(),winlabel->y()+360,winlabel->width(),winlabel->height()));
                         ani->setEasingCurve(QEasingCurve::OutBounce);
                         ani->start();

                         winlabel->raise(); // 将图片显示在最顶层，如果没有，图片将显示在最底层
                     }
                 });
         }
    }
}

void Playscene::paintEvent(QPaintEvent *event)
{
QPixmap pix;
pix.load(":/new/PlayLevelSceneBg.png");
QPainter painter(this);
//painter.draw
painter.drawPixmap(0,0,this->width(),this->height(),pix);
pix.load(":/new/Title.png");
pix = pix.scaled(pix.width()*0.8,pix.height()*0.8);
painter.drawPixmap(10,30,pix);
}


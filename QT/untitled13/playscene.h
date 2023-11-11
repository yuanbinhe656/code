#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include <QString>
#include <QDebug>
#include <QPainter>
#include <QmenuBar>
#include <Button.h>
#include <Qlabel>
#include <mycoin.h>
#include <QTime>
#include <QApplication>
#include <QPropertyAnimation>
#include <QHBoxLayout>
#include <QSoundEffect>
#include <QMainWindow>
#include <QPixmap>

class Playscene : public QMainWindow
{
    Q_OBJECT
public:
   // explicit Playscene(QWidget *parent = nullptr);
   Playscene(int leveNum);
   void paintEvent(QPaintEvent *event);
   int levelIndex;
   int gameArry[4][4];
    mycoin *coinBtn[4][4];
    bool isWin;

signals:
    void selectLevelScene();
};

#endif // PLAYSCENE_H

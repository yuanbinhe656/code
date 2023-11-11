#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QMenuBar>
#include <Qmenu>
#include <QAction>
#include <Qpainter>
#include <QPixmap>
#include <Button.h>
#include <QDebug>
#include <Qlabel>
#include <playscene.h>
#include <QTime>
#include <QApplication>
#include <QSoundEffect>


class chooselevelscene : public QMainWindow
{
    Q_OBJECT
public:
    explicit chooselevelscene(QWidget *parent = nullptr);
    void paintEvent (QPaintEvent *event);
    void sleep(int ms);
    Playscene * playsence = NULL;
    void closeEvent ( QCloseEvent * e );
    ~chooselevelscene();


signals:
        void chooseBackScene();

};

#endif // CHOOSELEVELSCENE_H

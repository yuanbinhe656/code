#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<chooselevelscene.h>
#include <QMainWindow>
#include<QPaintEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
   void paintEvent(QPaintEvent *);
    ~MainWindow();
    void sleep(int ms);
   // chooselevelscene *choice;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

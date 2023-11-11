#ifndef MAINWINDOWCLIENT_H
#define MAINWINDOWCLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
namespace Ui {
class MainWindowclient;
}

class MainWindowclient : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowclient(QWidget *parent = nullptr);
    ~MainWindowclient();
    QTcpSocket * socke;

private:
    Ui::MainWindowclient *ui;
};

#endif // MAINWINDOWCLIENT_H

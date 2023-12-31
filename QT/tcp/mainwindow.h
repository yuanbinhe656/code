#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTcpServer* sockserver;
    QTcpSocket *sock;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include <mainwindowclient.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MainWindowclient v;
    v.show();
    return a.exec();
}

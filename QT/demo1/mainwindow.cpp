#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i = 0; i < 10; i++)
    {
        this->add(i);
    }
    qDebug() << this->m_data.size();
    this->deal();
    qDebug() << this->m_data.size();
    for(int i = 0; i < 10; i++)
    {
        this->add(i);
    }
    qDebug() << this->m_data.size();
    this->deal();
    qDebug() << this->m_data.size();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::deal()
{
    for(int i = 0; i < this->m_data.size(); i++)
    {
        this->m_data.takeFirst();
    }
}

void MainWindow::add(int i)
{
    this->m_data.append(i);
}


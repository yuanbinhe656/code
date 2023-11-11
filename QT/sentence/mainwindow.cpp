#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstring.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    text = ui->textEdit->toPlainText();
    for(int i = 0, j = 0; i < text.length();i++)
    {
        if(text[i]>='0'&&text[i]<='9')
        {
            if(i-j!=1)
           {
                textnum.push_back(text.mid(j,i));
            }
            else
            {
                j++;
            }



        }
    }
    ui->lineEdit->setText(textnum[0]);
}


void MainWindow::on_pushButton_clicked()
{

}


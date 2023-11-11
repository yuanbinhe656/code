#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Qstring>
#include <qfiledialog.h>
#include <qdebug.h>
#include <QStringList>
#include <QProcess>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList QList;//停止位
        QList.clear();
        QList <<tr("markdown")<<tr("docx")<<tr("txt")<<tr("pdf")<<tr("doc");
        ui->comboBox->clear();
        ui->comboBox->addItems(QList);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    outclas = ui->comboBox->currentText();
    if(ui->comboBox->currentIndex() ==0)
    {
        Suffix = "md";
        outclas = "markdown_phpextra";
    }
    name =name + "." + Suffix;
    cmdtext = tr("pandoc -s %1 -f %2 -t %3 -o %4 --extract-media=./ ").arg(input).arg(inclas).arg(outclas).arg(name);
    //ui->plainTextEdit->insertPlainText("/n");

    QString cmd1 = "cd /d " +output+"&&"+cmdtext;
  ui->plainTextEdit->insertPlainText(cmd1);

// ui->plainTextEdit->insertPlainText("\n");

 ui->plainTextEdit->insertPlainText("\n");

//    QProcess p(0);
//    p.start("cmd",QStringList()<<cmd1<<"&&"<<cmdtext);
//    p.waitForStarted();
//      p.waitForFinished();
//  QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());
 QProcess p(0);

     p.start("cmd", QStringList()<<"/c"<<cmd1);

     p.waitForStarted();

     p.waitForFinished();
     qDebug()<<QString::fromLocal8Bit(p.readAllStandardOutput());
// QProcess p(0);
//     p.start("cmd", QStringList()<<cmd1);


//     p.waitForStarted();
//     p.waitForFinished();
//     QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());





}


void MainWindow::on_pushButton_clicked()
{
    QString str = QFileDialog::getOpenFileName(
                this,
                tr("open a file."),
                "D:/",
                tr("text files(*.txt *.doc *.docx *.pdf *.md *.pptx);;video files(*.avi *.mp4 *.wmv);;All files(*.*)"));
    ui->lineEdit->setText(str);
    input = ui->lineEdit->text();
    int num1 = input.lastIndexOf(".");
     inclas = input.mid(num1+1);
     if(inclas == "md")
     {
         inclas == "markdown";
     }
    int num2 = input.lastIndexOf("/");
    name = input.mid(num2+1,num1-num2-1);
    qDebug()<<num1<<" "<<num2<<" "<<inclas;

}


void MainWindow::on_pushButton_2_clicked()
{
    QString path  = QFileDialog::getExistingDirectory(this, "选择目录", "E:\云文件\BaiduNetdiskWorkspace\笔记\计算机", QFileDialog::ShowDirsOnly);
    ui->lineEdit_2->setText(path);
    output = ui->lineEdit_2->text();

}


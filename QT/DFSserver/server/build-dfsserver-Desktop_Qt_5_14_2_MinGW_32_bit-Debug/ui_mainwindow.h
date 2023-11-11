/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <buttongroup.h>
#include <myfilewg.h>
#include <rankinglist.h>
#include <sharelist.h>
#include <transfer.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    ButtonGroup *btn_group;
    QStackedWidget *stackedWidget;
    MyFileWg *myfiles_page;
    ShareList *sharefile_page;
    RankingList *ranking_page;
    Transfer *transfer_page;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(765, 685);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_group = new ButtonGroup(centralwidget);
        btn_group->setObjectName(QString::fromUtf8("btn_group"));
        btn_group->setGeometry(QRect(0, 0, 765, 113));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_group->sizePolicy().hasHeightForWidth());
        btn_group->setSizePolicy(sizePolicy);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 123, 755, 611));
        myfiles_page = new MyFileWg();
        myfiles_page->setObjectName(QString::fromUtf8("myfiles_page"));
        stackedWidget->addWidget(myfiles_page);
        sharefile_page = new ShareList();
        sharefile_page->setObjectName(QString::fromUtf8("sharefile_page"));
        stackedWidget->addWidget(sharefile_page);
        ranking_page = new RankingList();
        ranking_page->setObjectName(QString::fromUtf8("ranking_page"));
        stackedWidget->addWidget(ranking_page);
        transfer_page = new Transfer();
        transfer_page->setObjectName(QString::fromUtf8("transfer_page"));
        stackedWidget->addWidget(transfer_page);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

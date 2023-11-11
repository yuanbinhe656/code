/********************************************************************************
** Form generated from reading UI file 'mainwindowclient.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWCLIENT_H
#define UI_MAINWINDOWCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowclient
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowclient)
    {
        if (MainWindowclient->objectName().isEmpty())
            MainWindowclient->setObjectName(QString::fromUtf8("MainWindowclient"));
        MainWindowclient->resize(420, 559);
        centralwidget = new QWidget(MainWindowclient);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 0, 1, 1, 1);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout_2->addWidget(textEdit, 1, 0, 1, 2);

        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        gridLayout_2->addWidget(textEdit_2, 2, 0, 1, 2);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(46, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        horizontalSpacer_2 = new QSpacerItem(39, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        gridLayout_2->addWidget(widget_2, 3, 0, 1, 2);

        MainWindowclient->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowclient);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 420, 26));
        MainWindowclient->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowclient);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowclient->setStatusBar(statusbar);

        retranslateUi(MainWindowclient);
        QObject::connect(pushButton_4, &QPushButton::clicked, textEdit, qOverload<>(&QTextEdit::clear));

        QMetaObject::connectSlotsByName(MainWindowclient);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowclient)
    {
        MainWindowclient->setWindowTitle(QCoreApplication::translate("MainWindowclient", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindowclient", "host", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowclient", "port", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindowclient", "connect", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindowclient", "send", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindowclient", "clear", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindowclient", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowclient: public Ui_MainWindowclient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWCLIENT_H

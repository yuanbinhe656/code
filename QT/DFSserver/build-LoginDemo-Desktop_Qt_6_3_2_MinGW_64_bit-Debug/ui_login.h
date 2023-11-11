/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mytitlebar.h"

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    MyTitleBar *titleBar;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_9;
    QLabel *loginTitle;
    QSpacerItem *verticalSpacer_8;
    QWidget *widget_5;
    QGridLayout *gridLayout;
    QLineEdit *userName_login;
    QLabel *label_3;
    QLineEdit *passwd_login;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_7;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QCheckBox *rememberPwd;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *regAccount;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_7;
    QWidget *regPage;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_14;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_3;
    QLabel *registerTitle;
    QWidget *widget_7;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLabel *label_8;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_8;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *label_9;
    QLineEdit *lineEdit_7;
    QSpacerItem *horizontalSpacer_11;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *registreBtn;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_8;
    QWidget *netSetPage;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_18;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_5;
    QLabel *serverSetTitle;
    QSpacerItem *verticalSpacer_10;
    QWidget *widget_10;
    QGridLayout *gridLayout_3;
    QLabel *label_12;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_9;
    QLabel *label_13;
    QSpacerItem *verticalSpacer_11;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *setOkBtn;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_9;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(448, 330);
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleBar = new MyTitleBar(Login);
        titleBar->setObjectName(QString::fromUtf8("titleBar"));

        verticalLayout->addWidget(titleBar);

        stackedWidget = new QStackedWidget(Login);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        loginPage = new QWidget();
        loginPage->setObjectName(QString::fromUtf8("loginPage"));
        horizontalLayout_3 = new QHBoxLayout(loginPage);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        widget = new QWidget(loginPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_9);

        loginTitle = new QLabel(widget);
        loginTitle->setObjectName(QString::fromUtf8("loginTitle"));
        loginTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(loginTitle);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_8);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        gridLayout = new QGridLayout(widget_5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        userName_login = new QLineEdit(widget_5);
        userName_login->setObjectName(QString::fromUtf8("userName_login"));

        gridLayout->addWidget(userName_login, 0, 2, 1, 1);

        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        passwd_login = new QLineEdit(widget_5);
        passwd_login->setObjectName(QString::fromUtf8("passwd_login"));

        gridLayout->addWidget(passwd_login, 2, 2, 1, 1);

        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 0, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_7, 1, 0, 1, 1);


        verticalLayout_2->addWidget(widget_5);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        rememberPwd = new QCheckBox(widget_2);
        rememberPwd->setObjectName(QString::fromUtf8("rememberPwd"));

        horizontalLayout->addWidget(rememberPwd);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        regAccount = new QToolButton(widget_2);
        regAccount->setObjectName(QString::fromUtf8("regAccount"));
        regAccount->setAutoRaise(true);

        horizontalLayout->addWidget(regAccount);

        horizontalSpacer_2 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        loginButton = new QPushButton(widget_3);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        horizontalLayout_2->addWidget(loginButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addWidget(widget_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_3->addWidget(widget);

        horizontalSpacer_7 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        stackedWidget->addWidget(loginPage);
        regPage = new QWidget();
        regPage->setObjectName(QString::fromUtf8("regPage"));
        horizontalLayout_6 = new QHBoxLayout(regPage);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_14);

        widget_6 = new QWidget(regPage);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMinimumSize(QSize(300, 0));
        verticalLayout_3 = new QVBoxLayout(widget_6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        registerTitle = new QLabel(widget_6);
        registerTitle->setObjectName(QString::fromUtf8("registerTitle"));
        registerTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(registerTitle);

        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        gridLayout_2 = new QGridLayout(widget_7);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_5 = new QLabel(widget_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        label_8 = new QLabel(widget_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 3, 0, 1, 1);

        lineEdit_3 = new QLineEdit(widget_7);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout_2->addWidget(lineEdit_3, 0, 2, 1, 1);

        label_6 = new QLabel(widget_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        lineEdit_5 = new QLineEdit(widget_7);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout_2->addWidget(lineEdit_5, 6, 2, 1, 1);

        lineEdit_4 = new QLineEdit(widget_7);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout_2->addWidget(lineEdit_4, 2, 2, 1, 1);

        lineEdit_6 = new QLineEdit(widget_7);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout_2->addWidget(lineEdit_6, 5, 2, 1, 1);

        lineEdit_8 = new QLineEdit(widget_7);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        gridLayout_2->addWidget(lineEdit_8, 3, 2, 1, 1);

        label_10 = new QLabel(widget_7);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 1, 0, 1, 1);

        label_7 = new QLabel(widget_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 6, 0, 1, 1);

        label_9 = new QLabel(widget_7);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 5, 0, 1, 1);

        lineEdit_7 = new QLineEdit(widget_7);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        gridLayout_2->addWidget(lineEdit_7, 1, 2, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_11, 0, 1, 1, 1);


        verticalLayout_3->addWidget(widget_7);

        widget_9 = new QWidget(widget_6);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_5 = new QHBoxLayout(widget_9);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_12);

        registreBtn = new QPushButton(widget_9);
        registreBtn->setObjectName(QString::fromUtf8("registreBtn"));

        horizontalLayout_5->addWidget(registreBtn);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_13);


        verticalLayout_3->addWidget(widget_9);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);


        horizontalLayout_6->addWidget(widget_6);

        horizontalSpacer_8 = new QSpacerItem(39, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        stackedWidget->addWidget(regPage);
        netSetPage = new QWidget();
        netSetPage->setObjectName(QString::fromUtf8("netSetPage"));
        horizontalLayout_8 = new QHBoxLayout(netSetPage);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_18 = new QSpacerItem(31, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_18);

        widget_8 = new QWidget(netSetPage);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setMinimumSize(QSize(300, 0));
        verticalLayout_4 = new QVBoxLayout(widget_8);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        serverSetTitle = new QLabel(widget_8);
        serverSetTitle->setObjectName(QString::fromUtf8("serverSetTitle"));
        serverSetTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(serverSetTitle);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_10);

        widget_10 = new QWidget(widget_8);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        gridLayout_3 = new QGridLayout(widget_10);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_12 = new QLabel(widget_10);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_3->addWidget(label_12, 0, 0, 1, 1);

        lineEdit_10 = new QLineEdit(widget_10);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        gridLayout_3->addWidget(lineEdit_10, 2, 1, 1, 1);

        lineEdit_9 = new QLineEdit(widget_10);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        gridLayout_3->addWidget(lineEdit_9, 0, 1, 1, 1);

        label_13 = new QLabel(widget_10);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 2, 0, 1, 1);

        verticalSpacer_11 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_11, 1, 0, 1, 1);


        verticalLayout_4->addWidget(widget_10);

        widget_12 = new QWidget(widget_8);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        horizontalLayout_7 = new QHBoxLayout(widget_12);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_16);

        setOkBtn = new QPushButton(widget_12);
        setOkBtn->setObjectName(QString::fromUtf8("setOkBtn"));

        horizontalLayout_7->addWidget(setOkBtn);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_17);


        verticalLayout_4->addWidget(widget_12);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_6);


        horizontalLayout_8->addWidget(widget_8);

        horizontalSpacer_9 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);

        stackedWidget->addWidget(netSetPage);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(Login);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        loginTitle->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201:", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215:", nullptr));
        rememberPwd->setText(QCoreApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        regAccount->setText(QCoreApplication::translate("Login", "\346\262\241\346\234\211\350\264\246\345\217\267, \351\251\254\344\270\212\346\263\250\345\206\214", nullptr));
        loginButton->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        registerTitle->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        label_5->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_8->setText(QCoreApplication::translate("Login", "\347\241\256\350\256\244\345\257\206\347\240\201:", nullptr));
        label_6->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201:", nullptr));
        label_10->setText(QCoreApplication::translate("Login", "\346\230\265\347\247\260:", nullptr));
        label_7->setText(QCoreApplication::translate("Login", "\351\202\256\347\256\261:", nullptr));
        label_9->setText(QCoreApplication::translate("Login", "\347\224\265\350\257\235:", nullptr));
        registreBtn->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        serverSetTitle->setText(QCoreApplication::translate("Login", "\346\234\215\345\212\241\345\231\250\350\256\276\347\275\256", nullptr));
        label_12->setText(QCoreApplication::translate("Login", "\346\234\215\345\212\241\345\231\250IP:", nullptr));
        label_13->setText(QCoreApplication::translate("Login", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243:", nullptr));
        setOkBtn->setText(QCoreApplication::translate("Login", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

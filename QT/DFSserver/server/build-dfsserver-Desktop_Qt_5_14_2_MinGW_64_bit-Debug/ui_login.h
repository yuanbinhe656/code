/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <selfwidget/mytitlebar.h>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout_4;
    MyTitleBar *myToolBar;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *log_usr;
    QLabel *label_3;
    QLineEdit *log_pwd;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QCheckBox *rember_pwd;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *regAccount;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *login_btn;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QWidget *regPage;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_14;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_4;
    QWidget *widget_6;
    QGridLayout *gridLayout_2;
    QLineEdit *reg_passwd;
    QLabel *label_6;
    QLineEdit *reg_phone;
    QLineEdit *reg_userName;
    QLabel *label_5;
    QLineEdit *reg_confirmPwd;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *reg_NickName;
    QLabel *label_9;
    QLineEdit *reg_mail;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *regButton;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_13;
    QWidget *setPage;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_18;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_11;
    QWidget *widget_9;
    QGridLayout *gridLayout_3;
    QLabel *label_12;
    QLineEdit *ip;
    QLabel *label_13;
    QLineEdit *port;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *set;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_17;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(600, 400);
        gridLayout_4 = new QGridLayout(Login);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        myToolBar = new MyTitleBar(Login);
        myToolBar->setObjectName(QString::fromUtf8("myToolBar"));

        gridLayout_4->addWidget(myToolBar, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(Login);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        loginPage = new QWidget();
        loginPage->setObjectName(QString::fromUtf8("loginPage"));
        widget = new QWidget(loginPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 10, 401, 331));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        log_usr = new QLineEdit(widget_2);
        log_usr->setObjectName(QString::fromUtf8("log_usr"));

        gridLayout->addWidget(log_usr, 0, 1, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        log_pwd = new QLineEdit(widget_2);
        log_pwd->setObjectName(QString::fromUtf8("log_pwd"));

        gridLayout->addWidget(log_pwd, 1, 1, 1, 1);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        rember_pwd = new QCheckBox(widget_3);
        rember_pwd->setObjectName(QString::fromUtf8("rember_pwd"));

        horizontalLayout->addWidget(rember_pwd);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        regAccount = new QPushButton(widget_3);
        regAccount->setObjectName(QString::fromUtf8("regAccount"));

        horizontalLayout->addWidget(regAccount);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        login_btn = new QPushButton(widget_4);
        login_btn->setObjectName(QString::fromUtf8("login_btn"));

        horizontalLayout_2->addWidget(login_btn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addWidget(widget_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        stackedWidget->addWidget(loginPage);
        regPage = new QWidget();
        regPage->setObjectName(QString::fromUtf8("regPage"));
        horizontalLayout_6 = new QHBoxLayout(regPage);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_14 = new QSpacerItem(146, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_14);

        widget_5 = new QWidget(regPage);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        verticalLayout_3 = new QVBoxLayout(widget_5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);

        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        gridLayout_2 = new QGridLayout(widget_6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        reg_passwd = new QLineEdit(widget_6);
        reg_passwd->setObjectName(QString::fromUtf8("reg_passwd"));

        gridLayout_2->addWidget(reg_passwd, 2, 1, 1, 1);

        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        reg_phone = new QLineEdit(widget_6);
        reg_phone->setObjectName(QString::fromUtf8("reg_phone"));

        gridLayout_2->addWidget(reg_phone, 5, 1, 1, 1);

        reg_userName = new QLineEdit(widget_6);
        reg_userName->setObjectName(QString::fromUtf8("reg_userName"));

        gridLayout_2->addWidget(reg_userName, 0, 1, 1, 1);

        label_5 = new QLabel(widget_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        reg_confirmPwd = new QLineEdit(widget_6);
        reg_confirmPwd->setObjectName(QString::fromUtf8("reg_confirmPwd"));

        gridLayout_2->addWidget(reg_confirmPwd, 3, 1, 1, 1);

        label_10 = new QLabel(widget_6);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 4, 0, 1, 1);

        label_7 = new QLabel(widget_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 3, 0, 1, 1);

        label_8 = new QLabel(widget_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        reg_NickName = new QLineEdit(widget_6);
        reg_NickName->setObjectName(QString::fromUtf8("reg_NickName"));

        gridLayout_2->addWidget(reg_NickName, 1, 1, 1, 1);

        label_9 = new QLabel(widget_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 5, 0, 1, 1);

        reg_mail = new QLineEdit(widget_6);
        reg_mail->setObjectName(QString::fromUtf8("reg_mail"));

        gridLayout_2->addWidget(reg_mail, 4, 1, 1, 1);


        verticalLayout_3->addWidget(widget_6);

        widget_8 = new QWidget(widget_5);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_5 = new QHBoxLayout(widget_8);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        regButton = new QPushButton(widget_8);
        regButton->setObjectName(QString::fromUtf8("regButton"));

        horizontalLayout_5->addWidget(regButton);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_12);


        verticalLayout_3->addWidget(widget_8);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);


        horizontalLayout_6->addWidget(widget_5);

        horizontalSpacer_13 = new QSpacerItem(146, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_13);

        stackedWidget->addWidget(regPage);
        setPage = new QWidget();
        setPage->setObjectName(QString::fromUtf8("setPage"));
        horizontalLayout_8 = new QHBoxLayout(setPage);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_18 = new QSpacerItem(135, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_18);

        widget_7 = new QWidget(setPage);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        verticalLayout_4 = new QVBoxLayout(widget_7);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        label_11 = new QLabel(widget_7);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_11);

        widget_9 = new QWidget(widget_7);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        gridLayout_3 = new QGridLayout(widget_9);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_12 = new QLabel(widget_9);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_3->addWidget(label_12, 0, 0, 1, 1);

        ip = new QLineEdit(widget_9);
        ip->setObjectName(QString::fromUtf8("ip"));

        gridLayout_3->addWidget(ip, 0, 1, 1, 1);

        label_13 = new QLabel(widget_9);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 1, 0, 1, 1);

        port = new QLineEdit(widget_9);
        port->setObjectName(QString::fromUtf8("port"));

        gridLayout_3->addWidget(port, 1, 1, 1, 1);


        verticalLayout_4->addWidget(widget_9);

        widget_11 = new QWidget(widget_7);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_7 = new QHBoxLayout(widget_11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_15);

        set = new QPushButton(widget_11);
        set->setObjectName(QString::fromUtf8("set"));

        horizontalLayout_7->addWidget(set);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_16);


        verticalLayout_4->addWidget(widget_11);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_6);


        horizontalLayout_8->addWidget(widget_7);

        horizontalSpacer_17 = new QSpacerItem(135, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_17);

        stackedWidget->addWidget(setPage);

        gridLayout_4->addWidget(stackedWidget, 1, 0, 1, 1);


        retranslateUi(Login);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201:", nullptr));
        rember_pwd->setText(QCoreApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        regAccount->setText(QCoreApplication::translate("Login", "\346\262\241\346\234\211\350\264\246\345\217\267, \351\251\254\344\270\212\346\263\250\345\206\214", nullptr));
        login_btn->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        label_4->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        label_6->setText(QCoreApplication::translate("Login", "\346\230\265\347\247\260:", nullptr));
        label_5->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_10->setText(QCoreApplication::translate("Login", "\351\202\256\347\256\261:", nullptr));
        label_7->setText(QCoreApplication::translate("Login", "\347\241\256\350\256\244\345\257\206\347\240\201:", nullptr));
        label_8->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201:", nullptr));
        label_9->setText(QCoreApplication::translate("Login", "\347\224\265\350\257\235:", nullptr));
        regButton->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        label_11->setText(QCoreApplication::translate("Login", "\346\234\215\345\212\241\345\231\250\350\256\276\347\275\256", nullptr));
        label_12->setText(QCoreApplication::translate("Login", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200:", nullptr));
        label_13->setText(QCoreApplication::translate("Login", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243:", nullptr));
        set->setText(QCoreApplication::translate("Login", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

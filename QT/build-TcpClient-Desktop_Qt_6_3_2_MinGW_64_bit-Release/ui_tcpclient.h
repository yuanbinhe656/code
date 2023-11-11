/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpClient
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *text_user_pwd;
    QLineEdit *text_usrs_name;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_register;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_login;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_exit;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName(QString::fromUtf8("TcpClient"));
        TcpClient->resize(558, 405);
        gridLayout_2 = new QGridLayout(TcpClient);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 86, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(63, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(TcpClient);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(18);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(TcpClient);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        text_user_pwd = new QLineEdit(TcpClient);
        text_user_pwd->setObjectName(QString::fromUtf8("text_user_pwd"));
        QFont font1;
        font1.setPointSize(16);
        text_user_pwd->setFont(font1);

        gridLayout->addWidget(text_user_pwd, 1, 1, 1, 1);

        text_usrs_name = new QLineEdit(TcpClient);
        text_usrs_name->setObjectName(QString::fromUtf8("text_usrs_name"));
        text_usrs_name->setFont(font1);

        gridLayout->addWidget(text_usrs_name, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pb_register = new QPushButton(TcpClient);
        pb_register->setObjectName(QString::fromUtf8("pb_register"));
        pb_register->setFont(font1);

        horizontalLayout->addWidget(pb_register);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pb_login = new QPushButton(TcpClient);
        pb_login->setObjectName(QString::fromUtf8("pb_login"));
        pb_login->setFont(font1);

        horizontalLayout->addWidget(pb_login);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pb_exit = new QPushButton(TcpClient);
        pb_exit->setObjectName(QString::fromUtf8("pb_exit"));
        pb_exit->setFont(font1);

        horizontalLayout->addWidget(pb_exit);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout, 1, 1, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(62, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 86, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 2, 1, 1);


        retranslateUi(TcpClient);

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QWidget *TcpClient)
    {
        TcpClient->setWindowTitle(QCoreApplication::translate("TcpClient", "TcpClient", nullptr));
        label_2->setText(QCoreApplication::translate("TcpClient", "\345\257\206  \347\240\201", nullptr));
        label->setText(QCoreApplication::translate("TcpClient", "\347\224\250\346\210\267\345\220\215", nullptr));
        pb_register->setText(QCoreApplication::translate("TcpClient", "\346\263\250\345\206\214", nullptr));
        pb_login->setText(QCoreApplication::translate("TcpClient", "\347\231\273\345\275\225", nullptr));
        pb_exit->setText(QCoreApplication::translate("TcpClient", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H

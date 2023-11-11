/********************************************************************************
** Form generated from reading UI file 'mytitlebar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTITLEBAR_H
#define UI_MYTITLEBAR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyTitleBar
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *logo;
    QLabel *title;
    QSpacerItem *horizontalSpacer;
    QToolButton *setBtn;
    QToolButton *minBtn;
    QToolButton *closeBtn;

    void setupUi(QWidget *MyTitleBar)
    {
        if (MyTitleBar->objectName().isEmpty())
            MyTitleBar->setObjectName(QString::fromUtf8("MyTitleBar"));
        MyTitleBar->setEnabled(true);
        MyTitleBar->resize(431, 66);
        horizontalLayout = new QHBoxLayout(MyTitleBar);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        logo = new QLabel(MyTitleBar);
        logo->setObjectName(QString::fromUtf8("logo"));

        horizontalLayout->addWidget(logo);

        title = new QLabel(MyTitleBar);
        title->setObjectName(QString::fromUtf8("title"));

        horizontalLayout->addWidget(title);

        horizontalSpacer = new QSpacerItem(160, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        setBtn = new QToolButton(MyTitleBar);
        setBtn->setObjectName(QString::fromUtf8("setBtn"));
        setBtn->setEnabled(true);
        setBtn->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/login_setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        setBtn->setIcon(icon);
        setBtn->setIconSize(QSize(35, 35));
        setBtn->setAutoRaise(true);

        horizontalLayout->addWidget(setBtn);

        minBtn = new QToolButton(MyTitleBar);
        minBtn->setObjectName(QString::fromUtf8("minBtn"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/login_min.png"), QSize(), QIcon::Normal, QIcon::Off);
        minBtn->setIcon(icon1);
        minBtn->setIconSize(QSize(35, 35));
        minBtn->setAutoRaise(true);

        horizontalLayout->addWidget(minBtn);

        closeBtn = new QToolButton(MyTitleBar);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/login_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon2);
        closeBtn->setIconSize(QSize(35, 35));
        closeBtn->setAutoRaise(true);

        horizontalLayout->addWidget(closeBtn);


        retranslateUi(MyTitleBar);

        QMetaObject::connectSlotsByName(MyTitleBar);
    } // setupUi

    void retranslateUi(QWidget *MyTitleBar)
    {
        MyTitleBar->setWindowTitle(QCoreApplication::translate("MyTitleBar", "Form", nullptr));
        logo->setText(QString());
        title->setText(QCoreApplication::translate("MyTitleBar", "\344\274\240\346\231\272\346\222\255\345\256\242", nullptr));
        setBtn->setText(QString());
        minBtn->setText(QString());
        closeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyTitleBar: public Ui_MyTitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTITLEBAR_H

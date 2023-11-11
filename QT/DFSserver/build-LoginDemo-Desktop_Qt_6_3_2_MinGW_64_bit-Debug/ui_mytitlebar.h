/********************************************************************************
** Form generated from reading UI file 'mytitlebar.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTITLEBAR_H
#define UI_MYTITLEBAR_H

#include <QtCore/QVariant>
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
    QLabel *logoName;
    QSpacerItem *horizontalSpacer;
    QToolButton *setBtn;
    QToolButton *skinBtn;
    QToolButton *minBtn;
    QToolButton *closeBtn;

    void setupUi(QWidget *MyTitleBar)
    {
        if (MyTitleBar->objectName().isEmpty())
            MyTitleBar->setObjectName(QString::fromUtf8("MyTitleBar"));
        MyTitleBar->resize(442, 38);
        horizontalLayout = new QHBoxLayout(MyTitleBar);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        logo = new QLabel(MyTitleBar);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setMinimumSize(QSize(40, 40));

        horizontalLayout->addWidget(logo);

        logoName = new QLabel(MyTitleBar);
        logoName->setObjectName(QString::fromUtf8("logoName"));

        horizontalLayout->addWidget(logoName);

        horizontalSpacer = new QSpacerItem(235, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        setBtn = new QToolButton(MyTitleBar);
        setBtn->setObjectName(QString::fromUtf8("setBtn"));
        setBtn->setAutoRaise(true);

        horizontalLayout->addWidget(setBtn);

        skinBtn = new QToolButton(MyTitleBar);
        skinBtn->setObjectName(QString::fromUtf8("skinBtn"));
        skinBtn->setAutoRaise(true);

        horizontalLayout->addWidget(skinBtn);

        minBtn = new QToolButton(MyTitleBar);
        minBtn->setObjectName(QString::fromUtf8("minBtn"));
        minBtn->setAutoRaise(true);

        horizontalLayout->addWidget(minBtn);

        closeBtn = new QToolButton(MyTitleBar);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setAutoRaise(true);

        horizontalLayout->addWidget(closeBtn);


        retranslateUi(MyTitleBar);

        QMetaObject::connectSlotsByName(MyTitleBar);
    } // setupUi

    void retranslateUi(QWidget *MyTitleBar)
    {
        MyTitleBar->setWindowTitle(QCoreApplication::translate("MyTitleBar", "Form", nullptr));
        logo->setText(QString());
        logoName->setText(QCoreApplication::translate("MyTitleBar", "TextLabel", nullptr));
        setBtn->setText(QString());
        skinBtn->setText(QString());
        minBtn->setText(QString());
        closeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyTitleBar: public Ui_MyTitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTITLEBAR_H

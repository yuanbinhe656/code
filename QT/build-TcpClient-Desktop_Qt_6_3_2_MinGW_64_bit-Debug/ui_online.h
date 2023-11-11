/********************************************************************************
** Form generated from reading UI file 'online.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLINE_H
#define UI_ONLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_online
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QListWidget *onlienlist;
    QSpacerItem *verticalSpacer;
    QPushButton *addfriend_pb;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *online)
    {
        if (online->objectName().isEmpty())
            online->setObjectName(QString::fromUtf8("online"));
        online->resize(400, 300);
        widget = new QWidget(online);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 40, 358, 194));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        onlienlist = new QListWidget(widget);
        onlienlist->setObjectName(QString::fromUtf8("onlienlist"));

        gridLayout->addWidget(onlienlist, 0, 0, 3, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        addfriend_pb = new QPushButton(widget);
        addfriend_pb->setObjectName(QString::fromUtf8("addfriend_pb"));
        QFont font;
        font.setPointSize(12);
        addfriend_pb->setFont(font);

        gridLayout->addWidget(addfriend_pb, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(online);

        QMetaObject::connectSlotsByName(online);
    } // setupUi

    void retranslateUi(QWidget *online)
    {
        online->setWindowTitle(QCoreApplication::translate("online", "Form", nullptr));
        addfriend_pb->setText(QCoreApplication::translate("online", "\345\212\240\345\245\275\345\217\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class online: public Ui_online {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLINE_H

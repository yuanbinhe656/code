/********************************************************************************
** Form generated from reading UI file 'privatechat.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIVATECHAT_H
#define UI_PRIVATECHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_privatechat
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *send_pb;

    void setupUi(QWidget *privatechat)
    {
        if (privatechat->objectName().isEmpty())
            privatechat->setObjectName(QString::fromUtf8("privatechat"));
        privatechat->resize(400, 300);
        widget = new QWidget(privatechat);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 20, 322, 232));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        send_pb = new QPushButton(widget);
        send_pb->setObjectName(QString::fromUtf8("send_pb"));

        horizontalLayout->addWidget(send_pb);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(privatechat);

        QMetaObject::connectSlotsByName(privatechat);
    } // setupUi

    void retranslateUi(QWidget *privatechat)
    {
        privatechat->setWindowTitle(QCoreApplication::translate("privatechat", "Form", nullptr));
        send_pb->setText(QCoreApplication::translate("privatechat", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class privatechat: public Ui_privatechat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIVATECHAT_H

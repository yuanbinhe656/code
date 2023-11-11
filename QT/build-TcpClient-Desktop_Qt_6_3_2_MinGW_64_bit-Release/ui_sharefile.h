/********************************************************************************
** Form generated from reading UI file 'sharefile.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHAREFILE_H
#define UI_SHAREFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShareFile
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *selectAll_pb;
    QPushButton *cancelsSelect_pb;
    QScrollArea *PSA;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ok_pb;
    QPushButton *cancel_pb;

    void setupUi(QWidget *ShareFile)
    {
        if (ShareFile->objectName().isEmpty())
            ShareFile->setObjectName(QString::fromUtf8("ShareFile"));
        ShareFile->resize(400, 300);
        widget = new QWidget(ShareFile);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 50, 221, 195));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        selectAll_pb = new QPushButton(widget);
        selectAll_pb->setObjectName(QString::fromUtf8("selectAll_pb"));
        QFont font;
        font.setPointSize(16);
        selectAll_pb->setFont(font);

        horizontalLayout->addWidget(selectAll_pb);

        cancelsSelect_pb = new QPushButton(widget);
        cancelsSelect_pb->setObjectName(QString::fromUtf8("cancelsSelect_pb"));
        cancelsSelect_pb->setFont(font);

        horizontalLayout->addWidget(cancelsSelect_pb);


        verticalLayout->addLayout(horizontalLayout);

        PSA = new QScrollArea(widget);
        PSA->setObjectName(QString::fromUtf8("PSA"));
        PSA->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 217, 85));
        PSA->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(PSA);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ok_pb = new QPushButton(widget);
        ok_pb->setObjectName(QString::fromUtf8("ok_pb"));
        ok_pb->setFont(font);

        horizontalLayout_2->addWidget(ok_pb);

        cancel_pb = new QPushButton(widget);
        cancel_pb->setObjectName(QString::fromUtf8("cancel_pb"));
        cancel_pb->setFont(font);

        horizontalLayout_2->addWidget(cancel_pb);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ShareFile);

        QMetaObject::connectSlotsByName(ShareFile);
    } // setupUi

    void retranslateUi(QWidget *ShareFile)
    {
        ShareFile->setWindowTitle(QCoreApplication::translate("ShareFile", "Form", nullptr));
        selectAll_pb->setText(QCoreApplication::translate("ShareFile", "\345\205\250\351\200\211", nullptr));
        cancelsSelect_pb->setText(QCoreApplication::translate("ShareFile", "\345\217\226\346\266\210\345\205\250\351\200\211", nullptr));
        ok_pb->setText(QCoreApplication::translate("ShareFile", "\347\241\256\350\256\244", nullptr));
        cancel_pb->setText(QCoreApplication::translate("ShareFile", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShareFile: public Ui_ShareFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAREFILE_H

/********************************************************************************
** Form generated from reading UI file 'sharelist.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHARELIST_H
#define UI_SHARELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShareList
{
public:
    QListWidget *listWidget;

    void setupUi(QWidget *ShareList)
    {
        if (ShareList->objectName().isEmpty())
            ShareList->setObjectName(QString::fromUtf8("ShareList"));
        ShareList->resize(75, 550);
        listWidget = new QListWidget(ShareList);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 745, 550));

        retranslateUi(ShareList);

        QMetaObject::connectSlotsByName(ShareList);
    } // setupUi

    void retranslateUi(QWidget *ShareList)
    {
        ShareList->setWindowTitle(QCoreApplication::translate("ShareList", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShareList: public Ui_ShareList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHARELIST_H

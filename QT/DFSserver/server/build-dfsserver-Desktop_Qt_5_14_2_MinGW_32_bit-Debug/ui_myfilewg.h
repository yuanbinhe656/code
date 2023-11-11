/********************************************************************************
** Form generated from reading UI file 'myfilewg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFILEWG_H
#define UI_MYFILEWG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyFileWg
{
public:
    QListWidget *listWidget;

    void setupUi(QWidget *MyFileWg)
    {
        if (MyFileWg->objectName().isEmpty())
            MyFileWg->setObjectName(QString::fromUtf8("MyFileWg"));
        MyFileWg->resize(745, 550);
        listWidget = new QListWidget(MyFileWg);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 745, 550));

        retranslateUi(MyFileWg);

        QMetaObject::connectSlotsByName(MyFileWg);
    } // setupUi

    void retranslateUi(QWidget *MyFileWg)
    {
        MyFileWg->setWindowTitle(QCoreApplication::translate("MyFileWg", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyFileWg: public Ui_MyFileWg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFILEWG_H

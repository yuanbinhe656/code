/********************************************************************************
** Form generated from reading UI file 'rankinglist.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKINGLIST_H
#define UI_RANKINGLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RankingList
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *RankingList)
    {
        if (RankingList->objectName().isEmpty())
            RankingList->setObjectName(QString::fromUtf8("RankingList"));
        RankingList->resize(745, 550);
        tableWidget = new QTableWidget(RankingList);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 745, 550));
        tableWidget->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\260\345\256\213\344\275\223\";"));

        retranslateUi(RankingList);

        QMetaObject::connectSlotsByName(RankingList);
    } // setupUi

    void retranslateUi(QWidget *RankingList)
    {
        RankingList->setWindowTitle(QCoreApplication::translate("RankingList", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RankingList: public Ui_RankingList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKINGLIST_H

/********************************************************************************
** Form generated from reading UI file 'opewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPEWIDGET_H
#define UI_OPEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_opewidget
{
public:
    QListWidget *listWidget;

    void setupUi(QWidget *opewidget)
    {
        if (opewidget->objectName().isEmpty())
            opewidget->setObjectName(QString::fromUtf8("opewidget"));
        opewidget->resize(1137, 400);
        listWidget = new QListWidget(opewidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 50, 192));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);

        retranslateUi(opewidget);

        QMetaObject::connectSlotsByName(opewidget);
    } // setupUi

    void retranslateUi(QWidget *opewidget)
    {
        opewidget->setWindowTitle(QCoreApplication::translate("opewidget", "Form", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("opewidget", "\345\245\275\345\217\213", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("opewidget", "\345\233\276\344\271\246", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class opewidget: public Ui_opewidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPEWIDGET_H

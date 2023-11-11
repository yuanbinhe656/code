/********************************************************************************
** Form generated from reading UI file 'movefile.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVEFILE_H
#define UI_MOVEFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MoveFile
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QListWidget *dir_lw;
    QHBoxLayout *horizontalLayout;
    QPushButton *ok_pb;
    QPushButton *cancel_pb;

    void setupUi(QWidget *MoveFile)
    {
        if (MoveFile->objectName().isEmpty())
            MoveFile->setObjectName(QString::fromUtf8("MoveFile"));
        MoveFile->resize(400, 300);
        widget = new QWidget(MoveFile);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 20, 258, 252));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        dir_lw = new QListWidget(widget);
        dir_lw->setObjectName(QString::fromUtf8("dir_lw"));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(24);
        dir_lw->setFont(font);

        verticalLayout->addWidget(dir_lw);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ok_pb = new QPushButton(widget);
        ok_pb->setObjectName(QString::fromUtf8("ok_pb"));
        ok_pb->setFont(font);

        horizontalLayout->addWidget(ok_pb);

        cancel_pb = new QPushButton(widget);
        cancel_pb->setObjectName(QString::fromUtf8("cancel_pb"));
        cancel_pb->setFont(font);

        horizontalLayout->addWidget(cancel_pb);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MoveFile);

        QMetaObject::connectSlotsByName(MoveFile);
    } // setupUi

    void retranslateUi(QWidget *MoveFile)
    {
        MoveFile->setWindowTitle(QCoreApplication::translate("MoveFile", "Form", nullptr));
        ok_pb->setText(QCoreApplication::translate("MoveFile", "\347\241\256\345\256\232", nullptr));
        cancel_pb->setText(QCoreApplication::translate("MoveFile", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MoveFile: public Ui_MoveFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVEFILE_H

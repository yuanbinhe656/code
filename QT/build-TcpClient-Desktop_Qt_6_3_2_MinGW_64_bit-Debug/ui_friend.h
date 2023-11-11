/********************************************************************************
** Form generated from reading UI file 'friend.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIEND_H
#define UI_FRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_friend
{
public:
    QListWidget *listWidget;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;

    void setupUi(QWidget *friend)
    {
        if (friend->objectName().isEmpty())
            friend->setObjectName(QString::fromUtf8("friend"));
        friend->resize(457, 346);
        listWidget = new QListWidget(friend);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(210, 60, 191, 192));
        textEdit = new QTextEdit(friend);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 50, 161, 201));
        lineEdit = new QLineEdit(friend);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 280, 181, 41));
        QFont font;
        font.setPointSize(14);
        lineEdit->setFont(font);
        lineEdit->setCursor(QCursor(Qt::SizeFDiagCursor));

        retranslateUi(friend);

        QMetaObject::connectSlotsByName(friend);
    } // setupUi

    void retranslateUi(QWidget *friend)
    {
        friend->setWindowTitle(QCoreApplication::translate("friend", "Form", nullptr));
        lineEdit->setText(QCoreApplication::translate("friend", "ga", nullptr));
    } // retranslateUi

};

namespace Ui {
    class friend: public Ui_friend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIEND_H

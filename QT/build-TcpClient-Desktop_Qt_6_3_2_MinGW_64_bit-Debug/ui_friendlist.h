/********************************************************************************
** Form generated from reading UI file 'friendlist.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDLIST_H
#define UI_FRIENDLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_friendlist
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hor;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTextEdit *show_Msg_text;
    QListWidget *friendlist_list;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *inputTX;
    QVBoxLayout *verticalLayout;
    QPushButton *delFriend_pb;
    QPushButton *flush_pb;
    QPushButton *showOnline_pb;
    QPushButton *serchFriend_pb;
    QPushButton *chat_pb;
    QPushButton *sendMsg_pb;

    void setupUi(QWidget *friendlist)
    {
        if (friendlist->objectName().isEmpty())
            friendlist->setObjectName(QString::fromUtf8("friendlist"));
        friendlist->resize(755, 487);
        layoutWidget = new QWidget(friendlist);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(44, 16, 681, 273));
        hor = new QHBoxLayout(layoutWidget);
        hor->setObjectName(QString::fromUtf8("hor"));
        hor->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        show_Msg_text = new QTextEdit(layoutWidget);
        show_Msg_text->setObjectName(QString::fromUtf8("show_Msg_text"));
        show_Msg_text->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(show_Msg_text);

        friendlist_list = new QListWidget(layoutWidget);
        friendlist_list->setObjectName(QString::fromUtf8("friendlist_list"));
        friendlist_list->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(friendlist_list);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        inputTX = new QLineEdit(layoutWidget);
        inputTX->setObjectName(QString::fromUtf8("inputTX"));

        horizontalLayout_2->addWidget(inputTX);


        verticalLayout_2->addLayout(horizontalLayout_2);


        hor->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        delFriend_pb = new QPushButton(layoutWidget);
        delFriend_pb->setObjectName(QString::fromUtf8("delFriend_pb"));
        QFont font;
        font.setPointSize(14);
        delFriend_pb->setFont(font);

        verticalLayout->addWidget(delFriend_pb);

        flush_pb = new QPushButton(layoutWidget);
        flush_pb->setObjectName(QString::fromUtf8("flush_pb"));
        flush_pb->setFont(font);

        verticalLayout->addWidget(flush_pb);

        showOnline_pb = new QPushButton(layoutWidget);
        showOnline_pb->setObjectName(QString::fromUtf8("showOnline_pb"));
        showOnline_pb->setFont(font);

        verticalLayout->addWidget(showOnline_pb);

        serchFriend_pb = new QPushButton(layoutWidget);
        serchFriend_pb->setObjectName(QString::fromUtf8("serchFriend_pb"));
        serchFriend_pb->setFont(font);

        verticalLayout->addWidget(serchFriend_pb);

        chat_pb = new QPushButton(layoutWidget);
        chat_pb->setObjectName(QString::fromUtf8("chat_pb"));
        chat_pb->setFont(font);

        verticalLayout->addWidget(chat_pb);

        sendMsg_pb = new QPushButton(layoutWidget);
        sendMsg_pb->setObjectName(QString::fromUtf8("sendMsg_pb"));
        sendMsg_pb->setFont(font);

        verticalLayout->addWidget(sendMsg_pb);


        hor->addLayout(verticalLayout);


        retranslateUi(friendlist);

        QMetaObject::connectSlotsByName(friendlist);
    } // setupUi

    void retranslateUi(QWidget *friendlist)
    {
        friendlist->setWindowTitle(QCoreApplication::translate("friendlist", "Form", nullptr));
        delFriend_pb->setText(QCoreApplication::translate("friendlist", "\345\210\240\351\231\244\345\245\275\345\217\213", nullptr));
        flush_pb->setText(QCoreApplication::translate("friendlist", "\345\210\267\346\226\260\345\245\275\345\217\213", nullptr));
        showOnline_pb->setText(QCoreApplication::translate("friendlist", "\346\230\276\347\244\272\345\234\250\347\272\277\347\224\250\346\210\267", nullptr));
        serchFriend_pb->setText(QCoreApplication::translate("friendlist", "\346\237\245\346\211\276\347\224\250\346\210\267", nullptr));
        chat_pb->setText(QCoreApplication::translate("friendlist", "\347\247\201\350\201\212", nullptr));
        sendMsg_pb->setText(QCoreApplication::translate("friendlist", "\344\277\241\346\201\257\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class friendlist: public Ui_friendlist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDLIST_H

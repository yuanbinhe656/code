/********************************************************************************
** Form generated from reading UI file 'book.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOK_H
#define UI_BOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_book
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *bookList;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *return_pb;
    QPushButton *create_pb;
    QPushButton *deldir_pb;
    QPushButton *rename_pb;
    QPushButton *flushfile_pb;
    QVBoxLayout *verticalLayout_2;
    QPushButton *upload_pb;
    QPushButton *download_pb;
    QPushButton *delfile_pb;
    QPushButton *sharefile_pb;
    QPushButton *movefile_pb;
    QPushButton *selectdir_pb;

    void setupUi(QWidget *book)
    {
        if (book->objectName().isEmpty())
            book->setObjectName(QString::fromUtf8("book"));
        book->resize(940, 391);
        widget = new QWidget(book);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 539, 350));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        bookList = new QListWidget(widget);
        bookList->setObjectName(QString::fromUtf8("bookList"));

        horizontalLayout_2->addWidget(bookList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        return_pb = new QPushButton(widget);
        return_pb->setObjectName(QString::fromUtf8("return_pb"));
        QFont font;
        font.setPointSize(16);
        return_pb->setFont(font);

        verticalLayout->addWidget(return_pb);

        create_pb = new QPushButton(widget);
        create_pb->setObjectName(QString::fromUtf8("create_pb"));
        create_pb->setFont(font);

        verticalLayout->addWidget(create_pb);

        deldir_pb = new QPushButton(widget);
        deldir_pb->setObjectName(QString::fromUtf8("deldir_pb"));
        deldir_pb->setFont(font);

        verticalLayout->addWidget(deldir_pb);

        rename_pb = new QPushButton(widget);
        rename_pb->setObjectName(QString::fromUtf8("rename_pb"));
        rename_pb->setFont(font);

        verticalLayout->addWidget(rename_pb);

        flushfile_pb = new QPushButton(widget);
        flushfile_pb->setObjectName(QString::fromUtf8("flushfile_pb"));
        flushfile_pb->setFont(font);

        verticalLayout->addWidget(flushfile_pb);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        upload_pb = new QPushButton(widget);
        upload_pb->setObjectName(QString::fromUtf8("upload_pb"));
        upload_pb->setFont(font);

        verticalLayout_2->addWidget(upload_pb);

        download_pb = new QPushButton(widget);
        download_pb->setObjectName(QString::fromUtf8("download_pb"));
        download_pb->setFont(font);

        verticalLayout_2->addWidget(download_pb);

        delfile_pb = new QPushButton(widget);
        delfile_pb->setObjectName(QString::fromUtf8("delfile_pb"));
        delfile_pb->setFont(font);

        verticalLayout_2->addWidget(delfile_pb);

        sharefile_pb = new QPushButton(widget);
        sharefile_pb->setObjectName(QString::fromUtf8("sharefile_pb"));
        sharefile_pb->setFont(font);

        verticalLayout_2->addWidget(sharefile_pb);

        movefile_pb = new QPushButton(widget);
        movefile_pb->setObjectName(QString::fromUtf8("movefile_pb"));
        movefile_pb->setFont(font);

        verticalLayout_2->addWidget(movefile_pb);

        selectdir_pb = new QPushButton(widget);
        selectdir_pb->setObjectName(QString::fromUtf8("selectdir_pb"));
        selectdir_pb->setFont(font);

        verticalLayout_2->addWidget(selectdir_pb);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(book);

        QMetaObject::connectSlotsByName(book);
    } // setupUi

    void retranslateUi(QWidget *book)
    {
        book->setWindowTitle(QCoreApplication::translate("book", "Form", nullptr));
        return_pb->setText(QCoreApplication::translate("book", "\350\277\224\345\233\236", nullptr));
        create_pb->setText(QCoreApplication::translate("book", "\345\210\233\345\273\272\346\226\207\344\273\266\345\244\271", nullptr));
        deldir_pb->setText(QCoreApplication::translate("book", "\345\210\240\351\231\244\346\226\207\344\273\266\345\244\271", nullptr));
        rename_pb->setText(QCoreApplication::translate("book", "\351\207\215\345\221\275\345\220\215\346\226\207\344\273\266", nullptr));
        flushfile_pb->setText(QCoreApplication::translate("book", "\345\210\267\346\226\260\346\226\207\344\273\266\345\244\271", nullptr));
        upload_pb->setText(QCoreApplication::translate("book", "\344\270\212\344\274\240\346\226\207\344\273\266", nullptr));
        download_pb->setText(QCoreApplication::translate("book", "\344\270\213\350\275\275\346\226\207\344\273\266", nullptr));
        delfile_pb->setText(QCoreApplication::translate("book", "\345\210\240\351\231\244\346\226\207\344\273\266", nullptr));
        sharefile_pb->setText(QCoreApplication::translate("book", "\345\205\261\344\272\253\346\226\207\344\273\266", nullptr));
        movefile_pb->setText(QCoreApplication::translate("book", "\347\247\273\345\212\250\346\226\207\344\273\266", nullptr));
        selectdir_pb->setText(QCoreApplication::translate("book", "\347\233\256\346\240\207\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class book: public Ui_book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOK_H

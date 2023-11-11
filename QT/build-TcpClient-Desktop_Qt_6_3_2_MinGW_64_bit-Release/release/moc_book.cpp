/****************************************************************************
** Meta object code from reading C++ file 'book.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../cloud file/TcpClient/book.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'book.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_book_t {
    uint offsetsAndSizes[34];
    char stringdata0[5];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[21];
    char stringdata5[21];
    char stringdata6[24];
    char stringdata7[21];
    char stringdata8[23];
    char stringdata9[22];
    char stringdata10[24];
    char stringdata11[23];
    char stringdata12[24];
    char stringdata13[15];
    char stringdata14[26];
    char stringdata15[12];
    char stringdata16[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_book_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_book_t qt_meta_stringdata_book = {
    {
        QT_MOC_LITERAL(0, 4),  // "book"
        QT_MOC_LITERAL(5, 20),  // "on_return_pb_clicked"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 20),  // "on_create_pb_clicked"
        QT_MOC_LITERAL(48, 20),  // "on_deldir_pb_clicked"
        QT_MOC_LITERAL(69, 20),  // "on_rename_pb_clicked"
        QT_MOC_LITERAL(90, 23),  // "on_flushfile_pb_clicked"
        QT_MOC_LITERAL(114, 20),  // "on_upload_pb_clicked"
        QT_MOC_LITERAL(135, 22),  // "on_download_pb_clicked"
        QT_MOC_LITERAL(158, 21),  // "on_delfile_pb_clicked"
        QT_MOC_LITERAL(180, 23),  // "on_sharefile_pb_clicked"
        QT_MOC_LITERAL(204, 22),  // "on_movefile_pb_clicked"
        QT_MOC_LITERAL(227, 23),  // "on_selectdir_pb_clicked"
        QT_MOC_LITERAL(251, 14),  // "uploadFileData"
        QT_MOC_LITERAL(266, 25),  // "on_bookList_doubleClicked"
        QT_MOC_LITERAL(292, 11),  // "QModelIndex"
        QT_MOC_LITERAL(304, 5)   // "index"
    },
    "book",
    "on_return_pb_clicked",
    "",
    "on_create_pb_clicked",
    "on_deldir_pb_clicked",
    "on_rename_pb_clicked",
    "on_flushfile_pb_clicked",
    "on_upload_pb_clicked",
    "on_download_pb_clicked",
    "on_delfile_pb_clicked",
    "on_sharefile_pb_clicked",
    "on_movefile_pb_clicked",
    "on_selectdir_pb_clicked",
    "uploadFileData",
    "on_bookList_doubleClicked",
    "QModelIndex",
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_book[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    1 /* Private */,
       3,    0,   93,    2, 0x08,    2 /* Private */,
       4,    0,   94,    2, 0x08,    3 /* Private */,
       5,    0,   95,    2, 0x08,    4 /* Private */,
       6,    0,   96,    2, 0x08,    5 /* Private */,
       7,    0,   97,    2, 0x08,    6 /* Private */,
       8,    0,   98,    2, 0x08,    7 /* Private */,
       9,    0,   99,    2, 0x08,    8 /* Private */,
      10,    0,  100,    2, 0x08,    9 /* Private */,
      11,    0,  101,    2, 0x08,   10 /* Private */,
      12,    0,  102,    2, 0x08,   11 /* Private */,
      13,    0,  103,    2, 0x08,   12 /* Private */,
      14,    1,  104,    2, 0x08,   13 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void book::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<book *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_return_pb_clicked(); break;
        case 1: _t->on_create_pb_clicked(); break;
        case 2: _t->on_deldir_pb_clicked(); break;
        case 3: _t->on_rename_pb_clicked(); break;
        case 4: _t->on_flushfile_pb_clicked(); break;
        case 5: _t->on_upload_pb_clicked(); break;
        case 6: _t->on_download_pb_clicked(); break;
        case 7: _t->on_delfile_pb_clicked(); break;
        case 8: _t->on_sharefile_pb_clicked(); break;
        case 9: _t->on_movefile_pb_clicked(); break;
        case 10: _t->on_selectdir_pb_clicked(); break;
        case 11: _t->uploadFileData(); break;
        case 12: _t->on_bookList_doubleClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject book::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_book.offsetsAndSizes,
    qt_meta_data_book,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_book_t
, QtPrivate::TypeAndForceComplete<book, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>


>,
    nullptr
} };


const QMetaObject *book::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *book::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_book.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int book::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

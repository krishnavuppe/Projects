/****************************************************************************
** Meta object code from reading C++ file 'publisher.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chatbox/publisher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'publisher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CB_Publisher_t {
    QByteArrayData data[9];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CB_Publisher_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CB_Publisher_t qt_meta_stringdata_CB_Publisher = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CB_Publisher"
QT_MOC_LITERAL(1, 13, 9), // "getWriter"
QT_MOC_LITERAL(2, 23, 14), // "DataWriter_ptr"
QT_MOC_LITERAL(3, 38, 0), // ""
QT_MOC_LITERAL(4, 39, 10), // "publishmsg"
QT_MOC_LITERAL(5, 50, 8), // "display1"
QT_MOC_LITERAL(6, 59, 8), // "display2"
QT_MOC_LITERAL(7, 68, 8), // "display3"
QT_MOC_LITERAL(8, 77, 8) // "display4"

    },
    "CB_Publisher\0getWriter\0DataWriter_ptr\0"
    "\0publishmsg\0display1\0display2\0display3\0"
    "display4"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CB_Publisher[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    3, 0x0a /* Public */,
       4,    0,   45,    3, 0x0a /* Public */,
       5,    0,   46,    3, 0x0a /* Public */,
       6,    0,   47,    3, 0x0a /* Public */,
       7,    0,   48,    3, 0x0a /* Public */,
       8,    0,   49,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CB_Publisher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CB_Publisher *_t = static_cast<CB_Publisher *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { DataWriter_ptr _r = _t->getWriter();
            if (_a[0]) *reinterpret_cast< DataWriter_ptr*>(_a[0]) = _r; }  break;
        case 1: _t->publishmsg(); break;
        case 2: _t->display1(); break;
        case 3: _t->display2(); break;
        case 4: _t->display3(); break;
        case 5: _t->display4(); break;
        default: ;
        }
    }
}

const QMetaObject CB_Publisher::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CB_Publisher.data,
      qt_meta_data_CB_Publisher,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CB_Publisher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CB_Publisher::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CB_Publisher.stringdata0))
        return static_cast<void*>(const_cast< CB_Publisher*>(this));
    return QObject::qt_metacast(_clname);
}

int CB_Publisher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

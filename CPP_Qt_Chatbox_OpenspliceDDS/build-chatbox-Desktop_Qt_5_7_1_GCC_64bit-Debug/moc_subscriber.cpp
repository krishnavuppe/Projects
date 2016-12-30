/****************************************************************************
** Meta object code from reading C++ file 'subscriber.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chatbox/subscriber.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'subscriber.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CB_Subscriber_t {
    QByteArrayData data[5];
    char stringdata0[47];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CB_Subscriber_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CB_Subscriber_t qt_meta_stringdata_CB_Subscriber = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CB_Subscriber"
QT_MOC_LITERAL(1, 14, 9), // "getReader"
QT_MOC_LITERAL(2, 24, 14), // "DataReader_ptr"
QT_MOC_LITERAL(3, 39, 0), // ""
QT_MOC_LITERAL(4, 40, 6) // "update"

    },
    "CB_Subscriber\0getReader\0DataReader_ptr\0"
    "\0update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CB_Subscriber[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    3, 0x0a /* Public */,
       4,    0,   25,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void,

       0        // eod
};

void CB_Subscriber::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CB_Subscriber *_t = static_cast<CB_Subscriber *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { DataReader_ptr _r = _t->getReader();
            if (_a[0]) *reinterpret_cast< DataReader_ptr*>(_a[0]) = _r; }  break;
        case 1: _t->update(); break;
        default: ;
        }
    }
}

const QMetaObject CB_Subscriber::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CB_Subscriber.data,
      qt_meta_data_CB_Subscriber,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CB_Subscriber::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CB_Subscriber::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CB_Subscriber.stringdata0))
        return static_cast<void*>(const_cast< CB_Subscriber*>(this));
    return QObject::qt_metacast(_clname);
}

int CB_Subscriber::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'PrintHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PrintHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PrintHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PrintHandler_t {
    QByteArrayData data[7];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PrintHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PrintHandler_t qt_meta_stringdata_PrintHandler = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PrintHandler"
QT_MOC_LITERAL(1, 13, 12), // "workFinished"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 3), // "run"
QT_MOC_LITERAL(4, 31, 9), // "printInfo"
QT_MOC_LITERAL(5, 41, 7), // "AllData"
QT_MOC_LITERAL(6, 49, 1) // "s"

    },
    "PrintHandler\0workFinished\0\0run\0printInfo\0"
    "AllData\0s"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrintHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   30,    2, 0x0a /* Public */,
       4,    1,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void PrintHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PrintHandler *_t = static_cast<PrintHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->workFinished(); break;
        case 1: _t->run(); break;
        case 2: _t->printInfo((*reinterpret_cast< AllData(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PrintHandler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PrintHandler::workFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PrintHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PrintHandler.data,
      qt_meta_data_PrintHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PrintHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrintHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PrintHandler.stringdata0))
        return static_cast<void*>(const_cast< PrintHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int PrintHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PrintHandler::workFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

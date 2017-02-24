/****************************************************************************
** Meta object code from reading C++ file 'regulator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "regulator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'regulator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Regulator_t {
    QByteArrayData data[25];
    char stringdata[316];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Regulator_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Regulator_t qt_meta_stringdata_Regulator = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 14),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 15),
QT_MOC_LITERAL(4, 42, 9),
QT_MOC_LITERAL(5, 52, 8),
QT_MOC_LITERAL(6, 61, 14),
QT_MOC_LITERAL(7, 76, 21),
QT_MOC_LITERAL(8, 98, 12),
QT_MOC_LITERAL(9, 111, 9),
QT_MOC_LITERAL(10, 121, 12),
QT_MOC_LITERAL(11, 134, 14),
QT_MOC_LITERAL(12, 149, 13),
QT_MOC_LITERAL(13, 163, 16),
QT_MOC_LITERAL(14, 180, 9),
QT_MOC_LITERAL(15, 190, 12),
QT_MOC_LITERAL(16, 203, 16),
QT_MOC_LITERAL(17, 220, 9),
QT_MOC_LITERAL(18, 230, 13),
QT_MOC_LITERAL(19, 244, 16),
QT_MOC_LITERAL(20, 261, 10),
QT_MOC_LITERAL(21, 272, 20),
QT_MOC_LITERAL(22, 293, 5),
QT_MOC_LITERAL(23, 299, 11),
QT_MOC_LITERAL(24, 311, 4)
    },
    "Regulator\0regulationOver\0\0regulationBegun\0"
    "testBegun\0testOver\0regulatorError\0"
    "regulatorPortNotFound\0dataSendBack\0"
    "startBack\0shutDownBack\0simulationBack\0"
    "thersholdBack\0regulatorTIMEOUT\0startOver\0"
    "shutDownOver\0monitorActionEnd\0parseData\0"
    "handleTimeout\0handleEndTimeout\0"
    "orderClear\0regulatorinstruction\0order\0"
    "connectname\0name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Regulator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x06 /* Public */,
       3,    0,  115,    2, 0x06 /* Public */,
       4,    0,  116,    2, 0x06 /* Public */,
       5,    0,  117,    2, 0x06 /* Public */,
       6,    0,  118,    2, 0x06 /* Public */,
       7,    0,  119,    2, 0x06 /* Public */,
       8,    0,  120,    2, 0x06 /* Public */,
       9,    0,  121,    2, 0x06 /* Public */,
      10,    0,  122,    2, 0x06 /* Public */,
      11,    0,  123,    2, 0x06 /* Public */,
      12,    0,  124,    2, 0x06 /* Public */,
      13,    0,  125,    2, 0x06 /* Public */,
      14,    0,  126,    2, 0x06 /* Public */,
      15,    0,  127,    2, 0x06 /* Public */,
      16,    0,  128,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    0,  129,    2, 0x0a /* Public */,
      18,    0,  130,    2, 0x0a /* Public */,
      19,    0,  131,    2, 0x0a /* Public */,
      20,    1,  132,    2, 0x0a /* Public */,
      23,    1,  135,    2, 0x0a /* Public */,

 // signals: parameters
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::QString,   24,

       0        // eod
};

void Regulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Regulator *_t = static_cast<Regulator *>(_o);
        switch (_id) {
        case 0: _t->regulationOver(); break;
        case 1: _t->regulationBegun(); break;
        case 2: _t->testBegun(); break;
        case 3: _t->testOver(); break;
        case 4: _t->regulatorError(); break;
        case 5: _t->regulatorPortNotFound(); break;
        case 6: _t->dataSendBack(); break;
        case 7: _t->startBack(); break;
        case 8: _t->shutDownBack(); break;
        case 9: _t->simulationBack(); break;
        case 10: _t->thersholdBack(); break;
        case 11: _t->regulatorTIMEOUT(); break;
        case 12: _t->startOver(); break;
        case 13: _t->shutDownOver(); break;
        case 14: _t->monitorActionEnd(); break;
        case 15: _t->parseData(); break;
        case 16: _t->handleTimeout(); break;
        case 17: _t->handleEndTimeout(); break;
        case 18: _t->orderClear((*reinterpret_cast< regulatorinstruction(*)>(_a[1]))); break;
        case 19: _t->connectname((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Regulator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Regulator::regulationOver)) {
                *result = 0;
            }
        }
        {
            typedef void (Regulator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Regulator::regulationBegun)) {
                *result = 1;
            }
        }
        {
            typedef void (Regulator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Regulator::testBegun)) {
                *result = 2;
            }
        }
        {
            typedef void (Regulator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Regulator::testOver)) {
                *result = 3;
            }
        }
        {
            typedef void (Regulator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Regulator::regulatorError)) {
                *result = 4;
            }
        }
        {
            typedef void (Regulator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Regulator::regulatorPortNotFound)) {
                *result = 5;
            }
        }
        {
            typedef void (Regulator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Regulator::dataSendBack)) {
                *result = 6;
            }
        }
        {
            typedef void (Regulator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Regulator::startBack)) {
                *result = 7;
            }
        }
        {
            typedef void (Regulator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Regulator::shutDownBack)) {
                *result = 8;
            }
        }
        {
            typedef void (Regulator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Regulator::simulationBack)) {
                *result = 9;
            }
        }
        {
            typedef void (Regulator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Regulator::thersholdBack)) {
                *result = 10;
            }
        }
        {
            typedef void (Regulator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Regulator::regulatorTIMEOUT)) {
                *result = 11;
            }
        }
        {
            typedef void (Regulator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Regulator::startOver)) {
                *result = 12;
            }
        }
        {
            typedef void (Regulator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Regulator::shutDownOver)) {
                *result = 13;
            }
        }
        {
            typedef void (Regulator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Regulator::monitorActionEnd)) {
                *result = 14;
            }
        }
    }
}

const QMetaObject Regulator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Regulator.data,
      qt_meta_data_Regulator,  qt_static_metacall, 0, 0}
};


const QMetaObject *Regulator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Regulator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Regulator.stringdata))
        return static_cast<void*>(const_cast< Regulator*>(this));
    return QObject::qt_metacast(_clname);
}

int Regulator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void Regulator::regulationOver()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Regulator::regulationBegun()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Regulator::testBegun()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Regulator::testOver()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Regulator::regulatorError()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Regulator::regulatorPortNotFound()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void Regulator::dataSendBack()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void Regulator::startBack()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void Regulator::shutDownBack()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void Regulator::simulationBack()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}

// SIGNAL 10
void Regulator::thersholdBack()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}

// SIGNAL 11
void Regulator::regulatorTIMEOUT()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void Regulator::startOver()
{
    QMetaObject::activate(this, &staticMetaObject, 12, 0);
}

// SIGNAL 13
void Regulator::shutDownOver()
{
    QMetaObject::activate(this, &staticMetaObject, 13, 0);
}

// SIGNAL 14
void Regulator::monitorActionEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}
QT_END_MOC_NAMESPACE

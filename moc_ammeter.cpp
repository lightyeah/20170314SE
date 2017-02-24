/****************************************************************************
** Meta object code from reading C++ file 'ammeter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ammeter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ammeter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Ammeter_t {
    QByteArrayData data[23];
    char stringdata[326];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ammeter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ammeter_t qt_meta_stringdata_Ammeter = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 14),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 14),
QT_MOC_LITERAL(4, 39, 21),
QT_MOC_LITERAL(5, 61, 20),
QT_MOC_LITERAL(6, 82, 20),
QT_MOC_LITERAL(7, 103, 18),
QT_MOC_LITERAL(8, 122, 11),
QT_MOC_LITERAL(9, 134, 12),
QT_MOC_LITERAL(10, 147, 15),
QT_MOC_LITERAL(11, 163, 9),
QT_MOC_LITERAL(12, 173, 17),
QT_MOC_LITERAL(13, 191, 13),
QT_MOC_LITERAL(14, 205, 10),
QT_MOC_LITERAL(15, 216, 10),
QT_MOC_LITERAL(16, 227, 17),
QT_MOC_LITERAL(17, 245, 16),
QT_MOC_LITERAL(18, 262, 16),
QT_MOC_LITERAL(19, 279, 14),
QT_MOC_LITERAL(20, 294, 14),
QT_MOC_LITERAL(21, 309, 11),
QT_MOC_LITERAL(22, 321, 4)
    },
    "Ammeter\0voltageDataGot\0\0currentDataGot\0"
    "effectivePowerDataGot\0reactivePowerDataGot\0"
    "apparentPowerDataGot\0powerFactorDataGot\0"
    "getDataOver\0ammeterError\0ammeterNotFound\0"
    "parseData\0startTimeoutTimer\0handleTimeOut\0"
    "getVoltage\0getCurrent\0getEffectivePower\0"
    "getReactivePower\0getApparentPower\0"
    "getPowerFactor\0startReadTimer\0connectname\0"
    "name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ammeter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

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

 // slots: name, argc, parameters, tag, flags
      11,    0,  123,    2, 0x0a /* Public */,
      12,    0,  124,    2, 0x0a /* Public */,
      13,    0,  125,    2, 0x0a /* Public */,
      14,    0,  126,    2, 0x0a /* Public */,
      15,    0,  127,    2, 0x0a /* Public */,
      16,    0,  128,    2, 0x0a /* Public */,
      17,    0,  129,    2, 0x0a /* Public */,
      18,    0,  130,    2, 0x0a /* Public */,
      19,    0,  131,    2, 0x0a /* Public */,
      20,    0,  132,    2, 0x0a /* Public */,
      21,    1,  133,    2, 0x0a /* Public */,

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
    QMetaType::Void, QMetaType::QString,   22,

       0        // eod
};

void Ammeter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ammeter *_t = static_cast<Ammeter *>(_o);
        switch (_id) {
        case 0: _t->voltageDataGot(); break;
        case 1: _t->currentDataGot(); break;
        case 2: _t->effectivePowerDataGot(); break;
        case 3: _t->reactivePowerDataGot(); break;
        case 4: _t->apparentPowerDataGot(); break;
        case 5: _t->powerFactorDataGot(); break;
        case 6: _t->getDataOver(); break;
        case 7: _t->ammeterError(); break;
        case 8: _t->ammeterNotFound(); break;
        case 9: _t->parseData(); break;
        case 10: _t->startTimeoutTimer(); break;
        case 11: _t->handleTimeOut(); break;
        case 12: _t->getVoltage(); break;
        case 13: _t->getCurrent(); break;
        case 14: _t->getEffectivePower(); break;
        case 15: _t->getReactivePower(); break;
        case 16: _t->getApparentPower(); break;
        case 17: _t->getPowerFactor(); break;
        case 18: _t->startReadTimer(); break;
        case 19: _t->connectname((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Ammeter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ammeter::voltageDataGot)) {
                *result = 0;
            }
        }
        {
            typedef void (Ammeter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ammeter::currentDataGot)) {
                *result = 1;
            }
        }
        {
            typedef void (Ammeter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ammeter::effectivePowerDataGot)) {
                *result = 2;
            }
        }
        {
            typedef void (Ammeter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ammeter::reactivePowerDataGot)) {
                *result = 3;
            }
        }
        {
            typedef void (Ammeter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ammeter::apparentPowerDataGot)) {
                *result = 4;
            }
        }
        {
            typedef void (Ammeter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ammeter::powerFactorDataGot)) {
                *result = 5;
            }
        }
        {
            typedef void (Ammeter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ammeter::getDataOver)) {
                *result = 6;
            }
        }
        {
            typedef void (Ammeter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ammeter::ammeterError)) {
                *result = 7;
            }
        }
        {
            typedef void (Ammeter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ammeter::ammeterNotFound)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject Ammeter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ammeter.data,
      qt_meta_data_Ammeter,  qt_static_metacall, 0, 0}
};


const QMetaObject *Ammeter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ammeter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ammeter.stringdata))
        return static_cast<void*>(const_cast< Ammeter*>(this));
    return QObject::qt_metacast(_clname);
}

int Ammeter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Ammeter::voltageDataGot()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Ammeter::currentDataGot()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Ammeter::effectivePowerDataGot()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Ammeter::reactivePowerDataGot()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Ammeter::apparentPowerDataGot()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Ammeter::powerFactorDataGot()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void Ammeter::getDataOver()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void Ammeter::ammeterError()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void Ammeter::ammeterNotFound()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE

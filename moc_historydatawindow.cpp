/****************************************************************************
** Meta object code from reading C++ file 'historydatawindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "historydatawindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'historydatawindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HistoryDataWindow_t {
    QByteArrayData data[15];
    char stringdata[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HistoryDataWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HistoryDataWindow_t qt_meta_stringdata_HistoryDataWindow = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 20),
QT_MOC_LITERAL(2, 39, 0),
QT_MOC_LITERAL(3, 40, 7),
QT_MOC_LITERAL(4, 48, 20),
QT_MOC_LITERAL(5, 69, 21),
QT_MOC_LITERAL(6, 91, 21),
QT_MOC_LITERAL(7, 113, 21),
QT_MOC_LITERAL(8, 135, 21),
QT_MOC_LITERAL(9, 157, 22),
QT_MOC_LITERAL(10, 180, 20),
QT_MOC_LITERAL(11, 201, 20),
QT_MOC_LITERAL(12, 222, 20),
QT_MOC_LITERAL(13, 243, 18),
QT_MOC_LITERAL(14, 262, 18)
    },
    "HistoryDataWindow\0on_vRadioBtn_toggled\0"
    "\0checked\0on_iRadioBtn_toggled\0"
    "on_epRadioBtn_toggled\0on_fpRadioBtn_toggled\0"
    "on_apRadioBtn_toggled\0on_pfRadioBtn_toggled\0"
    "on_setRangeBtn_clicked\0on_returnBtn_clicked\0"
    "on_sincBtn_2_clicked\0on_sdecBtn_2_clicked\0"
    "on_eincBtn_clicked\0on_edecBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HistoryDataWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    1,   77,    2, 0x08 /* Private */,
       5,    1,   80,    2, 0x08 /* Private */,
       6,    1,   83,    2, 0x08 /* Private */,
       7,    1,   86,    2, 0x08 /* Private */,
       8,    1,   89,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HistoryDataWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HistoryDataWindow *_t = static_cast<HistoryDataWindow *>(_o);
        switch (_id) {
        case 0: _t->on_vRadioBtn_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_iRadioBtn_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_epRadioBtn_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_fpRadioBtn_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_apRadioBtn_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_pfRadioBtn_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_setRangeBtn_clicked(); break;
        case 7: _t->on_returnBtn_clicked(); break;
        case 8: _t->on_sincBtn_2_clicked(); break;
        case 9: _t->on_sdecBtn_2_clicked(); break;
        case 10: _t->on_eincBtn_clicked(); break;
        case 11: _t->on_edecBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject HistoryDataWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HistoryDataWindow.data,
      qt_meta_data_HistoryDataWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *HistoryDataWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HistoryDataWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HistoryDataWindow.stringdata))
        return static_cast<void*>(const_cast< HistoryDataWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int HistoryDataWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

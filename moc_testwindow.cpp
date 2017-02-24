/****************************************************************************
** Meta object code from reading C++ file 'testwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "testwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TestWindow_t {
    QByteArrayData data[12];
    char stringdata[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestWindow_t qt_meta_stringdata_TestWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 17),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 20),
QT_MOC_LITERAL(4, 51, 27),
QT_MOC_LITERAL(5, 79, 20),
QT_MOC_LITERAL(6, 100, 31),
QT_MOC_LITERAL(7, 132, 9),
QT_MOC_LITERAL(8, 142, 8),
QT_MOC_LITERAL(9, 151, 11),
QT_MOC_LITERAL(10, 163, 10),
QT_MOC_LITERAL(11, 174, 5)
    },
    "TestWindow\0testButtonClicked\0\0"
    "on_beginTest_clicked\0on_clearTestRecords_clicked\0"
    "on_returnBtn_clicked\0"
    "on_calculateRatioButton_clicked\0"
    "getResult\0datatype\0powerBefore\0"
    "powerAfter\0ratio"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    3,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8, QMetaType::Float,    9,   10,   11,

       0        // eod
};

void TestWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestWindow *_t = static_cast<TestWindow *>(_o);
        switch (_id) {
        case 0: _t->testButtonClicked(); break;
        case 1: _t->on_beginTest_clicked(); break;
        case 2: _t->on_clearTestRecords_clicked(); break;
        case 3: _t->on_returnBtn_clicked(); break;
        case 4: _t->on_calculateRatioButton_clicked(); break;
        case 5: _t->getResult((*reinterpret_cast< datatype(*)>(_a[1])),(*reinterpret_cast< datatype(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TestWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TestWindow::testButtonClicked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject TestWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TestWindow.data,
      qt_meta_data_TestWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *TestWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestWindow.stringdata))
        return static_cast<void*>(const_cast< TestWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int TestWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void TestWindow::testButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

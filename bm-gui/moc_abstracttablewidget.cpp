/****************************************************************************
** Meta object code from reading C++ file 'abstracttablewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "components/abstracttablewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'abstracttablewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AbstractTableWidget_t {
    QByteArrayData data[7];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AbstractTableWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AbstractTableWidget_t qt_meta_stringdata_AbstractTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "AbstractTableWidget"
QT_MOC_LITERAL(1, 20, 9), // "rowUpdate"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 3), // "row"
QT_MOC_LITERAL(4, 35, 10), // "dataChange"
QT_MOC_LITERAL(5, 46, 10), // "updateLine"
QT_MOC_LITERAL(6, 57, 9) // "on_remove"

    },
    "AbstractTableWidget\0rowUpdate\0\0row\0"
    "dataChange\0updateLine\0on_remove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AbstractTableWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    0,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   38,    2, 0x0a /* Public */,
       6,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void AbstractTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AbstractTableWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rowUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->dataChange(); break;
        case 2: _t->updateLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_remove((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AbstractTableWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractTableWidget::rowUpdate)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AbstractTableWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractTableWidget::dataChange)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AbstractTableWidget::staticMetaObject = { {
    &QTableWidget::staticMetaObject,
    qt_meta_stringdata_AbstractTableWidget.data,
    qt_meta_data_AbstractTableWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AbstractTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AbstractTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AbstractTableWidget.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int AbstractTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AbstractTableWidget::rowUpdate(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AbstractTableWidget::dataChange()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

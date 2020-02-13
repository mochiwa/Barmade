/****************************************************************************
** Meta object code from reading C++ file 'invoicetable_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "panel/product_panel/invoicetable_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'invoicetable_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InvoiceTable_t {
    QByteArrayData data[5];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InvoiceTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InvoiceTable_t qt_meta_stringdata_InvoiceTable = {
    {
QT_MOC_LITERAL(0, 0, 12), // "InvoiceTable"
QT_MOC_LITERAL(1, 13, 10), // "updateLine"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 3), // "row"
QT_MOC_LITERAL(4, 29, 13) // "on_updateData"

    },
    "InvoiceTable\0updateLine\0\0row\0on_updateData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InvoiceTable[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       4,    2,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

       0        // eod
};

void InvoiceTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InvoiceTable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_updateData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject InvoiceTable::staticMetaObject = { {
    &AbstractTableWidget::staticMetaObject,
    qt_meta_stringdata_InvoiceTable.data,
    qt_meta_data_InvoiceTable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *InvoiceTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InvoiceTable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InvoiceTable.stringdata0))
        return static_cast<void*>(this);
    return AbstractTableWidget::qt_metacast(_clname);
}

int InvoiceTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractTableWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

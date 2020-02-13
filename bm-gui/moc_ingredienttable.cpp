/****************************************************************************
** Meta object code from reading C++ file 'ingredienttable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "panel/ProductManagementPanel/ingredienttable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ingredienttable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IngredientTable_t {
    QByteArrayData data[5];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IngredientTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IngredientTable_t qt_meta_stringdata_IngredientTable = {
    {
QT_MOC_LITERAL(0, 0, 15), // "IngredientTable"
QT_MOC_LITERAL(1, 16, 10), // "updateLine"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "row"
QT_MOC_LITERAL(4, 32, 6) // "remove"

    },
    "IngredientTable\0updateLine\0\0row\0remove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IngredientTable[] = {

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
       4,    0,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void IngredientTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IngredientTable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->remove(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IngredientTable::staticMetaObject = { {
    &AbstractTableWidget::staticMetaObject,
    qt_meta_stringdata_IngredientTable.data,
    qt_meta_data_IngredientTable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IngredientTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IngredientTable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IngredientTable.stringdata0))
        return static_cast<void*>(this);
    return AbstractTableWidget::qt_metacast(_clname);
}

int IngredientTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

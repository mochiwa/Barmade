/****************************************************************************
** Meta object code from reading C++ file 'productform_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "panel/ProductManagementPanel/productform_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'productform_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProductFormWidget_t {
    QByteArrayData data[5];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProductFormWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProductFormWidget_t qt_meta_stringdata_ProductFormWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ProductFormWidget"
QT_MOC_LITERAL(1, 18, 20), // "on_createComposition"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 20), // "on_removeComposition"
QT_MOC_LITERAL(4, 61, 14) // "on_updateStock"

    },
    "ProductFormWidget\0on_createComposition\0"
    "\0on_removeComposition\0on_updateStock"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProductFormWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ProductFormWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProductFormWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_createComposition(); break;
        case 1: _t->on_removeComposition(); break;
        case 2: _t->on_updateStock(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ProductFormWidget::staticMetaObject = { {
    &EntityWidget::staticMetaObject,
    qt_meta_stringdata_ProductFormWidget.data,
    qt_meta_data_ProductFormWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProductFormWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProductFormWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProductFormWidget.stringdata0))
        return static_cast<void*>(this);
    return EntityWidget::qt_metacast(_clname);
}

int ProductFormWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = EntityWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

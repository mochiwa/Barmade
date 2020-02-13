/****************************************************************************
** Meta object code from reading C++ file 'planningviewcontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "panel/planning_panel/planningviewcontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'planningviewcontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlanningViewControl_t {
    QByteArrayData data[9];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlanningViewControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlanningViewControl_t qt_meta_stringdata_PlanningViewControl = {
    {
QT_MOC_LITERAL(0, 0, 19), // "PlanningViewControl"
QT_MOC_LITERAL(1, 20, 7), // "on_load"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 2), // "id"
QT_MOC_LITERAL(4, 32, 10), // "on_loadAll"
QT_MOC_LITERAL(5, 43, 9), // "on_create"
QT_MOC_LITERAL(6, 53, 16), // "on_calendarPopup"
QT_MOC_LITERAL(7, 70, 11), // "QModelIndex"
QT_MOC_LITERAL(8, 82, 5) // "index"

    },
    "PlanningViewControl\0on_load\0\0id\0"
    "on_loadAll\0on_create\0on_calendarPopup\0"
    "QModelIndex\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlanningViewControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    0,   37,    2, 0x0a /* Public */,
       5,    0,   38,    2, 0x0a /* Public */,
       6,    1,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void PlanningViewControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlanningViewControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_load((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_loadAll(); break;
        case 2: _t->on_create(); break;
        case 3: _t->on_calendarPopup((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlanningViewControl::staticMetaObject = { {
    &TableViewControl::staticMetaObject,
    qt_meta_stringdata_PlanningViewControl.data,
    qt_meta_data_PlanningViewControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PlanningViewControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlanningViewControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlanningViewControl.stringdata0))
        return static_cast<void*>(this);
    return TableViewControl::qt_metacast(_clname);
}

int PlanningViewControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TableViewControl::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'entitywidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "components/entitywidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'entitywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EntityWidget_t {
    QByteArrayData data[9];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EntityWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EntityWidget_t qt_meta_stringdata_EntityWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "EntityWidget"
QT_MOC_LITERAL(1, 13, 19), // "entity_presentation"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 20), // "entity_editingFinsih"
QT_MOC_LITERAL(4, 55, 7), // "on_load"
QT_MOC_LITERAL(5, 63, 7), // "on_save"
QT_MOC_LITERAL(6, 71, 7), // "on_edit"
QT_MOC_LITERAL(7, 79, 9), // "on_cancel"
QT_MOC_LITERAL(8, 89, 21) // "check_lineEdit_fields"

    },
    "EntityWidget\0entity_presentation\0\0"
    "entity_editingFinsih\0on_load\0on_save\0"
    "on_edit\0on_cancel\0check_lineEdit_fields"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EntityWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EntityWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EntityWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->entity_presentation(); break;
        case 1: _t->entity_editingFinsih(); break;
        case 2: _t->on_load(); break;
        case 3: _t->on_save(); break;
        case 4: _t->on_edit(); break;
        case 5: _t->on_cancel(); break;
        case 6: _t->check_lineEdit_fields(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EntityWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EntityWidget::entity_presentation)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EntityWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EntityWidget::entity_editingFinsih)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject EntityWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_EntityWidget.data,
    qt_meta_data_EntityWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EntityWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EntityWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EntityWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int EntityWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void EntityWidget::entity_presentation()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void EntityWidget::entity_editingFinsih()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

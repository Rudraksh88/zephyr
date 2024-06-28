/****************************************************************************
** Meta object code from reading C++ file 'breezeexceptionlistwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../config/breezeexceptionlistwidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'breezeexceptionlistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSBreezeSCOPEExceptionListWidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSBreezeSCOPEExceptionListWidgetENDCLASS = QtMocHelpers::stringData(
    "Breeze::ExceptionListWidget",
    "changed",
    "",
    "updateButtons",
    "add",
    "edit",
    "remove",
    "toggle",
    "QModelIndex",
    "up",
    "down"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBreezeSCOPEExceptionListWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   65,    2, 0x09,    3 /* Protected */,
       4,    0,   66,    2, 0x09,    4 /* Protected */,
       5,    0,   67,    2, 0x09,    5 /* Protected */,
       6,    0,   68,    2, 0x09,    6 /* Protected */,
       7,    1,   69,    2, 0x09,    7 /* Protected */,
       9,    0,   72,    2, 0x09,    9 /* Protected */,
      10,    0,   73,    2, 0x09,   10 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Breeze::ExceptionListWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSBreezeSCOPEExceptionListWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBreezeSCOPEExceptionListWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBreezeSCOPEExceptionListWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ExceptionListWidget, std::true_type>,
        // method 'changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'updateButtons'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'add'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'edit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'remove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'up'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'down'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Breeze::ExceptionListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExceptionListWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->changed((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->updateButtons(); break;
        case 2: _t->add(); break;
        case 3: _t->edit(); break;
        case 4: _t->remove(); break;
        case 5: _t->toggle((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 6: _t->up(); break;
        case 7: _t->down(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ExceptionListWidget::*)(bool );
            if (_t _q_method = &ExceptionListWidget::changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Breeze::ExceptionListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Breeze::ExceptionListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBreezeSCOPEExceptionListWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Breeze::ExceptionListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Breeze::ExceptionListWidget::changed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP

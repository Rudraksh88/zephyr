/****************************************************************************
** Meta object code from reading C++ file 'breezedecoration.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../breezedecoration.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'breezedecoration.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSBreezeSCOPEDecorationENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSBreezeSCOPEDecorationENDCLASS = QtMocHelpers::stringData(
    "Breeze::Decoration",
    "init",
    "",
    "reconfigure",
    "recalculateBorders",
    "resetBlurRegion",
    "updateButtonsGeometry",
    "updateButtonsGeometryDelayed",
    "updateTitleBar",
    "updateActiveState"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBreezeSCOPEDecorationENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x0a,    1 /* Public */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    0,   69,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Breeze::Decoration::staticMetaObject = { {
    QMetaObject::SuperData::link<KDecoration2::Decoration::staticMetaObject>(),
    qt_meta_stringdata_CLASSBreezeSCOPEDecorationENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBreezeSCOPEDecorationENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBreezeSCOPEDecorationENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Decoration, std::true_type>,
        // method 'init'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'reconfigure'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'recalculateBorders'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetBlurRegion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateButtonsGeometry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateButtonsGeometryDelayed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateTitleBar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateActiveState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Breeze::Decoration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Decoration *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->init();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->reconfigure(); break;
        case 2: _t->recalculateBorders(); break;
        case 3: _t->resetBlurRegion(); break;
        case 4: _t->updateButtonsGeometry(); break;
        case 5: _t->updateButtonsGeometryDelayed(); break;
        case 6: _t->updateTitleBar(); break;
        case 7: _t->updateActiveState(); break;
        default: ;
        }
    }
}

const QMetaObject *Breeze::Decoration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Breeze::Decoration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBreezeSCOPEDecorationENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return KDecoration2::Decoration::qt_metacast(_clname);
}

int Breeze::Decoration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KDecoration2::Decoration::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP

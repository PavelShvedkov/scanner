/****************************************************************************
** Meta object code from reading C++ file 'TunerBox.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../TunerBox.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TunerBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_TunerBox_t {
    uint offsetsAndSizes[14];
    char stringdata0[9];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[2];
    char stringdata4[8];
    char stringdata5[4];
    char stringdata6[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TunerBox_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_TunerBox_t qt_meta_stringdata_TunerBox = {
    {
        QT_MOC_LITERAL(0, 8),  // "TunerBox"
        QT_MOC_LITERAL(9, 12),  // "fieldChanged"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 1),  // "f"
        QT_MOC_LITERAL(25, 7),  // "setFreq"
        QT_MOC_LITERAL(33, 3),  // "frq"
        QT_MOC_LITERAL(37, 10)   // "adjustFreq"
    },
    "TunerBox",
    "fieldChanged",
    "",
    "f",
    "setFreq",
    "frq",
    "adjustFreq"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_TunerBox[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   35,    2, 0x0a,    3 /* Public */,
       6,    1,   38,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject TunerBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_TunerBox.offsetsAndSizes,
    qt_meta_data_TunerBox,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_TunerBox_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TunerBox, std::true_type>,
        // method 'fieldChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'setFreq'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'adjustFreq'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>
    >,
    nullptr
} };

void TunerBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TunerBox *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->fieldChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 1: _t->setFreq((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->adjustFreq((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TunerBox::*)(double );
            if (_t _q_method = &TunerBox::fieldChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *TunerBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TunerBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TunerBox.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int TunerBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void TunerBox::fieldChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

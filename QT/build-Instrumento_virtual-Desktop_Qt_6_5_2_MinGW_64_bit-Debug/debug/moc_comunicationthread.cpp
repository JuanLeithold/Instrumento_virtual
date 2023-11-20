/****************************************************************************
** Meta object code from reading C++ file 'comunicationthread.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QT/comunicationthread.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'comunicationthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
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
struct qt_meta_stringdata_CLASScomunicationThreadENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASScomunicationThreadENDCLASS = QtMocHelpers::stringData(
    "comunicationThread",
    "dataReceived",
    "",
    "unionRx_t",
    "data",
    "serialSend",
    "serialTx",
    "digitalOutputChange",
    "uint8_t",
    "dChange",
    "analogOutput1Change",
    "aChange",
    "analogOutput2Change"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASScomunicationThreadENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[19];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[5];
    char stringdata5[11];
    char stringdata6[9];
    char stringdata7[20];
    char stringdata8[8];
    char stringdata9[8];
    char stringdata10[20];
    char stringdata11[8];
    char stringdata12[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASScomunicationThreadENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASScomunicationThreadENDCLASS_t qt_meta_stringdata_CLASScomunicationThreadENDCLASS = {
    {
        QT_MOC_LITERAL(0, 18),  // "comunicationThread"
        QT_MOC_LITERAL(19, 12),  // "dataReceived"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 9),  // "unionRx_t"
        QT_MOC_LITERAL(43, 4),  // "data"
        QT_MOC_LITERAL(48, 10),  // "serialSend"
        QT_MOC_LITERAL(59, 8),  // "serialTx"
        QT_MOC_LITERAL(68, 19),  // "digitalOutputChange"
        QT_MOC_LITERAL(88, 7),  // "uint8_t"
        QT_MOC_LITERAL(96, 7),  // "dChange"
        QT_MOC_LITERAL(104, 19),  // "analogOutput1Change"
        QT_MOC_LITERAL(124, 7),  // "aChange"
        QT_MOC_LITERAL(132, 19)   // "analogOutput2Change"
    },
    "comunicationThread",
    "dataReceived",
    "",
    "unionRx_t",
    "data",
    "serialSend",
    "serialTx",
    "digitalOutputChange",
    "uint8_t",
    "dChange",
    "analogOutput1Change",
    "aChange",
    "analogOutput2Change"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASScomunicationThreadENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       5,    0,   53,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   54,    2, 0x0a,    4 /* Public */,
       7,    1,   55,    2, 0x0a,    5 /* Public */,
      10,    1,   58,    2, 0x0a,    7 /* Public */,
      12,    1,   61,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,   11,
    QMetaType::Void, 0x80000000 | 8,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject comunicationThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASScomunicationThreadENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASScomunicationThreadENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASScomunicationThreadENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<comunicationThread, std::true_type>,
        // method 'dataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const unionRx_t &, std::false_type>,
        // method 'serialSend'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'serialTx'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'digitalOutputChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>,
        // method 'analogOutput1Change'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>,
        // method 'analogOutput2Change'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>
    >,
    nullptr
} };

void comunicationThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<comunicationThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dataReceived((*reinterpret_cast< std::add_pointer_t<unionRx_t>>(_a[1]))); break;
        case 1: _t->serialSend(); break;
        case 2: { bool _r = _t->serialTx();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->digitalOutputChange((*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[1]))); break;
        case 4: _t->analogOutput1Change((*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[1]))); break;
        case 5: _t->analogOutput2Change((*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (comunicationThread::*)(const unionRx_t & );
            if (_t _q_method = &comunicationThread::dataReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (comunicationThread::*)();
            if (_t _q_method = &comunicationThread::serialSend; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *comunicationThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *comunicationThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASScomunicationThreadENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int comunicationThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void comunicationThread::dataReceived(const unionRx_t & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void comunicationThread::serialSend()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP

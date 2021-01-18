/****************************************************************************
** Meta object code from reading C++ file 'modbus.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../inc/modbus.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modbus.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Modbus_t {
    QByteArrayData data[13];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Modbus_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Modbus_t qt_meta_stringdata_Modbus = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Modbus"
QT_MOC_LITERAL(1, 7, 4), // "info"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 3), // "msg"
QT_MOC_LITERAL(4, 17, 4), // "warn"
QT_MOC_LITERAL(5, 22, 5), // "error"
QT_MOC_LITERAL(6, 28, 10), // "reportData"
QT_MOC_LITERAL(7, 39, 15), // "QVector<qint16>"
QT_MOC_LITERAL(8, 55, 7), // "rawData"
QT_MOC_LITERAL(9, 63, 9), // "slaveAddr"
QT_MOC_LITERAL(10, 73, 10), // "SensorType"
QT_MOC_LITERAL(11, 84, 6), // "sensor"
QT_MOC_LITERAL(12, 91, 9) // "readyRead"

    },
    "Modbus\0info\0\0msg\0warn\0error\0reportData\0"
    "QVector<qint16>\0rawData\0slaveAddr\0"
    "SensorType\0sensor\0readyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Modbus[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       5,    1,   45,    2, 0x06 /* Public */,
       6,    3,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int, 0x80000000 | 10,    8,    9,   11,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Modbus::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Modbus *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->info((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->warn((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->reportData((*reinterpret_cast< const QVector<qint16>(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const SensorType(*)>(_a[3]))); break;
        case 4: _t->readyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<qint16> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Modbus::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modbus::info)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Modbus::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modbus::warn)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Modbus::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modbus::error)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Modbus::*)(const QVector<qint16> & , const int , const SensorType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modbus::reportData)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Modbus::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Modbus.data,
    qt_meta_data_Modbus,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Modbus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Modbus::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Modbus.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Modbus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Modbus::info(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Modbus::warn(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Modbus::error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Modbus::reportData(const QVector<qint16> & _t1, const int _t2, const SensorType _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

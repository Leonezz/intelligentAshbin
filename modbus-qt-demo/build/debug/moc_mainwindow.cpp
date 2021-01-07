/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../inc/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[267];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 22), // "sendSensorDataToDevice"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 2), // "id"
QT_MOC_LITERAL(4, 38, 10), // "SensorType"
QT_MOC_LITERAL(5, 49, 6), // "sensor"
QT_MOC_LITERAL(6, 56, 4), // "data"
QT_MOC_LITERAL(7, 61, 9), // "addDevice"
QT_MOC_LITERAL(8, 71, 23), // "serialSettingDialogExec"
QT_MOC_LITERAL(9, 95, 28), // "actionConnectSerialTriggered"
QT_MOC_LITERAL(10, 124, 17), // "getSerialSettings"
QT_MOC_LITERAL(11, 142, 10), // "SerialInfo"
QT_MOC_LITERAL(12, 153, 4), // "info"
QT_MOC_LITERAL(13, 158, 10), // "statusInfo"
QT_MOC_LITERAL(14, 169, 3), // "msg"
QT_MOC_LITERAL(15, 173, 10), // "statusWarn"
QT_MOC_LITERAL(16, 184, 11), // "statusError"
QT_MOC_LITERAL(17, 196, 12), // "removeDevice"
QT_MOC_LITERAL(18, 209, 17), // "addRequestToQueue"
QT_MOC_LITERAL(19, 227, 7), // "slaveID"
QT_MOC_LITERAL(20, 235, 2), // "op"
QT_MOC_LITERAL(21, 238, 13), // "requestModbus"
QT_MOC_LITERAL(22, 252, 14) // "getModbusReply"

    },
    "MainWindow\0sendSensorDataToDevice\0\0"
    "id\0SensorType\0sensor\0data\0addDevice\0"
    "serialSettingDialogExec\0"
    "actionConnectSerialTriggered\0"
    "getSerialSettings\0SerialInfo\0info\0"
    "statusInfo\0msg\0statusWarn\0statusError\0"
    "removeDevice\0addRequestToQueue\0slaveID\0"
    "op\0requestModbus\0getModbusReply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   81,    2, 0x08 /* Private */,
       8,    0,   82,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    1,   84,    2, 0x08 /* Private */,
      13,    1,   87,    2, 0x08 /* Private */,
      15,    1,   90,    2, 0x08 /* Private */,
      16,    1,   93,    2, 0x08 /* Private */,
      17,    0,   96,    2, 0x08 /* Private */,
      18,    4,   97,    2, 0x08 /* Private */,
      21,    0,  106,    2, 0x08 /* Private */,
      22,    3,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, QMetaType::Int, QMetaType::Int,   19,    5,    6,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 4,    6,   19,    5,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendSensorDataToDevice((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const SensorType(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 1: _t->addDevice(); break;
        case 2: _t->serialSettingDialogExec(); break;
        case 3: _t->actionConnectSerialTriggered(); break;
        case 4: _t->getSerialSettings((*reinterpret_cast< const SerialInfo(*)>(_a[1]))); break;
        case 5: _t->statusInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->statusWarn((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->statusError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->removeDevice(); break;
        case 9: _t->addRequestToQueue((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const SensorType(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4]))); break;
        case 10: _t->requestModbus(); break;
        case 11: _t->getModbusReply((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< SensorType(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int , const SensorType , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendSensorDataToDevice)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sendSensorDataToDevice(int _t1, const SensorType _t2, const int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'main-window.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../corfu/dev-host/ground-tools/ground/src/main-window.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main-window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[36];
    char stringdata0[809];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "logReceived"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "Log&"
QT_MOC_LITERAL(4, 29, 1), // "l"
QT_MOC_LITERAL(5, 31, 11), // "hwidChanged"
QT_MOC_LITERAL(6, 43, 7), // "uint8_t"
QT_MOC_LITERAL(7, 51, 4), // "hwid"
QT_MOC_LITERAL(8, 56, 11), // "nodeChanged"
QT_MOC_LITERAL(9, 68, 11), // "focusOthers"
QT_MOC_LITERAL(10, 80, 19), // "localUTCtimerUpdate"
QT_MOC_LITERAL(11, 100, 35), // "on_nodeComboBox_currentIndexC..."
QT_MOC_LITERAL(12, 136, 4), // "name"
QT_MOC_LITERAL(13, 141, 41), // "on_hardwareIdComboBox_current..."
QT_MOC_LITERAL(14, 183, 23), // "on_loadAction_triggered"
QT_MOC_LITERAL(15, 207, 28), // "on_actionOpen_Wiki_triggered"
QT_MOC_LITERAL(16, 236, 30), // "on_actionsave_layout_triggered"
QT_MOC_LITERAL(17, 267, 30), // "on_actionload_layout_triggered"
QT_MOC_LITERAL(18, 298, 28), // "on_actionclose_all_triggered"
QT_MOC_LITERAL(19, 327, 32), // "on_actionOnly_Critical_triggered"
QT_MOC_LITERAL(20, 360, 36), // "on_actionWarnings_Critical_tr..."
QT_MOC_LITERAL(21, 397, 29), // "on_actionEverything_triggered"
QT_MOC_LITERAL(22, 427, 27), // "on_actionSee_Logs_triggered"
QT_MOC_LITERAL(23, 455, 43), // "on_actionAuto_Swap_on_Node_ch..."
QT_MOC_LITERAL(24, 499, 43), // "on_actionAuto_Swap_on_HwID_ch..."
QT_MOC_LITERAL(25, 543, 48), // "on_actionDefault_Preserve_Win..."
QT_MOC_LITERAL(26, 592, 40), // "on_actionWindows_to_backgroun..."
QT_MOC_LITERAL(27, 633, 31), // "on_actionLoad_TM_File_triggered"
QT_MOC_LITERAL(28, 665, 13), // "eventReceived"
QT_MOC_LITERAL(29, 679, 20), // "corfu::ground::Event"
QT_MOC_LITERAL(30, 700, 5), // "event"
QT_MOC_LITERAL(31, 706, 17), // "telemetryReceived"
QT_MOC_LITERAL(32, 724, 24), // "corfu::ground::Telemetry"
QT_MOC_LITERAL(33, 749, 17), // "receivedTelemetry"
QT_MOC_LITERAL(34, 767, 24), // "updateHardwareIdCombobox"
QT_MOC_LITERAL(35, 792, 16) // "updateAppWidgets"

    },
    "MainWindow\0logReceived\0\0Log&\0l\0"
    "hwidChanged\0uint8_t\0hwid\0nodeChanged\0"
    "focusOthers\0localUTCtimerUpdate\0"
    "on_nodeComboBox_currentIndexChanged\0"
    "name\0on_hardwareIdComboBox_currentIndexChanged\0"
    "on_loadAction_triggered\0"
    "on_actionOpen_Wiki_triggered\0"
    "on_actionsave_layout_triggered\0"
    "on_actionload_layout_triggered\0"
    "on_actionclose_all_triggered\0"
    "on_actionOnly_Critical_triggered\0"
    "on_actionWarnings_Critical_triggered\0"
    "on_actionEverything_triggered\0"
    "on_actionSee_Logs_triggered\0"
    "on_actionAuto_Swap_on_Node_change_triggered\0"
    "on_actionAuto_Swap_on_HwID_change_triggered\0"
    "on_actionDefault_Preserve_Window_Value_triggered\0"
    "on_actionWindows_to_background_triggered\0"
    "on_actionLoad_TM_File_triggered\0"
    "eventReceived\0corfu::ground::Event\0"
    "event\0telemetryReceived\0"
    "corfu::ground::Telemetry\0receivedTelemetry\0"
    "updateHardwareIdCombobox\0updateAppWidgets"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  139,    2, 0x06 /* Public */,
       5,    1,  142,    2, 0x06 /* Public */,
       8,    0,  145,    2, 0x06 /* Public */,
       9,    0,  146,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  147,    2, 0x08 /* Private */,
      11,    1,  148,    2, 0x08 /* Private */,
      13,    1,  151,    2, 0x08 /* Private */,
      14,    1,  154,    2, 0x08 /* Private */,
      15,    1,  157,    2, 0x08 /* Private */,
      16,    1,  160,    2, 0x08 /* Private */,
      17,    1,  163,    2, 0x08 /* Private */,
      18,    1,  166,    2, 0x08 /* Private */,
      19,    1,  169,    2, 0x08 /* Private */,
      20,    1,  172,    2, 0x08 /* Private */,
      21,    1,  175,    2, 0x08 /* Private */,
      22,    1,  178,    2, 0x08 /* Private */,
      23,    1,  181,    2, 0x08 /* Private */,
      24,    1,  184,    2, 0x08 /* Private */,
      25,    1,  187,    2, 0x08 /* Private */,
      26,    1,  190,    2, 0x08 /* Private */,
      27,    1,  193,    2, 0x08 /* Private */,
      28,    1,  196,    2, 0x08 /* Private */,
      31,    1,  199,    2, 0x08 /* Private */,
      34,    0,  202,    2, 0x08 /* Private */,
      35,    0,  203,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->logReceived((*reinterpret_cast< Log(*)>(_a[1]))); break;
        case 1: _t->hwidChanged((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 2: _t->nodeChanged(); break;
        case 3: _t->focusOthers(); break;
        case 4: _t->localUTCtimerUpdate(); break;
        case 5: _t->on_nodeComboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_hardwareIdComboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_loadAction_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_actionOpen_Wiki_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_actionsave_layout_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_actionload_layout_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_actionclose_all_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_actionOnly_Critical_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_actionWarnings_Critical_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_actionEverything_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_actionSee_Logs_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->on_actionAuto_Swap_on_Node_change_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->on_actionAuto_Swap_on_HwID_change_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_actionDefault_Preserve_Window_Value_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->on_actionWindows_to_background_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->on_actionLoad_TM_File_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->eventReceived((*reinterpret_cast< const corfu::ground::Event(*)>(_a[1]))); break;
        case 22: _t->telemetryReceived((*reinterpret_cast< const corfu::ground::Telemetry(*)>(_a[1]))); break;
        case 23: _t->updateHardwareIdCombobox(); break;
        case 24: _t->updateAppWidgets(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(Log & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::logReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(uint8_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::hwidChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::nodeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::focusOthers)) {
                *result = 3;
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
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::logReceived(Log & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::hwidChanged(uint8_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::nodeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::focusOthers()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

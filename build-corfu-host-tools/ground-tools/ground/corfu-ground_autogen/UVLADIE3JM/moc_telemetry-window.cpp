/****************************************************************************
** Meta object code from reading C++ file 'telemetry-window.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../corfu/dev-host/ground-tools/ground/src/telemetry-window.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'telemetry-window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TelemetryWindow_t {
    QByteArrayData data[19];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TelemetryWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TelemetryWindow_t qt_meta_stringdata_TelemetryWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TelemetryWindow"
QT_MOC_LITERAL(1, 16, 15), // "telemetryUpdate"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 12), // "RegisteredTM"
QT_MOC_LITERAL(4, 46, 17), // "receivedTelemetry"
QT_MOC_LITERAL(5, 64, 19), // "localUTCtimerUpdate"
QT_MOC_LITERAL(6, 84, 7), // "nextBtn"
QT_MOC_LITERAL(7, 92, 7), // "prevBtn"
QT_MOC_LITERAL(8, 100, 7), // "liveBtn"
QT_MOC_LITERAL(9, 108, 8), // "pauseBtn"
QT_MOC_LITERAL(10, 117, 19), // "hwidSelectorChanged"
QT_MOC_LITERAL(11, 137, 4), // "name"
QT_MOC_LITERAL(12, 142, 7), // "saveCSV"
QT_MOC_LITERAL(13, 150, 5), // "clear"
QT_MOC_LITERAL(14, 156, 14), // "historyChanged"
QT_MOC_LITERAL(15, 171, 17), // "hwidChangedFromMW"
QT_MOC_LITERAL(16, 189, 7), // "uint8_t"
QT_MOC_LITERAL(17, 197, 7), // "newhwid"
QT_MOC_LITERAL(18, 205, 5) // "focus"

    },
    "TelemetryWindow\0telemetryUpdate\0\0"
    "RegisteredTM\0receivedTelemetry\0"
    "localUTCtimerUpdate\0nextBtn\0prevBtn\0"
    "liveBtn\0pauseBtn\0hwidSelectorChanged\0"
    "name\0saveCSV\0clear\0historyChanged\0"
    "hwidChangedFromMW\0uint8_t\0newhwid\0"
    "focus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TelemetryWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    1,   82,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x0a /* Public */,
      14,    0,   87,    2, 0x0a /* Public */,
      15,    1,   88,    2, 0x0a /* Public */,
      18,    0,   91,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,

       0        // eod
};

void TelemetryWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TelemetryWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->telemetryUpdate((*reinterpret_cast< const RegisteredTM(*)>(_a[1]))); break;
        case 1: _t->localUTCtimerUpdate(); break;
        case 2: _t->nextBtn(); break;
        case 3: { bool _r = _t->prevBtn();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->liveBtn(); break;
        case 5: _t->pauseBtn(); break;
        case 6: _t->hwidSelectorChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->saveCSV(); break;
        case 8: _t->clear(); break;
        case 9: _t->historyChanged(); break;
        case 10: _t->hwidChangedFromMW((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 11: _t->focus(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TelemetryWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_TelemetryWindow.data,
    qt_meta_data_TelemetryWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TelemetryWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TelemetryWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TelemetryWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TelemetryWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

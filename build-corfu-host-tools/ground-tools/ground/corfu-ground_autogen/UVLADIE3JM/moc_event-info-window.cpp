/****************************************************************************
** Meta object code from reading C++ file 'event-info-window.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../corfu/dev-host/ground-tools/ground/src/event-info-window.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'event-info-window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EventInfoWindow_t {
    QByteArrayData data[11];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EventInfoWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EventInfoWindow_t qt_meta_stringdata_EventInfoWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "EventInfoWindow"
QT_MOC_LITERAL(1, 16, 21), // "updateHwIDAppSelector"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 1), // "i"
QT_MOC_LITERAL(4, 41, 17), // "updateAppSelector"
QT_MOC_LITERAL(5, 59, 6), // "newLog"
QT_MOC_LITERAL(6, 66, 5), // "Event"
QT_MOC_LITERAL(7, 72, 1), // "l"
QT_MOC_LITERAL(8, 74, 13), // "eventReceived"
QT_MOC_LITERAL(9, 88, 5), // "event"
QT_MOC_LITERAL(10, 94, 7) // "refresh"

    },
    "EventInfoWindow\0updateHwIDAppSelector\0"
    "\0i\0updateAppSelector\0newLog\0Event\0l\0"
    "eventReceived\0event\0refresh"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EventInfoWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       5,    1,   45,    2, 0x0a /* Public */,
       8,    1,   48,    2, 0x0a /* Public */,
      10,    0,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    9,
    QMetaType::Void,

       0        // eod
};

void EventInfoWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EventInfoWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateHwIDAppSelector((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateAppSelector((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->newLog((*reinterpret_cast< const Event(*)>(_a[1]))); break;
        case 3: _t->eventReceived((*reinterpret_cast< const Event(*)>(_a[1]))); break;
        case 4: _t->refresh(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EventInfoWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_EventInfoWindow.data,
    qt_meta_data_EventInfoWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EventInfoWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventInfoWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EventInfoWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int EventInfoWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'telecommand-window.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../corfu/dev-host/ground-tools/ground/src/telecommand-window.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'telecommand-window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TelecommandWindow_t {
    QByteArrayData data[25];
    char stringdata0[442];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TelecommandWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TelecommandWindow_t qt_meta_stringdata_TelecommandWindow = {
    {
QT_MOC_LITERAL(0, 0, 17), // "TelecommandWindow"
QT_MOC_LITERAL(1, 18, 12), // "tcReadyToAdd"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 44), // "std::shared_ptr<corfu::ground..."
QT_MOC_LITERAL(4, 77, 15), // "telecommandData"
QT_MOC_LITERAL(5, 93, 57), // "std::shared_ptr<const corfu::..."
QT_MOC_LITERAL(6, 151, 16), // "telecommandModel"
QT_MOC_LITERAL(7, 168, 8), // "position"
QT_MOC_LITERAL(8, 177, 13), // "tcDataChanged"
QT_MOC_LITERAL(9, 191, 43), // "std::shared_ptr<corfu::ground..."
QT_MOC_LITERAL(10, 235, 11), // "tabSelected"
QT_MOC_LITERAL(11, 247, 19), // "selectedDateChanged"
QT_MOC_LITERAL(12, 267, 19), // "relativeTimeChanged"
QT_MOC_LITERAL(13, 287, 15), // "manualTimeInput"
QT_MOC_LITERAL(14, 303, 21), // "on_sendButton_clicked"
QT_MOC_LITERAL(15, 325, 17), // "updateAppSelector"
QT_MOC_LITERAL(16, 343, 1), // "i"
QT_MOC_LITERAL(17, 345, 16), // "updateTMSelector"
QT_MOC_LITERAL(18, 362, 13), // "appIsSelected"
QT_MOC_LITERAL(19, 376, 19), // "updateFieldSelector"
QT_MOC_LITERAL(20, 396, 5), // "clear"
QT_MOC_LITERAL(21, 402, 17), // "hwidChangedFromMW"
QT_MOC_LITERAL(22, 420, 7), // "uint8_t"
QT_MOC_LITERAL(23, 428, 7), // "newhwid"
QT_MOC_LITERAL(24, 436, 5) // "focus"

    },
    "TelecommandWindow\0tcReadyToAdd\0\0"
    "std::shared_ptr<corfu::ground::Telecommand>&\0"
    "telecommandData\0"
    "std::shared_ptr<const corfu::config_parser::model::Tele>&\0"
    "telecommandModel\0position\0tcDataChanged\0"
    "std::shared_ptr<corfu::ground::Telecommand>\0"
    "tabSelected\0selectedDateChanged\0"
    "relativeTimeChanged\0manualTimeInput\0"
    "on_sendButton_clicked\0updateAppSelector\0"
    "i\0updateTMSelector\0appIsSelected\0"
    "updateFieldSelector\0clear\0hwidChangedFromMW\0"
    "uint8_t\0newhwid\0focus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TelecommandWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   89,    2, 0x06 /* Public */,
       1,    2,   96,    2, 0x26 /* Public | MethodCloned */,
       8,    1,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  104,    2, 0x08 /* Private */,
      11,    0,  105,    2, 0x08 /* Private */,
      12,    0,  106,    2, 0x08 /* Private */,
      13,    0,  107,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    1,  109,    2, 0x0a /* Public */,
      17,    2,  112,    2, 0x0a /* Public */,
      17,    1,  117,    2, 0x2a /* Public | MethodCloned */,
      19,    0,  120,    2, 0x0a /* Public */,
      20,    0,  121,    2, 0x0a /* Public */,
      21,    1,  122,    2, 0x0a /* Public */,
      24,    0,  125,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::Int,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 9,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   16,   18,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void,

       0        // eod
};

void TelecommandWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TelecommandWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->tcReadyToAdd((*reinterpret_cast< std::shared_ptr<corfu::ground::Telecommand>(*)>(_a[1])),(*reinterpret_cast< std::shared_ptr<const corfu::config_parser::model::Tele>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->tcReadyToAdd((*reinterpret_cast< std::shared_ptr<corfu::ground::Telecommand>(*)>(_a[1])),(*reinterpret_cast< std::shared_ptr<const corfu::config_parser::model::Tele>(*)>(_a[2]))); break;
        case 2: _t->tcDataChanged((*reinterpret_cast< std::shared_ptr<corfu::ground::Telecommand>(*)>(_a[1]))); break;
        case 3: _t->tabSelected(); break;
        case 4: _t->selectedDateChanged(); break;
        case 5: _t->relativeTimeChanged(); break;
        case 6: _t->manualTimeInput(); break;
        case 7: { bool _r = _t->on_sendButton_clicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->updateAppSelector((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->updateTMSelector((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->updateTMSelector((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->updateFieldSelector(); break;
        case 12: _t->clear(); break;
        case 13: _t->hwidChangedFromMW((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 14: _t->focus(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TelecommandWindow::*)(std::shared_ptr<corfu::ground::Telecommand> & , std::shared_ptr<const corfu::config_parser::model::Tele> & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TelecommandWindow::tcReadyToAdd)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TelecommandWindow::*)(std::shared_ptr<corfu::ground::Telecommand> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TelecommandWindow::tcDataChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TelecommandWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_TelecommandWindow.data,
    qt_meta_data_TelecommandWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TelecommandWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TelecommandWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TelecommandWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TelecommandWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void TelecommandWindow::tcReadyToAdd(std::shared_ptr<corfu::ground::Telecommand> & _t1, std::shared_ptr<const corfu::config_parser::model::Tele> & _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void TelecommandWindow::tcDataChanged(std::shared_ptr<corfu::ground::Telecommand> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

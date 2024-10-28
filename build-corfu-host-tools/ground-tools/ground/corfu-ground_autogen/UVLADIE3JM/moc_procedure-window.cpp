/****************************************************************************
** Meta object code from reading C++ file 'procedure-window.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../corfu/dev-host/ground-tools/ground/src/procedure-window.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'procedure-window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProcedureWindow_t {
    QByteArrayData data[23];
    char stringdata0[381];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProcedureWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProcedureWindow_t qt_meta_stringdata_ProcedureWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ProcedureWindow"
QT_MOC_LITERAL(1, 16, 10), // "removeItem"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 2), // "id"
QT_MOC_LITERAL(4, 31, 17), // "updateAppSelector"
QT_MOC_LITERAL(5, 49, 1), // "i"
QT_MOC_LITERAL(6, 51, 16), // "updateTCSelector"
QT_MOC_LITERAL(7, 68, 13), // "appIsSelected"
QT_MOC_LITERAL(8, 82, 18), // "tcAddButtonPressed"
QT_MOC_LITERAL(9, 101, 11), // "addTCtoList"
QT_MOC_LITERAL(10, 113, 26), // "TelecommandListItemWidget*"
QT_MOC_LITERAL(11, 140, 43), // "std::shared_ptr<corfu::ground..."
QT_MOC_LITERAL(12, 184, 15), // "telecommandData"
QT_MOC_LITERAL(13, 200, 56), // "std::shared_ptr<const corfu::..."
QT_MOC_LITERAL(14, 257, 16), // "telecommandModel"
QT_MOC_LITERAL(15, 274, 8), // "position"
QT_MOC_LITERAL(16, 283, 10), // "saveToFile"
QT_MOC_LITERAL(17, 294, 12), // "loadFromFile"
QT_MOC_LITERAL(18, 307, 16), // "bakeTCTimestamps"
QT_MOC_LITERAL(19, 324, 19), // "unbakeTCTimestampes"
QT_MOC_LITERAL(20, 344, 10), // "sendAllTCs"
QT_MOC_LITERAL(21, 355, 15), // "sendSelectedTCs"
QT_MOC_LITERAL(22, 371, 9) // "itemMoved"

    },
    "ProcedureWindow\0removeItem\0\0id\0"
    "updateAppSelector\0i\0updateTCSelector\0"
    "appIsSelected\0tcAddButtonPressed\0"
    "addTCtoList\0TelecommandListItemWidget*\0"
    "std::shared_ptr<corfu::ground::Telecommand>\0"
    "telecommandData\0"
    "std::shared_ptr<const corfu::config_parser::model::Tele>\0"
    "telecommandModel\0position\0saveToFile\0"
    "loadFromFile\0bakeTCTimestamps\0"
    "unbakeTCTimestampes\0sendAllTCs\0"
    "sendSelectedTCs\0itemMoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProcedureWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x0a /* Public */,
       4,    1,   87,    2, 0x0a /* Public */,
       6,    2,   90,    2, 0x0a /* Public */,
       6,    1,   95,    2, 0x2a /* Public | MethodCloned */,
       8,    0,   98,    2, 0x0a /* Public */,
       9,    3,   99,    2, 0x0a /* Public */,
       9,    2,  106,    2, 0x2a /* Public | MethodCloned */,
      16,    0,  111,    2, 0x0a /* Public */,
      17,    0,  112,    2, 0x0a /* Public */,
      18,    0,  113,    2, 0x0a /* Public */,
      19,    0,  114,    2, 0x0a /* Public */,
      20,    0,  115,    2, 0x0a /* Public */,
      21,    0,  116,    2, 0x0a /* Public */,
      22,    0,  117,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    5,    7,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    0x80000000 | 10, 0x80000000 | 11, 0x80000000 | 13, QMetaType::Int,   12,   14,   15,
    0x80000000 | 10, 0x80000000 | 11, 0x80000000 | 13,   12,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ProcedureWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProcedureWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->removeItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateAppSelector((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updateTCSelector((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->updateTCSelector((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->tcAddButtonPressed(); break;
        case 5: { TelecommandListItemWidget* _r = _t->addTCtoList((*reinterpret_cast< std::shared_ptr<corfu::ground::Telecommand>(*)>(_a[1])),(*reinterpret_cast< std::shared_ptr<const corfu::config_parser::model::Tele>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< TelecommandListItemWidget**>(_a[0]) = std::move(_r); }  break;
        case 6: { TelecommandListItemWidget* _r = _t->addTCtoList((*reinterpret_cast< std::shared_ptr<corfu::ground::Telecommand>(*)>(_a[1])),(*reinterpret_cast< std::shared_ptr<const corfu::config_parser::model::Tele>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< TelecommandListItemWidget**>(_a[0]) = std::move(_r); }  break;
        case 7: _t->saveToFile(); break;
        case 8: _t->loadFromFile(); break;
        case 9: _t->bakeTCTimestamps(); break;
        case 10: _t->unbakeTCTimestampes(); break;
        case 11: _t->sendAllTCs(); break;
        case 12: _t->sendSelectedTCs(); break;
        case 13: _t->itemMoved(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ProcedureWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ProcedureWindow.data,
    qt_meta_data_ProcedureWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProcedureWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProcedureWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProcedureWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ProcedureWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

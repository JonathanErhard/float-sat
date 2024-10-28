/****************************************************************************
** Meta object code from reading C++ file 'telecommand-list-item-widget.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../corfu/dev-host/ground-tools/ground/src/telecommand-list-item-widget.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'telecommand-list-item-widget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TelecommandListItemWidget_t {
    QByteArrayData data[15];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TelecommandListItemWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TelecommandListItemWidget_t qt_meta_stringdata_TelecommandListItemWidget = {
    {
QT_MOC_LITERAL(0, 0, 25), // "TelecommandListItemWidget"
QT_MOC_LITERAL(1, 26, 14), // "sendRemoveItem"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 2), // "id"
QT_MOC_LITERAL(4, 45, 18), // "closeButtonClicked"
QT_MOC_LITERAL(5, 64, 13), // "editTcClicked"
QT_MOC_LITERAL(6, 78, 10), // "tcEditDone"
QT_MOC_LITERAL(7, 89, 43), // "std::shared_ptr<corfu::ground..."
QT_MOC_LITERAL(8, 133, 15), // "telecommandData"
QT_MOC_LITERAL(9, 149, 21), // "mouseDoubleClickEvent"
QT_MOC_LITERAL(10, 171, 12), // "QMouseEvent*"
QT_MOC_LITERAL(11, 184, 5), // "event"
QT_MOC_LITERAL(12, 190, 11), // "hwIdChanged"
QT_MOC_LITERAL(13, 202, 3), // "txt"
QT_MOC_LITERAL(14, 206, 14) // "sendIndividual"

    },
    "TelecommandListItemWidget\0sendRemoveItem\0"
    "\0id\0closeButtonClicked\0editTcClicked\0"
    "tcEditDone\0std::shared_ptr<corfu::ground::Telecommand>\0"
    "telecommandData\0mouseDoubleClickEvent\0"
    "QMouseEvent*\0event\0hwIdChanged\0txt\0"
    "sendIndividual"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TelecommandListItemWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   52,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x0a /* Public */,
       6,    1,   54,    2, 0x0a /* Public */,
       9,    1,   57,    2, 0x0a /* Public */,
      12,    1,   60,    2, 0x0a /* Public */,
      14,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,

       0        // eod
};

void TelecommandListItemWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TelecommandListItemWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendRemoveItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->closeButtonClicked(); break;
        case 2: _t->editTcClicked(); break;
        case 3: _t->tcEditDone((*reinterpret_cast< std::shared_ptr<corfu::ground::Telecommand>(*)>(_a[1]))); break;
        case 4: _t->mouseDoubleClickEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->hwIdChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->sendIndividual(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TelecommandListItemWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TelecommandListItemWidget::sendRemoveItem)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TelecommandListItemWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidgetListItem::staticMetaObject>(),
    qt_meta_stringdata_TelecommandListItemWidget.data,
    qt_meta_data_TelecommandListItemWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TelecommandListItemWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TelecommandListItemWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TelecommandListItemWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidgetListItem::qt_metacast(_clname);
}

int TelecommandListItemWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidgetListItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TelecommandListItemWidget::sendRemoveItem(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

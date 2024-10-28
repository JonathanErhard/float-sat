/****************************************************************************
** Meta object code from reading C++ file 'QWidgetListWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../corfu/dev-host/ground-tools/ground/QtAdditions/include/dak/QtAdditions/QWidgetListWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QWidgetListWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dak__QtAdditions__QWidgetListWidget_t {
    QByteArrayData data[3];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dak__QtAdditions__QWidgetListWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dak__QtAdditions__QWidgetListWidget_t qt_meta_stringdata_dak__QtAdditions__QWidgetListWidget = {
    {
QT_MOC_LITERAL(0, 0, 35), // "dak::QtAdditions::QWidgetList..."
QT_MOC_LITERAL(1, 36, 12), // "itemsChanged"
QT_MOC_LITERAL(2, 49, 0) // ""

    },
    "dak::QtAdditions::QWidgetListWidget\0"
    "itemsChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dak__QtAdditions__QWidgetListWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void dak::QtAdditions::QWidgetListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QWidgetListWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->itemsChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QWidgetListWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QWidgetListWidget::itemsChanged)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject dak::QtAdditions::QWidgetListWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_dak__QtAdditions__QWidgetListWidget.data,
    qt_meta_data_dak__QtAdditions__QWidgetListWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dak::QtAdditions::QWidgetListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dak::QtAdditions::QWidgetListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dak__QtAdditions__QWidgetListWidget.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int dak::QtAdditions::QWidgetListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void dak::QtAdditions::QWidgetListWidget::itemsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

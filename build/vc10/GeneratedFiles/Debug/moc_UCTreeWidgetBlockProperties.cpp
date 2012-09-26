/****************************************************************************
** Meta object code from reading C++ file 'UCTreeWidgetBlockProperties.h'
**
** Created: Wed 26. Sep 14:41:16 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/UCTreeWidgetBlockProperties.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UCTreeWidgetBlockProperties.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Uber__UCTreeWidgetBlockProperties[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      41,   35,   34,   34, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Uber__UCTreeWidgetBlockProperties[] = {
    "Uber::UCTreeWidgetBlockProperties\0\0"
    "model\0OnBlockSelected(UCBlockModel*)\0"
};

void Uber::UCTreeWidgetBlockProperties::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UCTreeWidgetBlockProperties *_t = static_cast<UCTreeWidgetBlockProperties *>(_o);
        switch (_id) {
        case 0: _t->OnBlockSelected((*reinterpret_cast< UCBlockModel*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Uber::UCTreeWidgetBlockProperties::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Uber::UCTreeWidgetBlockProperties::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_Uber__UCTreeWidgetBlockProperties,
      qt_meta_data_Uber__UCTreeWidgetBlockProperties, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Uber::UCTreeWidgetBlockProperties::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Uber::UCTreeWidgetBlockProperties::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Uber::UCTreeWidgetBlockProperties::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Uber__UCTreeWidgetBlockProperties))
        return static_cast<void*>(const_cast< UCTreeWidgetBlockProperties*>(this));
    if (!strcmp(_clname, "UCSingleton<UCTreeWidgetBlockProperties>"))
        return static_cast< UCSingleton<UCTreeWidgetBlockProperties>*>(const_cast< UCTreeWidgetBlockProperties*>(this));
    return QTreeView::qt_metacast(_clname);
}

int Uber::UCTreeWidgetBlockProperties::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

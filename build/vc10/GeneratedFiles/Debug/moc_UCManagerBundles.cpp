/****************************************************************************
** Meta object code from reading C++ file 'UCManagerBundles.h'
**
** Created: Wed 26. Sep 14:39:09 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/UCManagerBundles.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UCManagerBundles.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Uber__UCManagerBundles[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      42,   24,   23,   23, 0x05,
      86,   24,   23,   23, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Uber__UCManagerBundles[] = {
    "Uber::UCManagerBundles\0\0bundleName,blocks\0"
    "NotifyBundleDetected(QString,BlockInfoList)\0"
    "NotifyBundleUnloaded(QString,BlockInfoList)\0"
};

void Uber::UCManagerBundles::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UCManagerBundles *_t = static_cast<UCManagerBundles *>(_o);
        switch (_id) {
        case 0: _t->NotifyBundleDetected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const BlockInfoList(*)>(_a[2]))); break;
        case 1: _t->NotifyBundleUnloaded((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const BlockInfoList(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Uber::UCManagerBundles::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Uber::UCManagerBundles::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Uber__UCManagerBundles,
      qt_meta_data_Uber__UCManagerBundles, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Uber::UCManagerBundles::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Uber::UCManagerBundles::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Uber::UCManagerBundles::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Uber__UCManagerBundles))
        return static_cast<void*>(const_cast< UCManagerBundles*>(this));
    if (!strcmp(_clname, "UCSingleton<UCManagerBundles>"))
        return static_cast< UCSingleton<UCManagerBundles>*>(const_cast< UCManagerBundles*>(this));
    return QObject::qt_metacast(_clname);
}

int Uber::UCManagerBundles::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Uber::UCManagerBundles::NotifyBundleDetected(const QString & _t1, const BlockInfoList & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Uber::UCManagerBundles::NotifyBundleUnloaded(const QString & _t1, const BlockInfoList & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

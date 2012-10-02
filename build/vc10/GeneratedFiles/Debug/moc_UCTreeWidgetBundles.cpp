/****************************************************************************
** Meta object code from reading C++ file 'UCTreeWidgetBundles.h'
**
** Created: Tue 2. Oct 10:57:19 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/UCTreeWidgetBundles.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UCTreeWidgetBundles.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Uber__UCTreeWidgetBundles[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      39,   27,   26,   26, 0x08,
      93,   75,   26,   26, 0x08,
     133,   75,   26,   26, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Uber__UCTreeWidgetBundles[] = {
    "Uber::UCTreeWidgetBundles\0\0item,column\0"
    "OnItemClicked(QTreeWidgetItem*,int)\0"
    "bundleName,blocks\0"
    "OnBundleDetected(QString,BlockInfoList)\0"
    "OnBundleUnloaded(QString,BlockInfoList)\0"
};

void Uber::UCTreeWidgetBundles::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UCTreeWidgetBundles *_t = static_cast<UCTreeWidgetBundles *>(_o);
        switch (_id) {
        case 0: _t->OnItemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->OnBundleDetected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const BlockInfoList(*)>(_a[2]))); break;
        case 2: _t->OnBundleUnloaded((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const BlockInfoList(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Uber::UCTreeWidgetBundles::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Uber::UCTreeWidgetBundles::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_Uber__UCTreeWidgetBundles,
      qt_meta_data_Uber__UCTreeWidgetBundles, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Uber::UCTreeWidgetBundles::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Uber::UCTreeWidgetBundles::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Uber::UCTreeWidgetBundles::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Uber__UCTreeWidgetBundles))
        return static_cast<void*>(const_cast< UCTreeWidgetBundles*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int Uber::UCTreeWidgetBundles::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

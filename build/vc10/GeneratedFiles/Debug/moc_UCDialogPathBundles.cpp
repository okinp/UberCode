/****************************************************************************
** Meta object code from reading C++ file 'UCDialogPathBundles.h'
**
** Created: Wed 26. Sep 13:09:36 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/UCDialogPathBundles.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UCDialogPathBundles.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Uber__UCDialogPathBundles[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x0a,
      39,   26,   26,   26, 0x0a,
      54,   26,   26,   26, 0x0a,
      70,   65,   26,   26, 0x0a,
     117,  103,   26,   26, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Uber__UCDialogPathBundles[] = {
    "Uber::UCDialogPathBundles\0\0OnAddItem()\0"
    "OnRemoveItem()\0OnAccept()\0item\0"
    "OnInsertWidget(QListWidgetItem*)\0"
    "next,previous\0"
    "OnRemoveWidget(QListWidgetItem*,QListWidgetItem*)\0"
};

void Uber::UCDialogPathBundles::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UCDialogPathBundles *_t = static_cast<UCDialogPathBundles *>(_o);
        switch (_id) {
        case 0: _t->OnAddItem(); break;
        case 1: _t->OnRemoveItem(); break;
        case 2: _t->OnAccept(); break;
        case 3: _t->OnInsertWidget((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->OnRemoveWidget((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Uber::UCDialogPathBundles::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Uber::UCDialogPathBundles::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Uber__UCDialogPathBundles,
      qt_meta_data_Uber__UCDialogPathBundles, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Uber::UCDialogPathBundles::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Uber::UCDialogPathBundles::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Uber::UCDialogPathBundles::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Uber__UCDialogPathBundles))
        return static_cast<void*>(const_cast< UCDialogPathBundles*>(this));
    return QDialog::qt_metacast(_clname);
}

int Uber::UCDialogPathBundles::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
static const uint qt_meta_data_Uber__UCPathBundlesWidgetItem[] = {

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
      31,   30,   30,   30, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Uber__UCPathBundlesWidgetItem[] = {
    "Uber::UCPathBundlesWidgetItem\0\0"
    "OnOpenFolder()\0"
};

void Uber::UCPathBundlesWidgetItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UCPathBundlesWidgetItem *_t = static_cast<UCPathBundlesWidgetItem *>(_o);
        switch (_id) {
        case 0: _t->OnOpenFolder(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Uber::UCPathBundlesWidgetItem::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Uber::UCPathBundlesWidgetItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Uber__UCPathBundlesWidgetItem,
      qt_meta_data_Uber__UCPathBundlesWidgetItem, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Uber::UCPathBundlesWidgetItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Uber::UCPathBundlesWidgetItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Uber::UCPathBundlesWidgetItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Uber__UCPathBundlesWidgetItem))
        return static_cast<void*>(const_cast< UCPathBundlesWidgetItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int Uber::UCPathBundlesWidgetItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

/****************************************************************************
** Meta object code from reading C++ file 'UCWindowMain.h'
**
** Created: Tue 2. Oct 10:57:19 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/UCWindowMain.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UCWindowMain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Uber__UCWindowMain[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      34,   19,   19,   19, 0x08,
      48,   19,   19,   19, 0x08,
      61,   19,   19,   19, 0x08,
      82,   19,   19,   19, 0x08,
      96,   19,   19,   19, 0x08,
     124,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Uber__UCWindowMain[] = {
    "Uber::UCWindowMain\0\0OnLoadScene()\0"
    "OnSaveScene()\0OnNewScene()\0"
    "OnDocumentModified()\0OnShowAbout()\0"
    "OnShowSettingsPathBundles()\0"
    "OnBundleRefresh()\0"
};

void Uber::UCWindowMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UCWindowMain *_t = static_cast<UCWindowMain *>(_o);
        switch (_id) {
        case 0: _t->OnLoadScene(); break;
        case 1: _t->OnSaveScene(); break;
        case 2: _t->OnNewScene(); break;
        case 3: _t->OnDocumentModified(); break;
        case 4: _t->OnShowAbout(); break;
        case 5: _t->OnShowSettingsPathBundles(); break;
        case 6: _t->OnBundleRefresh(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Uber::UCWindowMain::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Uber::UCWindowMain::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Uber__UCWindowMain,
      qt_meta_data_Uber__UCWindowMain, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Uber::UCWindowMain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Uber::UCWindowMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Uber::UCWindowMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Uber__UCWindowMain))
        return static_cast<void*>(const_cast< UCWindowMain*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Uber::UCWindowMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

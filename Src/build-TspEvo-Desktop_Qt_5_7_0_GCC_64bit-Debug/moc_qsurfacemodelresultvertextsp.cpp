/****************************************************************************
** Meta object code from reading C++ file 'qsurfacemodelresultvertextsp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TspEvo/qsurfacemodelresultvertextsp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsurfacemodelresultvertextsp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QSurfaceModelResultVertexTsp_t {
    QByteArrayData data[8];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSurfaceModelResultVertexTsp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSurfaceModelResultVertexTsp_t qt_meta_stringdata_QSurfaceModelResultVertexTsp = {
    {
QT_MOC_LITERAL(0, 0, 28), // "QSurfaceModelResultVertexTsp"
QT_MOC_LITERAL(1, 29, 13), // "lengthChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 11), // "costChanged"
QT_MOC_LITERAL(4, 56, 17), // "generationChanged"
QT_MOC_LITERAL(5, 74, 6), // "length"
QT_MOC_LITERAL(6, 81, 4), // "cost"
QT_MOC_LITERAL(7, 86, 10) // "generation"

    },
    "QSurfaceModelResultVertexTsp\0lengthChanged\0"
    "\0costChanged\0generationChanged\0length\0"
    "cost\0generation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSurfaceModelResultVertexTsp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       5, QMetaType::Double, 0x00495103,
       6, QMetaType::Double, 0x00495103,
       7, QMetaType::Double, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void QSurfaceModelResultVertexTsp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QSurfaceModelResultVertexTsp *_t = static_cast<QSurfaceModelResultVertexTsp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lengthChanged(); break;
        case 1: _t->costChanged(); break;
        case 2: _t->generationChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QSurfaceModelResultVertexTsp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSurfaceModelResultVertexTsp::lengthChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QSurfaceModelResultVertexTsp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSurfaceModelResultVertexTsp::costChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QSurfaceModelResultVertexTsp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSurfaceModelResultVertexTsp::generationChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QSurfaceModelResultVertexTsp *_t = static_cast<QSurfaceModelResultVertexTsp *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->getLength(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->getCost(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->getGeneration(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QSurfaceModelResultVertexTsp *_t = static_cast<QSurfaceModelResultVertexTsp *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLength(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setCost(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->setGeneration(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject QSurfaceModelResultVertexTsp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSurfaceModelResultVertexTsp.data,
      qt_meta_data_QSurfaceModelResultVertexTsp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QSurfaceModelResultVertexTsp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSurfaceModelResultVertexTsp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QSurfaceModelResultVertexTsp.stringdata0))
        return static_cast<void*>(const_cast< QSurfaceModelResultVertexTsp*>(this));
    return QObject::qt_metacast(_clname);
}

int QSurfaceModelResultVertexTsp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QSurfaceModelResultVertexTsp::lengthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void QSurfaceModelResultVertexTsp::costChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void QSurfaceModelResultVertexTsp::generationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

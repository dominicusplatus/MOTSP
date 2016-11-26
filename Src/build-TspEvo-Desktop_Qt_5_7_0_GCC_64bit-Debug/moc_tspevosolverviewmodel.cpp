/****************************************************************************
** Meta object code from reading C++ file 'tspevosolverviewmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TspEvo/Model/tspevosolverviewmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tspevosolverviewmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TspEvoSolverViewModel_t {
    QByteArrayData data[18];
    char stringdata0[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TspEvoSolverViewModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TspEvoSolverViewModel_t qt_meta_stringdata_TspEvoSolverViewModel = {
    {
QT_MOC_LITERAL(0, 0, 21), // "TspEvoSolverViewModel"
QT_MOC_LITERAL(1, 22, 18), // "DidSolveGeneration"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 17), // "populationChanged"
QT_MOC_LITERAL(4, 60, 12), // "eoPop<Route>"
QT_MOC_LITERAL(5, 73, 13), // "newPopulation"
QT_MOC_LITERAL(6, 87, 21), // "populationSizeChanged"
QT_MOC_LITERAL(7, 109, 7), // "newSize"
QT_MOC_LITERAL(8, 117, 19), // "historyModelChanged"
QT_MOC_LITERAL(9, 137, 30), // "TspEvoFitnessHistoryDataModel*"
QT_MOC_LITERAL(10, 168, 13), // "setPopulation"
QT_MOC_LITERAL(11, 182, 1), // "a"
QT_MOC_LITERAL(12, 184, 17), // "setpopulationSize"
QT_MOC_LITERAL(13, 202, 15), // "sethistoryModel"
QT_MOC_LITERAL(14, 218, 5), // "Solve"
QT_MOC_LITERAL(15, 224, 10), // "population"
QT_MOC_LITERAL(16, 235, 14), // "populationSize"
QT_MOC_LITERAL(17, 250, 12) // "historyModel"

    },
    "TspEvoSolverViewModel\0DidSolveGeneration\0"
    "\0populationChanged\0eoPop<Route>\0"
    "newPopulation\0populationSizeChanged\0"
    "newSize\0historyModelChanged\0"
    "TspEvoFitnessHistoryDataModel*\0"
    "setPopulation\0a\0setpopulationSize\0"
    "sethistoryModel\0Solve\0population\0"
    "populationSize\0historyModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TspEvoSolverViewModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       3,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       6,    1,   58,    2, 0x06 /* Public */,
       8,    1,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   64,    2, 0x0a /* Public */,
      12,    1,   67,    2, 0x0a /* Public */,
      13,    1,   70,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      14,    0,   73,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Int,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QReal,    7,
    QMetaType::Void, 0x80000000 | 9,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,   11,
    QMetaType::Void, QMetaType::QReal,   11,
    QMetaType::Void, 0x80000000 | 9,   11,

 // methods: parameters
    QMetaType::Void,

 // properties: name, type, flags
      15, 0x80000000 | 4, 0x0049510b,
      16, QMetaType::QReal, 0x00495003,
      17, 0x80000000 | 9, 0x0049500b,

 // properties: notify_signal_id
       1,
       2,
       3,

       0        // eod
};

void TspEvoSolverViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TspEvoSolverViewModel *_t = static_cast<TspEvoSolverViewModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->DidSolveGeneration();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: _t->populationChanged((*reinterpret_cast< const eoPop<Route>(*)>(_a[1]))); break;
        case 2: _t->populationSizeChanged((*reinterpret_cast< const qreal(*)>(_a[1]))); break;
        case 3: _t->historyModelChanged((*reinterpret_cast< const TspEvoFitnessHistoryDataModel*(*)>(_a[1]))); break;
        case 4: _t->setPopulation((*reinterpret_cast< eoPop<Route>(*)>(_a[1]))); break;
        case 5: _t->setpopulationSize((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 6: _t->sethistoryModel((*reinterpret_cast< TspEvoFitnessHistoryDataModel*(*)>(_a[1]))); break;
        case 7: _t->Solve(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TspEvoFitnessHistoryDataModel* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TspEvoFitnessHistoryDataModel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef int (TspEvoSolverViewModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TspEvoSolverViewModel::DidSolveGeneration)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TspEvoSolverViewModel::*_t)(const eoPop<Route> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TspEvoSolverViewModel::populationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TspEvoSolverViewModel::*_t)(const qreal & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TspEvoSolverViewModel::populationSizeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TspEvoSolverViewModel::*_t)(const TspEvoFitnessHistoryDataModel * & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TspEvoSolverViewModel::historyModelChanged)) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TspEvoFitnessHistoryDataModel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        TspEvoSolverViewModel *_t = static_cast<TspEvoSolverViewModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< eoPop<Route>*>(_v) = _t->getPopulation(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->getpopulationSize(); break;
        case 2: *reinterpret_cast< TspEvoFitnessHistoryDataModel**>(_v) = _t->gethistoryModel(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        TspEvoSolverViewModel *_t = static_cast<TspEvoSolverViewModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPopulation(*reinterpret_cast< eoPop<Route>*>(_v)); break;
        case 1: _t->setpopulationSize(*reinterpret_cast< qreal*>(_v)); break;
        case 2: _t->sethistoryModel(*reinterpret_cast< TspEvoFitnessHistoryDataModel**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject TspEvoSolverViewModel::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_TspEvoSolverViewModel.data,
      qt_meta_data_TspEvoSolverViewModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TspEvoSolverViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TspEvoSolverViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TspEvoSolverViewModel.stringdata0))
        return static_cast<void*>(const_cast< TspEvoSolverViewModel*>(this));
    return QAbstractTableModel::qt_metacast(_clname);
}

int TspEvoSolverViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
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
int TspEvoSolverViewModel::DidSolveGeneration()
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
void TspEvoSolverViewModel::populationChanged(const eoPop<Route> & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TspEvoSolverViewModel::populationSizeChanged(const qreal & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TspEvoSolverViewModel::historyModelChanged(const TspEvoFitnessHistoryDataModel * & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

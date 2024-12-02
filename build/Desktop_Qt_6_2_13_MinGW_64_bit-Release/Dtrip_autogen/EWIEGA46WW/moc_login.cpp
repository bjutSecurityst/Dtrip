/****************************************************************************
** Meta object code from reading C++ file 'login.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../login.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'login.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Login_t {
    uint offsetsAndSizes[60];
    char stringdata0[377];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Login_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_Login_t qt_meta_stringdata_Login = {
    {
        QT_MOC_LITERAL(0, 5),  // "Login"
        QT_MOC_LITERAL(6, 16),  // "sendToMainWindow"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 4),  // "name"
        QT_MOC_LITERAL(29, 4),  // "Log*"
        QT_MOC_LITERAL(34, 4),  // "logs"
        QT_MOC_LITERAL(39, 7),  // "prelogs"
        QT_MOC_LITERAL(47, 11),  // "myticketnum"
        QT_MOC_LITERAL(59, 14),  // "allmyticektnum"
        QT_MOC_LITERAL(74, 4),  // "home"
        QT_MOC_LITERAL(79, 11),  // "probability"
        QT_MOC_LITERAL(91, 6),  // "common"
        QT_MOC_LITERAL(98, 3),  // "pco"
        QT_MOC_LITERAL(102, 10),  // "time_money"
        QT_MOC_LITERAL(113, 9),  // "time_time"
        QT_MOC_LITERAL(123, 13),  // "time_straight"
        QT_MOC_LITERAL(137, 6),  // "float*"
        QT_MOC_LITERAL(144, 13),  // "citytimesfrom"
        QT_MOC_LITERAL(158, 11),  // "citytimesto"
        QT_MOC_LITERAL(170, 4),  // "cost"
        QT_MOC_LITERAL(175, 4),  // "mile"
        QT_MOC_LITERAL(180, 23),  // "on_pushButton_5_clicked"
        QT_MOC_LITERAL(204, 23),  // "on_pushButton_2_clicked"
        QT_MOC_LITERAL(228, 31),  // "on_checkBox_2_checkStateChanged"
        QT_MOC_LITERAL(260, 14),  // "Qt::CheckState"
        QT_MOC_LITERAL(275, 4),  // "arg1"
        QT_MOC_LITERAL(280, 26),  // "on_checkBox_2_stateChanged"
        QT_MOC_LITERAL(307, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(329, 23),  // "on_pushButton_3_clicked"
        QT_MOC_LITERAL(353, 23)   // "on_pushButton_6_clicked"
    },
    "Login\0sendToMainWindow\0\0name\0Log*\0"
    "logs\0prelogs\0myticketnum\0allmyticektnum\0"
    "home\0probability\0common\0pco\0time_money\0"
    "time_time\0time_straight\0float*\0"
    "citytimesfrom\0citytimesto\0cost\0mile\0"
    "on_pushButton_5_clicked\0on_pushButton_2_clicked\0"
    "on_checkBox_2_checkStateChanged\0"
    "Qt::CheckState\0arg1\0on_checkBox_2_stateChanged\0"
    "on_pushButton_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_6_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Login[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,   16,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      21,    0,   95,    2, 0x08,   18 /* Private */,
      22,    0,   96,    2, 0x08,   19 /* Private */,
      23,    1,   97,    2, 0x08,   20 /* Private */,
      26,    1,  100,    2, 0x08,   22 /* Private */,
      27,    0,  103,    2, 0x08,   24 /* Private */,
      28,    0,  104,    2, 0x08,   25 /* Private */,
      29,    0,  105,    2, 0x08,   26 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Int, QMetaType::Double, QMetaType::Float, QMetaType::Float, QMetaType::Float, 0x80000000 | 16, 0x80000000 | 16, QMetaType::Int, QMetaType::Int,    3,    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,   17,   18,   19,   20,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Login::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Login *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendToMainWindow((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Log*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<Log*>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<float*>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<float*>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[15])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[16]))); break;
        case 1: _t->on_pushButton_5_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_checkBox_2_checkStateChanged((*reinterpret_cast< std::add_pointer_t<Qt::CheckState>>(_a[1]))); break;
        case 4: _t->on_checkBox_2_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->on_pushButton_6_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Login::*)(QString , Log * , Log * , int , int , int , double , int , double , float , float , float , float * , float * , int , int );
            if (_t _q_method = &Login::sendToMainWindow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Login::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Login.offsetsAndSizes,
    qt_meta_data_Login,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Login_t
, QtPrivate::TypeAndForceComplete<Login, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<Log *, std::false_type>, QtPrivate::TypeAndForceComplete<Log *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<float *, std::false_type>, QtPrivate::TypeAndForceComplete<float *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Qt::CheckState &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Login::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Login::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Login.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Login::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Login::sendToMainWindow(QString _t1, Log * _t2, Log * _t3, int _t4, int _t5, int _t6, double _t7, int _t8, double _t9, float _t10, float _t11, float _t12, float * _t13, float * _t14, int _t15, int _t16)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t11))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t12))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t13))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t14))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t15))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t16))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

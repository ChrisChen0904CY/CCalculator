/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../CCalculator/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "num0_clicked",
    "",
    "num1_clicked",
    "num2_clicked",
    "num3_clicked",
    "num4_clicked",
    "num5_clicked",
    "num6_clicked",
    "num7_clicked",
    "num8_clicked",
    "num9_clicked",
    "dot_clicked",
    "left_bracket_clicked",
    "right_bracket_clicked",
    "back_clicked",
    "clear_clicked",
    "pi_clicked",
    "e_clicked",
    "sin_clicked",
    "asin_clicked",
    "cos_clicked",
    "acos_clicked",
    "tan_clicked",
    "atan_clicked",
    "ln_clicked",
    "log_clicked",
    "add_clicked",
    "minus_clicked",
    "multi_clicked",
    "divid_clicked",
    "percent_clicked",
    "mod_clicked",
    "pow_clicked",
    "prod_clicked",
    "pprod_clicked",
    "equal_clicked",
    "check_clicked",
    "ans_clicked",
    "mode_change",
    "normal_mode_style_set",
    "sci_mode_style_set",
    "light_style_set",
    "dark_style_set",
    "all_history_display",
    "cur_history_display"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[92];
    char stringdata0[11];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[13];
    char stringdata5[13];
    char stringdata6[13];
    char stringdata7[13];
    char stringdata8[13];
    char stringdata9[13];
    char stringdata10[13];
    char stringdata11[13];
    char stringdata12[12];
    char stringdata13[21];
    char stringdata14[22];
    char stringdata15[13];
    char stringdata16[14];
    char stringdata17[11];
    char stringdata18[10];
    char stringdata19[12];
    char stringdata20[13];
    char stringdata21[12];
    char stringdata22[13];
    char stringdata23[12];
    char stringdata24[13];
    char stringdata25[11];
    char stringdata26[12];
    char stringdata27[12];
    char stringdata28[14];
    char stringdata29[14];
    char stringdata30[14];
    char stringdata31[16];
    char stringdata32[12];
    char stringdata33[12];
    char stringdata34[13];
    char stringdata35[14];
    char stringdata36[14];
    char stringdata37[14];
    char stringdata38[12];
    char stringdata39[12];
    char stringdata40[22];
    char stringdata41[19];
    char stringdata42[16];
    char stringdata43[15];
    char stringdata44[20];
    char stringdata45[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 12),  // "num0_clicked"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 12),  // "num1_clicked"
        QT_MOC_LITERAL(38, 12),  // "num2_clicked"
        QT_MOC_LITERAL(51, 12),  // "num3_clicked"
        QT_MOC_LITERAL(64, 12),  // "num4_clicked"
        QT_MOC_LITERAL(77, 12),  // "num5_clicked"
        QT_MOC_LITERAL(90, 12),  // "num6_clicked"
        QT_MOC_LITERAL(103, 12),  // "num7_clicked"
        QT_MOC_LITERAL(116, 12),  // "num8_clicked"
        QT_MOC_LITERAL(129, 12),  // "num9_clicked"
        QT_MOC_LITERAL(142, 11),  // "dot_clicked"
        QT_MOC_LITERAL(154, 20),  // "left_bracket_clicked"
        QT_MOC_LITERAL(175, 21),  // "right_bracket_clicked"
        QT_MOC_LITERAL(197, 12),  // "back_clicked"
        QT_MOC_LITERAL(210, 13),  // "clear_clicked"
        QT_MOC_LITERAL(224, 10),  // "pi_clicked"
        QT_MOC_LITERAL(235, 9),  // "e_clicked"
        QT_MOC_LITERAL(245, 11),  // "sin_clicked"
        QT_MOC_LITERAL(257, 12),  // "asin_clicked"
        QT_MOC_LITERAL(270, 11),  // "cos_clicked"
        QT_MOC_LITERAL(282, 12),  // "acos_clicked"
        QT_MOC_LITERAL(295, 11),  // "tan_clicked"
        QT_MOC_LITERAL(307, 12),  // "atan_clicked"
        QT_MOC_LITERAL(320, 10),  // "ln_clicked"
        QT_MOC_LITERAL(331, 11),  // "log_clicked"
        QT_MOC_LITERAL(343, 11),  // "add_clicked"
        QT_MOC_LITERAL(355, 13),  // "minus_clicked"
        QT_MOC_LITERAL(369, 13),  // "multi_clicked"
        QT_MOC_LITERAL(383, 13),  // "divid_clicked"
        QT_MOC_LITERAL(397, 15),  // "percent_clicked"
        QT_MOC_LITERAL(413, 11),  // "mod_clicked"
        QT_MOC_LITERAL(425, 11),  // "pow_clicked"
        QT_MOC_LITERAL(437, 12),  // "prod_clicked"
        QT_MOC_LITERAL(450, 13),  // "pprod_clicked"
        QT_MOC_LITERAL(464, 13),  // "equal_clicked"
        QT_MOC_LITERAL(478, 13),  // "check_clicked"
        QT_MOC_LITERAL(492, 11),  // "ans_clicked"
        QT_MOC_LITERAL(504, 11),  // "mode_change"
        QT_MOC_LITERAL(516, 21),  // "normal_mode_style_set"
        QT_MOC_LITERAL(538, 18),  // "sci_mode_style_set"
        QT_MOC_LITERAL(557, 15),  // "light_style_set"
        QT_MOC_LITERAL(573, 14),  // "dark_style_set"
        QT_MOC_LITERAL(588, 19),  // "all_history_display"
        QT_MOC_LITERAL(608, 19)   // "cur_history_display"
    },
    "MainWindow",
    "num0_clicked",
    "",
    "num1_clicked",
    "num2_clicked",
    "num3_clicked",
    "num4_clicked",
    "num5_clicked",
    "num6_clicked",
    "num7_clicked",
    "num8_clicked",
    "num9_clicked",
    "dot_clicked",
    "left_bracket_clicked",
    "right_bracket_clicked",
    "back_clicked",
    "clear_clicked",
    "pi_clicked",
    "e_clicked",
    "sin_clicked",
    "asin_clicked",
    "cos_clicked",
    "acos_clicked",
    "tan_clicked",
    "atan_clicked",
    "ln_clicked",
    "log_clicked",
    "add_clicked",
    "minus_clicked",
    "multi_clicked",
    "divid_clicked",
    "percent_clicked",
    "mod_clicked",
    "pow_clicked",
    "prod_clicked",
    "pprod_clicked",
    "equal_clicked",
    "check_clicked",
    "ans_clicked",
    "mode_change",
    "normal_mode_style_set",
    "sci_mode_style_set",
    "light_style_set",
    "dark_style_set",
    "all_history_display",
    "cur_history_display"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      44,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  278,    2, 0x0a,    1 /* Public */,
       3,    0,  279,    2, 0x0a,    2 /* Public */,
       4,    0,  280,    2, 0x0a,    3 /* Public */,
       5,    0,  281,    2, 0x0a,    4 /* Public */,
       6,    0,  282,    2, 0x0a,    5 /* Public */,
       7,    0,  283,    2, 0x0a,    6 /* Public */,
       8,    0,  284,    2, 0x0a,    7 /* Public */,
       9,    0,  285,    2, 0x0a,    8 /* Public */,
      10,    0,  286,    2, 0x0a,    9 /* Public */,
      11,    0,  287,    2, 0x0a,   10 /* Public */,
      12,    0,  288,    2, 0x0a,   11 /* Public */,
      13,    0,  289,    2, 0x0a,   12 /* Public */,
      14,    0,  290,    2, 0x0a,   13 /* Public */,
      15,    0,  291,    2, 0x0a,   14 /* Public */,
      16,    0,  292,    2, 0x0a,   15 /* Public */,
      17,    0,  293,    2, 0x0a,   16 /* Public */,
      18,    0,  294,    2, 0x0a,   17 /* Public */,
      19,    0,  295,    2, 0x0a,   18 /* Public */,
      20,    0,  296,    2, 0x0a,   19 /* Public */,
      21,    0,  297,    2, 0x0a,   20 /* Public */,
      22,    0,  298,    2, 0x0a,   21 /* Public */,
      23,    0,  299,    2, 0x0a,   22 /* Public */,
      24,    0,  300,    2, 0x0a,   23 /* Public */,
      25,    0,  301,    2, 0x0a,   24 /* Public */,
      26,    0,  302,    2, 0x0a,   25 /* Public */,
      27,    0,  303,    2, 0x0a,   26 /* Public */,
      28,    0,  304,    2, 0x0a,   27 /* Public */,
      29,    0,  305,    2, 0x0a,   28 /* Public */,
      30,    0,  306,    2, 0x0a,   29 /* Public */,
      31,    0,  307,    2, 0x0a,   30 /* Public */,
      32,    0,  308,    2, 0x0a,   31 /* Public */,
      33,    0,  309,    2, 0x0a,   32 /* Public */,
      34,    0,  310,    2, 0x0a,   33 /* Public */,
      35,    0,  311,    2, 0x0a,   34 /* Public */,
      36,    0,  312,    2, 0x0a,   35 /* Public */,
      37,    0,  313,    2, 0x0a,   36 /* Public */,
      38,    0,  314,    2, 0x0a,   37 /* Public */,
      39,    0,  315,    2, 0x0a,   38 /* Public */,
      40,    0,  316,    2, 0x0a,   39 /* Public */,
      41,    0,  317,    2, 0x0a,   40 /* Public */,
      42,    0,  318,    2, 0x0a,   41 /* Public */,
      43,    0,  319,    2, 0x0a,   42 /* Public */,
      44,    0,  320,    2, 0x0a,   43 /* Public */,
      45,    0,  321,    2, 0x0a,   44 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'num0_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'num1_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'num2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'num3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'num4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'num5_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'num6_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'num7_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'num8_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'num9_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dot_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'left_bracket_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'right_bracket_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'back_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pi_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'e_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'asin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cos_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'acos_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tan_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'atan_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ln_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'log_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'add_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'minus_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'multi_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'divid_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'percent_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mod_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pow_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'prod_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pprod_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'equal_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'check_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ans_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mode_change'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'normal_mode_style_set'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sci_mode_style_set'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'light_style_set'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dark_style_set'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'all_history_display'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cur_history_display'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->num0_clicked(); break;
        case 1: _t->num1_clicked(); break;
        case 2: _t->num2_clicked(); break;
        case 3: _t->num3_clicked(); break;
        case 4: _t->num4_clicked(); break;
        case 5: _t->num5_clicked(); break;
        case 6: _t->num6_clicked(); break;
        case 7: _t->num7_clicked(); break;
        case 8: _t->num8_clicked(); break;
        case 9: _t->num9_clicked(); break;
        case 10: _t->dot_clicked(); break;
        case 11: _t->left_bracket_clicked(); break;
        case 12: _t->right_bracket_clicked(); break;
        case 13: _t->back_clicked(); break;
        case 14: _t->clear_clicked(); break;
        case 15: _t->pi_clicked(); break;
        case 16: _t->e_clicked(); break;
        case 17: _t->sin_clicked(); break;
        case 18: _t->asin_clicked(); break;
        case 19: _t->cos_clicked(); break;
        case 20: _t->acos_clicked(); break;
        case 21: _t->tan_clicked(); break;
        case 22: _t->atan_clicked(); break;
        case 23: _t->ln_clicked(); break;
        case 24: _t->log_clicked(); break;
        case 25: _t->add_clicked(); break;
        case 26: _t->minus_clicked(); break;
        case 27: _t->multi_clicked(); break;
        case 28: _t->divid_clicked(); break;
        case 29: _t->percent_clicked(); break;
        case 30: _t->mod_clicked(); break;
        case 31: _t->pow_clicked(); break;
        case 32: _t->prod_clicked(); break;
        case 33: _t->pprod_clicked(); break;
        case 34: _t->equal_clicked(); break;
        case 35: _t->check_clicked(); break;
        case 36: _t->ans_clicked(); break;
        case 37: _t->mode_change(); break;
        case 38: _t->normal_mode_style_set(); break;
        case 39: _t->sci_mode_style_set(); break;
        case 40: _t->light_style_set(); break;
        case 41: _t->dark_style_set(); break;
        case 42: _t->all_history_display(); break;
        case 43: _t->cur_history_display(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 44)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 44;
    }
    return _id;
}
QT_WARNING_POP

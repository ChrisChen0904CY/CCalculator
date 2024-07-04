#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QScreen>
#include <QMainWindow>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include <QMessageBox>
#include <QSpacerItem>
#include <QMap>

// SQL 数据库相关包的导入
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

// 响应键盘事件
#include <QKeyEvent>
#include <QClipboard>

#include "historyview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // 窗口移动到屏幕中央
    void move_to_center();
    // 所有按钮载入按钮容器
    void buttons_loadin();
    // 科学计算模式下专有的弹簧载入对应容器
    void sci_spacers_loadin();
    // 链接所有槽函数
    void slots_connected();
    // 输入算式显示
    void formula_display();
    // 结果显示
    void result_display();
    // 单独输入符号 补result
    void single_symbol_fix();
    /* ======================= 数据库相关函数 ========================== */
    // 建立数据库
    void DB_Create(QString File_Name);
    // 打开数据库
    void Open_DB();
    // 关闭数据库
    void Close_DB();
    // 获取全部数据
    QVector<QVector<QString>> QueryAllData();
    // 获取指定数据
    QVector<QVector<QString>> QuerySpecificData(QString col_name, QString val,
                                                QString op = "==");
    // 写入当前输入的算式和计算结果到数据库中
    void write2database();

public slots:
    // 数字键响应槽函数
    void num0_clicked();
    void num1_clicked();
    void num2_clicked();
    void num3_clicked();
    void num4_clicked();
    void num5_clicked();
    void num6_clicked();
    void num7_clicked();
    void num8_clicked();
    void num9_clicked();
    // 小数点按键响应槽函数
    void dot_clicked();
    // 括号按键响应槽函数
    void left_bracket_clicked();
    void right_bracket_clicked();
    // 退格按键响应槽函数
    void back_clicked();
    // 清空按键响应槽函数
    void clear_clicked();
    // 特殊数字按键响应槽函数
    void pi_clicked();
    void e_clicked();
    // 函数运算符
    void sin_clicked();
    void asin_clicked();
    void cos_clicked();
    void acos_clicked();
    void tan_clicked();
    void atan_clicked();
    void ln_clicked();
    void log_clicked();
    // 运算符按键响应槽函数
    void add_clicked();
    void minus_clicked();
    void multi_clicked();
    void divid_clicked();
    void percent_clicked();
    void mod_clicked();
    void pow_clicked();
    void prod_clicked();
    void pprod_clicked();
    // 等于号按键响应槽函数
    void equal_clicked();
    // 错误自检按键响应槽函数
    void check_clicked();
    // 结果调用按键响应槽函数
    void ans_clicked();
    // 模式切换槽函数
    void mode_change();
    // 普通模式样式调整
    void normal_mode_style_set();
    // 科学计算模式样式调整
    void sci_mode_style_set();

    /* 样式设置 */
    // 浅色背景
    void light_style_set();
    // 深色背景
    void dark_style_set();

    /* 历史记录查看 */
    void all_history_display();
    void cur_history_display();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
    // 当前输入的算式文本
    QString formula_text = "";
    // 将显示文本转成易解析的文本
    QString formula_cal_text = "";
    // 计算结果
    double result = 0.0;
    // 结果文本
    QString result_text = "";
    // 解析字符对应的显示字符串
    QMap<QChar, QString> sysmbol_map = {{'0', "0"},
                                        {'1', "1"},
                                        {'2', "2"},
                                        {'3', "3"},
                                        {'4', "4"},
                                        {'5', "5"},
                                        {'6', "6"},
                                        {'7', "7"},
                                        {'8', "8"},
                                        {'9', "9"},
                                        {'(', "("},
                                        {')', ")"},
                                        {'+', "+"},
                                        {'-', "-"},
                                        {'*', "×"},
                                        {'/', "÷"},
                                        {'^', "^"},
                                        {'!', "!"},
                                        {'%', "%"},
                                        {'@', "!!"},
                                        {'M', " MOD "},
                                        {'P', "π"},
                                        {'E', "e"},
                                        {'S', "sin"},
                                        {'s', "arcsin"},
                                        {'C', "cos"},
                                        {'c', "arccos"},
                                        {'T', "tan"},
                                        {'t', "arctan"},
                                        {'L', "ln"},
                                        {'l', "log"}};
    QMap<QString, QChar> sysmbol_rmap;
    // 按钮容器
    QVector<QPushButton*> buttons;
    // 科学模式专有弹簧容器
    QVector<QSpacerItem*> sci_spacers;
    // 历史记录窗口
    HistoryView* history_view = NULL;
    // 当前打开时间 --- 计算器本次打开的时间
    QString open_time;
};
#endif // MAINWINDOW_H

#ifndef STYLES_H
#define STYLES_H

#include <QMap>
#include <QString>
#include <QVector>

/*
 * 样式容器命名规范 --- x_Styles, 其中x为您提供的预设方案的名字
 * 最后需要以您提供的预设方案的名字为键名将方案QSS容器直接写入QMap styleMap中
 * 传入的样式容器中应按照下述顺序传入(传空字符串表示维持不变)：
 * 1. 计算器背景颜色 --- 即主窗口的背景颜色
 * 2. 数字/小数点/Answer按键的 Style
 * 3. 第一列运算符 --- +, -, ^
 * 4. 第二列运算符 --- ×, ÷, !
 * 5. 第三列运算符 --- %, MOD, !!
 * 6. 两个括号按钮的 Style
 * 7. 退格和清空按钮的 Style
 * 8. 两个特殊常数按钮的 Style
 * 9. 八个函数按钮的 Style
 * 10. 错误自检按钮的 Style
 * 11. 等于号按钮的 Style
 * 12. 算式输入框的 Style
 * 13. 结果展示框的 Style
*/

// Light Style
QVector<QString> Light_Styles = {"QMainWindow {background-color: rgb(255, 255, 255);}",
                                 // 数字/小数点/Answer按键
                                 "QPushButton {background-color: rgb(255, 255, 255);"
                                 "color: rgb(0, 0, 0);"
                                 "border-color: rgb(168, 168, 168);}"
                                 "QPushButton:hover {"
                                 "background-color: rgb(210, 210, 210);}",
                                 // 第一列运算符按钮
                                 "QPushButton {background-color: rgb(14, 183, 255);"
                                 "color: rgb(255, 255, 255);"
                                 "border-color: rgb(5, 120, 168);}"
                                 "QPushButton:hover {"
                                 "background-color: rgb(14, 133, 255);}",
                                 // 第二列运算符按钮
                                 "QPushButton {background-color: rgb(132, 225, 0);"
                                 "color: rgb(255, 255, 255);"
                                 "border-color: rgb(100, 168, 0);}"
                                 "QPushButton:hover {"
                                 "background-color: rgb(82, 205, 0);}",
                                 // 第三列运算符按钮
                                 "QPushButton {background-color: rgb(255, 85, 255);"
                                 "color: rgb(255, 255, 255);"
                                 "border-color: rgb(168, 25, 168);}"
                                 "QPushButton:hover {"
                                 "background-color: rgb(205, 50, 205);}",
                                 // 两个括号按钮
                                 "QPushButton {background-color: rgb(255, 157, 87);"
                                 "color: rgb(255, 255, 255);"
                                 "border-color: rgb(168, 100, 45);}"
                                 "QPushButton:hover {"
                                 "background-color: rgb(205, 100, 50);}",
                                 // 退格和清空按钮
                                 "QPushButton {background-color: rgb(255, 68, 6);"
                                 "color: rgb(255, 255, 255);"
                                 "border-color: rgb(168, 25, 5);}"
                                 "QPushButton:hover {"
                                 "background-color: rgb(204, 54, 5);}",
                                 // 两个特殊常数按钮
                                 "QPushButton {background-color: rgb(255, 157, 87);"
                                 "color: rgb(255, 255, 255);"
                                 "border-color: rgb(168, 100, 45);}"
                                 "QPushButton:hover {"
                                 "background-color: rgb(205, 100, 50);}",
                                 // 八个函数按钮
                                 "QPushButton {background-color: rgb(255, 85, 255);"
                                 "color: rgb(255, 255, 255);"
                                 "border-color: rgb(168, 25, 168);}"
                                 "QPushButton:hover {"
                                 "background-color: rgb(205, 50, 205);}",
                                 // 错误自检按钮
                                 "QPushButton {background-color: rgb(255, 26, 106);"
                                 "color: rgb(255, 255, 255);"
                                 "border-color: rgb(168, 5, 50);}"
                                 "QPushButton:hover {"
                                 "background-color: rgb(205, 15, 80);}",
                                 // 等于号按钮
                                 "QPushButton {background-color: rgb(255, 26, 106);"
                                 "color: rgb(255, 255, 255);"
                                 "border-color: rgb(168, 5, 50);}"
                                 "QPushButton:hover {"
                                 "background-color: rgb(205, 15, 80);}",
                                 // 算式输入框
                                 "QLabel {"
                                 "background-color: white;"
                                 "font: 16pt \"Microsoft YaHei UI\";"
                                 "color: black;"
                                 "border-color: black;"
                                 "}",
                                 // 结果展示框
                                 "QLabel {"
                                 "background-color: white;"
                                 "font: 16pt \"Microsoft YaHei UI\";"
                                 "color: black;"
                                 "border-color: black;"
                                 "}"};

// Dark Style
QVector<QString> Dark_Styles = {"QMainWindow {background-color: rgb(64, 65, 66);}",
                                // 数字/小数点/Answer按键
                                "QPushButton {background-color: rgb(94, 95, 96);"
                                "color: rgb(255, 255, 255);"
                                "border-color: rgb(74, 75, 76);}"
                                "QPushButton:hover {"
                                "background-color: rgb(44, 45, 46);}",
                                // 第一列运算符按钮
                                "QPushButton {background-color: rgb(94, 95, 96);"
                                "color: rgb(255, 255, 255);"
                                "border-color: rgb(74, 75, 76);}"
                                "QPushButton:hover {"
                                "background-color: rgb(44, 45, 46);}",
                                // 第二列运算符按钮
                                "QPushButton {background-color: rgb(94, 95, 96);"
                                "color: rgb(255, 255, 255);"
                                "border-color: rgb(74, 75, 76);}"
                                "QPushButton:hover {"
                                "background-color: rgb(44, 45, 46);}",
                                // 第三列运算符按钮
                                "QPushButton {background-color: rgb(94, 95, 96);"
                                "color: rgb(255, 255, 255);"
                                "border-color: rgb(74, 75, 76);}"
                                "QPushButton:hover {"
                                "background-color: rgb(44, 45, 46);}",
                                // 两个括号按钮
                                "QPushButton {background-color: rgb(94, 95, 96);"
                                "color: rgb(255, 255, 255);"
                                "border-color: rgb(74, 75, 76);}"
                                "QPushButton:hover {"
                                "background-color: rgb(44, 45, 46);}",
                                // 退格和清空按钮
                                "QPushButton {background-color: rgb(217, 123, 123);"
                                "color: rgb(255, 255, 255);"
                                "border-color: rgb(187, 93, 93);}"
                                "QPushButton:hover {"
                                "background-color: rgb(167, 73, 73);}",
                                // 两个特殊常数按钮
                                "QPushButton {background-color: rgb(94, 95, 96);"
                                "color: rgb(255, 255, 255);"
                                "border-color: rgb(74, 75, 76);}"
                                "QPushButton:hover {"
                                "background-color: rgb(44, 45, 46);}",
                                // 八个函数按钮
                                "QPushButton {background-color: rgb(94, 95, 96);"
                                "color: rgb(255, 255, 255);"
                                "border-color: rgb(74, 75, 76);}"
                                "QPushButton:hover {"
                                "background-color: rgb(44, 45, 46);}",
                                // 错误自检按钮
                                "QPushButton {background-color: rgb(217, 123, 123);"
                                "color: rgb(255, 255, 255);"
                                "border-color: rgb(187, 93, 93);}"
                                "QPushButton:hover {"
                                "background-color: rgb(167, 73, 73);}",
                                // 等于号按钮
                                "QPushButton {background-color: rgb(146, 189, 108);"
                                "color: rgb(255, 255, 255);"
                                "border-color: rgb(116, 159, 78);}"
                                "QPushButton:hover {"
                                "background-color: rgb(96, 139, 58);}",
                                // 算式输入框
                                "QLabel {"
                                "background-color: rgb(46, 47, 48);"
                                "font: 16pt \"Microsoft YaHei UI\";"
                                "color: white;"
                                "border-color: white;"
                                "}",
                                // 结果展示框
                                "QLabel {"
                                "background-color: rgb(46, 47, 48);"
                                "font: 16pt \"Microsoft YaHei UI\";"
                                "color: white;"
                                "border-color: white;"
                                "}"};

// Blue Style
QVector<QString> Blue_Styles = {"QMainWindow {background-color: rgb(112, 245, 236);}",
                                // 数字/小数点/Answer按键
                                "QPushButton {background-color: rgb(255, 255, 255);"
                                "color: rgb(0, 0, 0);"
                                "border-color: rgb(168, 168, 168);}"
                                "QPushButton:hover {"
                                "background-color: rgb(210, 210, 210);}",
                                // 第一列运算符按钮
                                "QPushButton {background-color: rgb(255, 255, 255);"
                                "color: rgb(0, 0, 0);"
                                "border-color: rgb(168, 168, 168);}"
                                "QPushButton:hover {"
                                "background-color: rgb(210, 210, 210);}",
                                // 第二列运算符按钮
                                "QPushButton {background-color: rgb(255, 255, 255);"
                                "color: rgb(0, 0, 0);"
                                "border-color: rgb(168, 168, 168);}"
                                "QPushButton:hover {"
                                "background-color: rgb(210, 210, 210);}",
                                // 第三列运算符按钮
                                "QPushButton {background-color: rgb(255, 255, 255);"
                                "color: rgb(0, 0, 0);"
                                "border-color: rgb(168, 168, 168);}"
                                "QPushButton:hover {"
                                "background-color: rgb(210, 210, 210);}",
                                // 两个括号按钮
                                "QPushButton {background-color: rgb(255, 255, 255);"
                                "color: rgb(0, 0, 0);"
                                "border-color: rgb(168, 168, 168);}"
                                "QPushButton:hover {"
                                "background-color: rgb(210, 210, 210);}",
                                // 退格和清空按钮
                                "QPushButton {background-color: rgb(255, 206, 227);"
                                "color: rgb(255, 255, 255);"
                                "border-color: rgb(225, 176, 197);}"
                                "QPushButton:hover {"
                                "background-color: rgb(205, 156, 177);}",
                                // 两个特殊常数按钮
                                "QPushButton {background-color: rgb(255, 255, 255);"
                                "color: rgb(0, 0, 0);"
                                "border-color: rgb(168, 168, 168);}"
                                "QPushButton:hover {"
                                "background-color: rgb(210, 210, 210);}",
                                // 八个函数按钮
                                "QPushButton {background-color: rgb(255, 255, 255);"
                                "color: rgb(0, 0, 0);"
                                "border-color: rgb(168, 168, 168);}"
                                "QPushButton:hover {"
                                "background-color: rgb(210, 210, 210);}",
                                // 错误自检按钮
                                "QPushButton {background-color: rgb(255, 206, 227);"
                                "color: rgb(255, 255, 255);"
                                "border-color: rgb(225, 176, 197);}"
                                "QPushButton:hover {"
                                "background-color: rgb(205, 156, 177);}",
                                // 等于号按钮
                                "QPushButton {background-color: rgb(255, 206, 227);"
                                "color: rgb(255, 255, 255);"
                                "border-color: rgb(225, 176, 197);}"
                                "QPushButton:hover {"
                                "background-color: rgb(205, 156, 177);}",
                                // 算式输入框
                                "QLabel {"
                                "background-color: white;"
                                "font: 16pt \"Microsoft YaHei UI\";"
                                "color: black;"
                                "border-color: black;"
                                "}",
                                // 结果展示框
                                "QLabel {"
                                "background-color: white;"
                                "font: 16pt \"Microsoft YaHei UI\";"
                                "color: black;"
                                "border-color: black;"
                                "}"};

// 通过方案名称映射到对应的QSS方案数组
QMap<QString, QVector<QString>> styleMap = {{"Light", Light_Styles},
                                            {"Dark", Dark_Styles},
                                            {"Blue", Blue_Styles}};

#endif // STYLES_H

#ifndef QUTILS_H
#define QUTILS_H

#include <QWidget>
#include <QRegularExpression>
#include <QString>
#include <QMap>
#include <QStringList>
#include <QDebug>
#include <QVector>
#include <QLabel>
#include <QTimer>

// 解析某一个具体的样式
QMap<QString, QString> parseStyleSettings(const QString &style);
// 解析整个样式表
QMap<QString, QMap<QString, QString>> parseStyleSheet(const QString &style);
// 根据 QSS 解析表构建 QSS 字符串
QString generateQSS(QMap<QString, QMap<QString, QString>> styleMap);
// 在控件原本的 QSS 基础上 更新其 QSS
void updateStyleSheet(QWidget* item, QString new_style);
// 给一个 QLabel 设置图片背景进行展示
void setupLabel(QLabel* label, QString path);
// 将 Hex 颜色码转为 RGB 编码
QVector<int> hex2rgb(QString hexColor);
// 判断字符是不是函数字符
bool isFunctionSymbol(QChar c);
// 判断字符是不是数字
bool isQNum(QChar c);
// 判断小数点是否合法
bool checkDots(QString formula);
// 判断尾字符是否合法
bool checkTail(QString formula);

#endif // QUTILS_H

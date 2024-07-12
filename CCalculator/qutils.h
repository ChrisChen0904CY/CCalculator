#ifndef QUTILS_H
#define QUTILS_H

#include <QWidget>
#include <QRegularExpression>
#include <QString>
#include <QMap>
#include <QStringList>
#include <QDebug>
#include <QVector>

// 解析某一个具体的样式
QMap<QString, QString> parseStyleSettings(const QString &style);
// 解析整个样式表
QMap<QString, QMap<QString, QString>> parseStyleSheet(const QString &style);
// 根据 QSS 解析表构建 QSS 字符串
QString generateQSS(QMap<QString, QMap<QString, QString>> styleMap);
// 在控件原本的 QSS 基础上 更新其 QSS
void updateStyleSheet(QWidget* item, QString new_style);

#endif // QUTILS_H

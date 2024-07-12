#include "qutils.h"

// 解析某一个具体的样式
QMap<QString, QString> parseStyleSettings(const QString &style) {
    QMap<QString, QString> settings;

    // 正则表达式匹配 {} 中的内容
    static QRegularExpression re("\\{([^}]*)\\}");
    QRegularExpressionMatchIterator i = re.globalMatch(style);

    QStringList contents;
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        contents << match.captured(1); // 提取 {} 中的内容
    }

    // 拼接内容并用 ; 分割
    QString joinedContents = contents.join(";");
    QStringList settingsList = joinedContents.split(";");

    // 存储键名读入顺序的字符串
    QString order = "";

    // 分割每一项并存入 QMap
    for (const QString &setting : settingsList) {
        QStringList keyValue = setting.split(":");
        if (keyValue.size() == 2) {
            settings.insert(keyValue[0].trimmed(), keyValue[1].trimmed());
            order += keyValue[0].trimmed() + ";";
        }
    }

    settings.insert("Order", order);

    return settings;
}

// 解析整个样式表
QMap<QString, QMap<QString, QString>> parseStyleSheet(const QString &style) {
    QMap<QString, QMap<QString, QString>> parsed_style_sheet;

    QVector<int> openBracePositions;
    QVector<int> closeBracePositions;

    // 找到所有 { 的位置
    int openBraceIndex = style.indexOf('{');
    while (openBraceIndex != -1) {
        openBracePositions.append(openBraceIndex);
        openBraceIndex = style.indexOf('{', openBraceIndex + 1);
    }

    // 找到所有 } 的位置
    int closeBraceIndex = style.indexOf('}');
    while (closeBraceIndex != -1) {
        closeBracePositions.append(closeBraceIndex);
        closeBraceIndex = style.indexOf('}', closeBraceIndex + 1);
    }

    QString order = "";

    // 遍历每一个 { 并与前一个 } 截获当前 qss 的作用对象
    for (auto i = 0; i < openBracePositions.size(); i++) {
        int start_index = (i==0) ? 0 : (closeBracePositions[i-1]+1);
        QString domain = style.mid(start_index,
                                   openBracePositions[i]-start_index);
        QString style_settings = style.mid(openBracePositions[i],
                                           closeBracePositions[i]-openBracePositions[i]+1);
        // 加入 Map
        parsed_style_sheet.insert(domain.trimmed(),
                                  parseStyleSettings(style_settings));
        order += domain.trimmed() + ";";
    }

    parsed_style_sheet.insert("Order", {{"Order", order}});

    return parsed_style_sheet;
}

QString generateQSS(QMap<QString, QMap<QString, QString>> styleMap) {
    QString qss = "";
    QVector<QString> keys;
    QString order = styleMap["Order"]["Order"];

    QString tmp = "";
    for (auto i = 0; i < order.size(); i++) {
        if (order[i] != ';') {
            tmp += order[i];
        }
        else {
            keys.append(tmp);
            tmp = "";
        }
    }

    // 遍历键名
    for (auto i = 0; i < keys.size(); i++) {
        QString key = keys[i];
        qss += key + " {\n";
        QMap<QString, QString> subMap = styleMap[key];
        // 获取子表语句顺序
        QVector<QString> sub_keys;
        QString sub_order = subMap["Order"];
        for (auto j = 0; j < sub_order.size(); j++) {
            if (sub_order[j] != ';') {
                tmp += sub_order[j];
            }
            else {
                sub_keys.append(tmp);
                tmp = "";
            }
        }
        // 遍历该对象每一条qss样式设置
        for (auto j = 0; j < sub_keys.size(); j++) {
            qss += "\t" + sub_keys[j] + ": " + subMap[sub_keys[j]] + ";\n";
        }
        qss += "\n}";
    }
    // qDebug()<<qss;
    return qss;
}


// 在控件原本的 QSS 基础上 更新其 QSS
void updateStyleSheet(QWidget* item, QString new_style) {
    QString ori_style = item->styleSheet();
    // 分别解析原有和现有的 QSS 表
    QMap<QString, QMap<QString, QString>> parsed_ori = parseStyleSheet(ori_style);
    QMap<QString, QMap<QString, QString>> parsed_new = parseStyleSheet(new_style);
    // 根据 Order 遍历新表的键值对 然后更新已有的值 加入新来的值
    QVector<QString> keys;
    QString order = parsed_new["Order"]["Order"];

    QString tmp = "";
    for (auto i = 0; i < order.size(); i++) {
        if (order[i] != ';') {
            tmp += order[i];
        }
        else {
            keys.append(tmp);
            tmp = "";
        }
    }

    for (auto i = 0; i < keys.size(); i++) {
        if (parsed_ori.contains(keys[i])) {
            // 获取该类型的 qss 语句顺序
            QVector<QString> sub_keys;
            QString sub_order = parsed_new[keys[i]]["Order"];
            for (auto j = 0; j < sub_order.size(); j++) {
                if (sub_order[j] != ';') {
                    tmp += sub_order[j];
                }
                else {
                    sub_keys.append(tmp);
                    tmp = "";
                }
            }
            // 更新已有键名的值并更新Order
            for (auto j = 0; j < sub_keys.size(); j++) {
                if (!parsed_ori[keys[i]].contains(sub_keys[j])) {
                    // 将新键名尾缀入order
                    parsed_ori[keys[i]]["Order"] += sub_keys[j] + ";";
                }
                parsed_ori[keys[i]][sub_keys[j]] = parsed_new[keys[i]][sub_keys[j]];
            }
        }
        // 如果不存在该键名直接加入一整个新条目
        else {
            parsed_ori[keys[i]] = parsed_new[keys[i]];
            // 更新Order
            parsed_ori["Order"]["Order"] += keys[i] + ";";
        }
    }
    // 生成 QSS 表达式并设置给控件
    item->setStyleSheet(generateQSS(parsed_ori));
}

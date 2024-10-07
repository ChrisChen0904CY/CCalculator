#include "qutils.h"

// 所有运算符的计算替换字符
QString myOpsString = "+-*/()!@M%";

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

// 给一个 QLabel 设置图片背景进行展示
void setupLabel(QLabel* label, QString path) {
    // 加载资源文件中的图片
    QPixmap pixmap(path);

    // 检查图片是否加载成功
    if (!pixmap.isNull()) {
        // 使用 QTimer::singleShot 延迟设置图片，以确保 QLabel 已经调整到最终大小
        QTimer::singleShot(0, label, [label, pixmap]() {
            // 获取label的实际大小
            QSize labelSize = label->size();

            // 获取pixmap的宽高比
            qreal pixmapAspectRatio = qreal(pixmap.width()) / qreal(pixmap.height());

            // 获取label的宽高比
            qreal labelAspectRatio = qreal(labelSize.width()) / qreal(labelSize.height());

            // 设置图片自适应标签大小，同时保持图片宽高比
            if (pixmapAspectRatio > labelAspectRatio) {
                label->setPixmap(pixmap.scaledToWidth(labelSize.width(),
                                                      Qt::SmoothTransformation));
            } else {
                label->setPixmap(pixmap.scaledToHeight(labelSize.height(),
                                                       Qt::SmoothTransformation));
            }

            // 这一步自动填充背景不能省略
            label->setAutoFillBackground(true);
        });
    } else {
        // 处理加载失败的情况
        qDebug() << "Failed to load image";
    }
}

int hex2int(QChar c) {
    char cc = c.toLatin1();
    if ('0' <= cc && cc <= '9') {
        return cc - '0';
    }
    else if ('a' <= cc && cc <= 'z') {
        return cc - 'a' + 10;
    }
    else if ('A' <= cc && cc <= 'Z') {
        return cc - 'A' + 10;
    }
    return -1;
}

// 将 Hex 颜色码转为 RGB 编码
QVector<int> hex2rgb(QString hexColor) {
    QVector<int> rgbColors;
    for (auto i = 1; i <= 6; i += 2) {
        rgbColors.append(hex2int(hexColor[i])*16+hex2int(hexColor[i+1]));
    }
    return rgbColors;
}

// 判断字符是不是函数字符
bool isFunctionSymbol(QChar c) {
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
        // 筛除特殊数字
        if (c == 'P' || c == 'E') {
            return false;
        }
        // 筛除取余
        else if (c == 'M') {
            return false;
        }
        return true;
    }
    // 幂次同样当作函数处理
    else if (c == '^') {
        return true;
    }
    return false;
}

// 判断字符是不是数字
bool isQNum(QChar c) {
    if (c == 'P' || c == 'E') {
        return true;
    }
    else if ('0' <= c && c <= '9') {
        return true;
    }
    return false;
}

// 判断小数点是否合法
bool checkDots(QString formula) {
    // 初始小数点允许存在
    bool dotAllowed = true;
    // 遍历计算式判断小数点是否合法
    for (auto i = 0; i < formula.size(); i++) {
        QChar c = formula[i];
        // 遇到运算符自动允许输入小数点 --- 右括号、阶乘、百分号除外
        if (myOpsString.indexOf(c) != -1) {
            if (c != ')' && c != '!' && c != '@' && c != '%') {
                dotAllowed = true;
            }
            else {
                dotAllowed = false;
            }
        }
        // 遇到小数点则禁止继续输入小数点
        if (c == '.') {
            // 判断是否允许存在
            if (!dotAllowed) {
                return false;
            }
            dotAllowed = false;
        }
    }
    // 通过遍历检验则回真
    return true;
}

// 判断尾字符是否合法
bool checkTail(QString formula) {
    // 获取尾字符
    QChar tailChar = formula.back();
    // 判断是否合法
    if (myOpsString.indexOf(tailChar) != -1) {
        if (tailChar != ')' && tailChar != '!' && tailChar != '@' && tailChar != '%') {
            return false;
        }
    }
    return true;
}

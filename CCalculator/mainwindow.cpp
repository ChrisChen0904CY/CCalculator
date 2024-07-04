#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "utils.h"

// 数据库
QSqlDatabase db;

vector<double> num_vec;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 载入所有按钮到容器中
    buttons_loadin();
    sci_spacers_loadin();
    // 默认是普通模式
    normal_mode_style_set();
    // 移动到屏幕正中央
    move_to_center();
    // 链接所有槽函数
    slots_connected();
    // 反向建立符号映射表
    for (auto it = this->sysmbol_map.begin(); it != this->sysmbol_map.end(); ++it) {
        // 插入到反向映射表中
        this->sysmbol_rmap.insert(it.value(), it.key());
    }
    // 建立数据库并链接
    this->DB_Create("History.db");
    // 打开数据库
    Open_DB();
    // 获取当前时间戳
    open_time = QString::fromStdString(getCurrentTimestamp());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    // 关闭打开了的历史记录窗口
    if (this->history_view) {
        this->history_view->close();
    }
    QMainWindow::closeEvent(event);
}

void MainWindow::move_to_center() {
    // 获取屏幕的可用几何区域
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();

    // 获取窗口的大小
    QSize windowSize = this->size();

    // 计算窗口移动到中央的位置
    int x = (screenGeometry.width() - windowSize.width()) / 2;
    int y = (screenGeometry.height() - windowSize.height()) / 2;

    // 移动窗口到新的位置
    this->move(x, y);
}

// 所有按钮载入按钮容器以便统一进行样式调整
void MainWindow::buttons_loadin()
{
    this->buttons.append(this->ui->pushButton);
    this->buttons.append(this->ui->pushButton_2);
    this->buttons.append(this->ui->pushButton_3);
    this->buttons.append(this->ui->pushButton_4);
    this->buttons.append(this->ui->pushButton_5);
    this->buttons.append(this->ui->pushButton_6);
    this->buttons.append(this->ui->pushButton_7);
    this->buttons.append(this->ui->pushButton_8);
    this->buttons.append(this->ui->pushButton_9);
    this->buttons.append(this->ui->pushButton_10);
    this->buttons.append(this->ui->pushButton_11);
    this->buttons.append(this->ui->pushButton_12);
    this->buttons.append(this->ui->pushButton_13);
    this->buttons.append(this->ui->pushButton_14);
    this->buttons.append(this->ui->pushButton_15);
    this->buttons.append(this->ui->pushButton_16);
    this->buttons.append(this->ui->pushButton_17);
    this->buttons.append(this->ui->pushButton_18);
    this->buttons.append(this->ui->pushButton_19);
    this->buttons.append(this->ui->pushButton_20);
    this->buttons.append(this->ui->pushButton_21);
    this->buttons.append(this->ui->pushButton_22);
    this->buttons.append(this->ui->pushButton_23);
    this->buttons.append(this->ui->pushButton_24);
    this->buttons.append(this->ui->pushButton_25);
    this->buttons.append(this->ui->pushButton_26);
    this->buttons.append(this->ui->pushButton_27);
    this->buttons.append(this->ui->pushButton_28);
    this->buttons.append(this->ui->pushButton_29);
    this->buttons.append(this->ui->pushButton_30);
    this->buttons.append(this->ui->pushButton_31);
    this->buttons.append(this->ui->pushButton_32);
    this->buttons.append(this->ui->pushButton_33);
    this->buttons.append(this->ui->pushButton_34);
    this->buttons.append(this->ui->pushButton_35);
    this->buttons.append(this->ui->pushButton_36);
    this->buttons.append(this->ui->pushButton_37);
}

// 科学计算模式下专有的弹簧载入对应容器
void MainWindow::sci_spacers_loadin()
{
    this->sci_spacers.append(this->ui->horizontalSpacer_33);
    this->sci_spacers.append(this->ui->horizontalSpacer_25);
    this->sci_spacers.append(this->ui->horizontalSpacer_26);
    this->sci_spacers.append(this->ui->horizontalSpacer_27);
    this->sci_spacers.append(this->ui->horizontalSpacer_28);
    this->sci_spacers.append(this->ui->horizontalSpacer_29);
    this->sci_spacers.append(this->ui->horizontalSpacer_30);
    this->sci_spacers.append(this->ui->horizontalSpacer_31);
    this->sci_spacers.append(this->ui->horizontalSpacer_32);
}

// 链接所有槽函数
void MainWindow::slots_connected()
{
    // 数字按键
    // 0
    connect(this->ui->pushButton_25,
            &QPushButton::clicked,
            this,
            &MainWindow::num0_clicked);
    // 1-3
    connect(this->ui->pushButton_6,
            &QPushButton::clicked,
            this,
            &MainWindow::num1_clicked);
    connect(this->ui->pushButton_7,
            &QPushButton::clicked,
            this,
            &MainWindow::num2_clicked);
    connect(this->ui->pushButton_8,
            &QPushButton::clicked,
            this,
            &MainWindow::num3_clicked);
    // 4-6
    connect(this->ui->pushButton_12,
            &QPushButton::clicked,
            this,
            &MainWindow::num4_clicked);
    connect(this->ui->pushButton_13,
            &QPushButton::clicked,
            this,
            &MainWindow::num5_clicked);
    connect(this->ui->pushButton_14,
            &QPushButton::clicked,
            this,
            &MainWindow::num6_clicked);
    // 7-9
    connect(this->ui->pushButton_18,
            &QPushButton::clicked,
            this,
            &MainWindow::num7_clicked);
    connect(this->ui->pushButton_19,
            &QPushButton::clicked,
            this,
            &MainWindow::num8_clicked);
    connect(this->ui->pushButton_20,
            &QPushButton::clicked,
            this,
            &MainWindow::num9_clicked);
    // 特殊符号按键
    // .
    connect(this->ui->pushButton_24,
            &QPushButton::clicked,
            this,
            &MainWindow::dot_clicked);
    // 左右括号
    connect(this->ui->pushButton_2,
            &QPushButton::clicked,
            this,
            &MainWindow::left_bracket_clicked);
    connect(this->ui->pushButton_3,
            &QPushButton::clicked,
            this,
            &MainWindow::right_bracket_clicked);
    // 退格 & 清除
    connect(this->ui->pushButton_4,
            &QPushButton::clicked,
            this,
            &MainWindow::back_clicked);
    connect(this->ui->pushButton_5,
            &QPushButton::clicked,
            this,
            &MainWindow::clear_clicked);
    // 特殊数字 π & e
    connect(this->ui->pushButton_27,
            &QPushButton::clicked,
            this,
            &MainWindow::pi_clicked);
    connect(this->ui->pushButton_28,
            &QPushButton::clicked,
            this,
            &MainWindow::e_clicked);
    // 函数运算
    connect(this->ui->pushButton_30,
            &QPushButton::clicked,
            this,
            &MainWindow::sin_clicked);
    connect(this->ui->pushButton_31,
            &QPushButton::clicked,
            this,
            &MainWindow::asin_clicked);
    connect(this->ui->pushButton_32,
            &QPushButton::clicked,
            this,
            &MainWindow::cos_clicked);
    connect(this->ui->pushButton_33,
            &QPushButton::clicked,
            this,
            &MainWindow::acos_clicked);
    connect(this->ui->pushButton_34,
            &QPushButton::clicked,
            this,
            &MainWindow::tan_clicked);
    connect(this->ui->pushButton_35,
            &QPushButton::clicked,
            this,
            &MainWindow::atan_clicked);
    connect(this->ui->pushButton_36,
            &QPushButton::clicked,
            this,
            &MainWindow::ln_clicked);
    connect(this->ui->pushButton_37,
            &QPushButton::clicked,
            this,
            &MainWindow::log_clicked);
    // 运算符
    connect(this->ui->pushButton_9,
            &QPushButton::clicked,
            this,
            &MainWindow::add_clicked);
    connect(this->ui->pushButton_10,
            &QPushButton::clicked,
            this,
            &MainWindow::multi_clicked);
    connect(this->ui->pushButton_11,
            &QPushButton::clicked,
            this,
            &MainWindow::percent_clicked);
    connect(this->ui->pushButton_15,
            &QPushButton::clicked,
            this,
            &MainWindow::minus_clicked);
    connect(this->ui->pushButton_16,
            &QPushButton::clicked,
            this,
            &MainWindow::divid_clicked);
    connect(this->ui->pushButton_17,
            &QPushButton::clicked,
            this,
            &MainWindow::mod_clicked);
    connect(this->ui->pushButton_21,
            &QPushButton::clicked,
            this,
            &MainWindow::pow_clicked);
    connect(this->ui->pushButton_22,
            &QPushButton::clicked,
            this,
            &MainWindow::prod_clicked);
    connect(this->ui->pushButton_23,
            &QPushButton::clicked,
            this,
            &MainWindow::pprod_clicked);
    // 等号按键响应槽函数
    connect(this->ui->pushButton_29,
            &QPushButton::clicked,
            this,
            &MainWindow::equal_clicked);
    // 错误自检按键响应槽函数
    connect(this->ui->pushButton,
            &QPushButton::clicked,
            this,
            &MainWindow::check_clicked);
    // 结果调用按键响应槽函数
    connect(this->ui->pushButton_26,
            &QPushButton::clicked,
            this,
            &MainWindow::ans_clicked);
    // 模式切换槽函数
    connect(this->ui->actionScientific,
            &QAction::triggered,
            this,
            &MainWindow::mode_change);
    /* 样式设置 */
    // 浅色设置
    connect(this->ui->actionLight,
            &QAction::triggered,
            this,
            &MainWindow::light_style_set);
    // 深色设置
    connect(this->ui->actionDark,
            &QAction::triggered,
            this,
            &MainWindow::dark_style_set);
    /* 历史记录相关槽函数 */
    connect(this->ui->actionAll_History,
            &QAction::triggered,
            this,
            &MainWindow::all_history_display);
    connect(this->ui->actionCurrent_History,
            &QAction::triggered,
            this,
            &MainWindow::cur_history_display);
}

// 输入算式显示
void MainWindow::formula_display()
{
    this->ui->label->setText(this->formula_text);
}

// 结果显示
void MainWindow::result_display()
{
    this->ui->label_2->setText(QString("%1").arg(this->result));
    // 能够正确显示结果则清空已输入的表达式
    this->formula_text = "";
    this->formula_cal_text = "";
}

// 数字键响应槽函数
void MainWindow::num0_clicked()
{
    this->formula_text += "0";
    this->formula_cal_text += "0";
    formula_display();
}
void MainWindow::num1_clicked()
{
    this->formula_text += "1";
    this->formula_cal_text += "1";
    formula_display();
}
void MainWindow::num2_clicked()
{
    this->formula_text += "2";
    this->formula_cal_text += "2";
    formula_display();
}
void MainWindow::num3_clicked()
{
    this->formula_text += "3";
    this->formula_cal_text += "3";
    formula_display();
}
void MainWindow::num4_clicked()
{
    this->formula_text += "4";
    this->formula_cal_text += "4";
    formula_display();
}
void MainWindow::num5_clicked()
{
    this->formula_text += "5";
    this->formula_cal_text += "5";
    formula_display();
}
void MainWindow::num6_clicked()
{
    this->formula_text += "6";
    this->formula_cal_text += "6";
    formula_display();
}
void MainWindow::num7_clicked()
{
    this->formula_text += "7";
    this->formula_cal_text += "7";
    formula_display();
}
void MainWindow::num8_clicked()
{
    this->formula_text += "8";
    this->formula_cal_text += "8";
    formula_display();
}
void MainWindow::num9_clicked()
{
    this->formula_text += "9";
    this->formula_cal_text += "9";
    formula_display();
}

// 单独输入符号 补result
void MainWindow::single_symbol_fix()
{
    // 若当前输入为空但直接按下符号键 则默认在其前面补一个result
    if (this->formula_text == "") {
        this->formula_text += QString("%1").arg(this->result);
        this->formula_cal_text += QString("%1").arg(this->result);
    }
}

// 小数点按键响应槽函数
void MainWindow::dot_clicked()
{
    // 若此时表达式末尾已经是小数点则禁止输入连续小数点
    if (this->formula_text.at(this->formula_text.size()-1) == '.') {
        return;
    }
    single_symbol_fix();
    this->formula_text += ".";
    this->formula_cal_text += ".";
    formula_display();
}

// 括号按键响应槽函数
void MainWindow::left_bracket_clicked()
{
    this->formula_text += "(";
    this->formula_cal_text += "(";
    formula_display();
}
void MainWindow::right_bracket_clicked()
{
    this->formula_text += ")";
    this->formula_cal_text += ")";
    formula_display();
}

// 退格按键响应槽函数
void MainWindow::back_clicked()
{
    // 当前无内容时啥也不干
    if (this->formula_text.size() == 0) {
        return;
    }

    // 获取 formula_cal_text 的尾字符
    QChar lastChar = this->formula_cal_text.at(this->formula_cal_text.size() - 1);

    // 删除 formula_cal_text 的最后一个字符
    this->formula_cal_text.chop(1);
    // 按照尾字符对应的表达式长度来删除显示式
    this->formula_text.chop(sysmbol_map[lastChar].size());

    // 更新显示
    formula_display();
}

// 清空按键响应槽函数
void MainWindow::clear_clicked()
{
    this->formula_text = "";
    this->formula_cal_text = "";
    formula_display();
}

// 特殊数字按键响应槽函数
void MainWindow::pi_clicked()
{
    this->formula_text += "π";
    // 解析时大P代表π
    this->formula_cal_text += "P";
    formula_display();
}
void MainWindow::e_clicked()
{
    this->formula_text += "e";
    this->formula_cal_text += "E";
    formula_display();
}

// 函数运算符
void MainWindow::sin_clicked()
{
    this->formula_text += "sin(";
    this->formula_cal_text += "S(";
    formula_display();
}

void MainWindow::asin_clicked()
{
    this->formula_text += "arcsin(";
    this->formula_cal_text += "s(";
    formula_display();
}

void MainWindow::cos_clicked()
{
    this->formula_text += "cos(";
    this->formula_cal_text += "C(";
    formula_display();
}

void MainWindow::acos_clicked()
{
    this->formula_text += "arccos(";
    this->formula_cal_text += "c(";
    formula_display();
}

void MainWindow::tan_clicked()
{
    this->formula_text += "tan(";
    this->formula_cal_text += "T(";
    formula_display();
}

void MainWindow::atan_clicked()
{
    this->formula_text += "arctan(";
    this->formula_cal_text += "t(";
    formula_display();
}

void MainWindow::ln_clicked()
{
    this->formula_text += "ln(";
    this->formula_cal_text += "L(";
    formula_display();
}

void MainWindow::log_clicked()
{
    this->formula_text += "log(";
    this->formula_cal_text += "l(";
    formula_display();
}

// 运算符按键响应槽函数
void MainWindow::add_clicked()
{
    if (this->result != 0) {
        single_symbol_fix();
    }
    this->formula_text += "+";
    this->formula_cal_text += "+";
    formula_display();
}
void MainWindow::minus_clicked()
{
    this->formula_text += "-";
    this->formula_cal_text += "-";
    formula_display();
}
void MainWindow::multi_clicked()
{
    single_symbol_fix();
    this->formula_text += "×";
    this->formula_cal_text += "*";
    formula_display();
}
void MainWindow::divid_clicked()
{
    single_symbol_fix();
    this->formula_text += "÷";
    this->formula_cal_text += "/";
    formula_display();
}
void MainWindow::percent_clicked()
{
    single_symbol_fix();
    this->formula_text += "%";
    this->formula_cal_text += "%";
    formula_display();
}
void MainWindow::mod_clicked()
{
    single_symbol_fix();
    this->formula_text += " MOD ";
    this->formula_cal_text += "M";
    formula_display();
}
void MainWindow::pow_clicked()
{
    single_symbol_fix();
    this->formula_text += "^(";
    this->formula_cal_text += "^(";
    formula_display();
}
void MainWindow::prod_clicked()
{
    single_symbol_fix();
    this->formula_text += "!";
    this->formula_cal_text += "!";
    formula_display();
}
void MainWindow::pprod_clicked()
{
    single_symbol_fix();
    this->formula_text += "!!";
    this->formula_cal_text += "@";
    formula_display();
}
// 等于号按键响应槽函数
void MainWindow::equal_clicked()
{
    // 重置数字列表
    num_vec = {};

    // 解析算式并显示计算结果
    string processed_formula = num_extract(this->formula_cal_text.toStdString(),
                                           num_vec);
    // qDebug() << processed_formula << "\n";

    // 连续操作符检验
    // 当前连续操作符数
    int continuous_ops = 0;

    // 遍历每一个字符进行解析
    for (int i = 0; i < processed_formula.size(); i++) {
        // 如果当前是操作符 则进行连续操作符统计
        if (processed_formula[i] == '+' || processed_formula[i] == '-' || processed_formula[i] == '*' ||\
            processed_formula[i] == '/' || processed_formula[i] == '^' || processed_formula[i] == '!' ||\
            processed_formula[i] == '@' || processed_formula[i] == '%' || processed_formula[i] == 'M')
        {
            continuous_ops++;
            // 位于尾部的连续操作符检验
            if (i == processed_formula.size()-1 && continuous_ops > 1) {
                // 则从当前位置往前 continuous_ops 个字符都有问题
                QMessageBox::critical(this, "表达式输入错误",
                                            "非法表达式！存在连续输入的操作符！");
                return;
            }
        }
        // 不是操作符则判断是否有多个连续操作符并清空计数
        else {
            if (continuous_ops > 1) {
                // 则从当前位置往前 continuous_ops 个字符都有问题
                QMessageBox::critical(this, "表达式输入错误",
                                            "非法表达式！存在连续输入的操作符！");
                return;
            }
            continuous_ops = 0;
        }
    }

    try {
        this->result = double(compute(processed_formula,
                                      num_vec));
        this->result_text = QString("%1").arg(this->result);
        // 输入非空时结果写入数据库
        if (this->formula_text.size() > 0) {
            write2database();
            // 如果此时已经打开了一个历史记录框 则更新其中的数据
            if (this->history_view) {
                // 将数据加载入页面
                QVector<QVector<QString>> data;
                if (this->history_view->windowTitle() == "All") {
                    data = QueryAllData();
                }
                else {
                    data = QuerySpecificData("timestamp",
                                             this->open_time,
                                             ">=");
                }
                // 倒置 --- 因为数据插入的顺序是从旧到新的 默认顺序越后面越新
                reverse(data.begin(), data.end());
                this->history_view->page_create(data);
                // 打开当前所在页面
                this->history_view->page_load();
            }
        }
        this->result_display();
    }
    catch(const char* msg) {
        string errorMsg(msg);
        this->ui->label_2->setText("<font color=\"red\">Error</font>");
        if (errorMsg == "非法的括号表达式！") {
            QMessageBox::critical(this, "括号错误",
                                  "非法的括号表达式 --- 括号无法正确匹配！");
        }
        else if (errorMsg == "非整数不可用于阶乘运算！") {
            QMessageBox::critical(this, "运算错误",
                                  "非整数不可用于阶乘运算！");
        }
        else if (errorMsg == "无内容的括号对是不被允许的！括号内必须有表达式！") {
            QMessageBox::critical(this, "括号错误",
                                  "无内容的括号对是不被允许的！括号内必须有表达式！");
        }
        else if (errorMsg == "不能用0作分母！！！") {
            QMessageBox::critical(this, "运算错误",
                                  "不能用0作分母！！！");
        }
        else if (errorMsg == "非法表达式！") {
            QMessageBox::critical(this, "表达式输入错误",
                                  "非法表达式！请仔细检查您的输入！");
        }
        else if (errorMsg == "空表达式！") {
            QMessageBox::critical(this, "表达式输入错误",
                                  "空表达式！上一次运算完后表达式会自动清空！");
        }
        else if (errorMsg == "对数运算中真数必须为非负数！") {
            QMessageBox::critical(this, "对数运算错误",
                                  "对数运算中真数必须为非负数！请检查您的对数运算！");
        }
        else if (errorMsg == "对数运算错误！底数必须为不是1的非负数！") {
            QMessageBox::critical(this, "对数运算错误",
                                  "对数运算错误！底数必须为不是1的非负数！");
        }
        else {
            QMessageBox::critical(this, "未知错误",
                                  "我也不知道发生了啥！！！");
        }
    }
}

// 错误自检按键响应槽函数
void MainWindow::check_clicked()
{
    // 重置数字列表
    num_vec = {};
    // 获取当前公式串转为 std::string 进行解析
    string s = num_extract(this->formula_cal_text.toStdString(),
                           num_vec);

    // 记录需要标红的字符位置
    vector<bool> wrong_pos(s.size(), false);
    // 记录需要标红的数字序号
    vector<bool> wrong_nums(num_vec.size(), false);
    // 左括号栈 --- 用于检验括号匹配错误
    stack<int> brackets;
    // 当前连续操作符数
    int continuous_ops = 0;

    // 遍历每一个字符进行解析
    for (int i = 0; i < s.size(); i++) {
        // 如果当前是操作符或小数点 则进行连续操作符统计
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' ||\
            s[i] == '/' || s[i] == '^' || s[i] == '!' ||\
            s[i] == '@' || s[i] == '%' || s[i] == 'M')
        {
            continuous_ops++;
            // 位于尾部的连续操作符检验
            if (i == s.size()-1 && continuous_ops > 1) {
                // 则从当前位置往前 continuous_ops 个字符都有问题
                for (int j = i+1-continuous_ops; j <= i; j++) {
                    wrong_pos[j] = true;
                }
            }
        }
        // 不是操作符则判断是否有多个连续操作符并清空计数
        else {
            if (continuous_ops > 1) {
                // 则从当前位置往前 continuous_ops 个字符都有问题
                for (int j = i-continuous_ops; j <= i; j++) {
                    wrong_pos[j] = true;
                }
            }
            continuous_ops = 0;
        }
        // 左括号入栈
        if (s[i] == '(') {
            brackets.push(i);
        }
        // 右括号弹出左括号
        else if (s[i] == ')') {
            // 检查是否有左括号
            if (brackets.empty()) {
                // 此时右括号是冗余 加入错误字符
                wrong_pos[i] = true;
            }
            else {
                // 否则就近弹出一个左括号
                brackets.pop();
            }
        }
    }

    // 将未配对的所有左括号加入错误字符集
    while (!brackets.empty()) {
        wrong_pos[brackets.top()] = true;
        brackets.pop();
    }

    // 标红显示每一个错误字符
    string ss = "";
    // 数字下标
    string num_id = "";
    // 遍历每一个字符进行处理
    for (int i = 0; i < s.size(); i++) {
        // 处理普通数字
        if ('0' <= s[i] && s[i] <= '9') {
            num_id += s[i];
            // 处理位于表达式末尾数字
            if (i == s.size()-1) {
                int num_id_int = stoi(num_id);
                if (wrong_nums[num_id_int]) {
                    ss += "<font color='red'>";
                }
                ss += beautiful_double_string(to_string(num_vec[num_id_int]));
                if (wrong_nums[num_id_int]) {
                    ss += "</font>";
                }
                num_id = "";
            }
        }

        // 处理非数字字符
        else {
            if (num_id != "") {
                int num_id_int = stoi(num_id);
                if (wrong_nums[num_id_int]) {
                    ss += "<font color='red'>";
                }
                ss += beautiful_double_string(to_string(num_vec[num_id_int]));
                if (wrong_nums[num_id_int]) {
                    ss += "</font>";
                }
                num_id = "";
            }

            // 处理错误字符前缀
            if (wrong_pos[i]) {
                ss += "<font color='red'>";
            }

            // 函数
            if (s[i] == 'S') {
                ss += "sin";
            }
            else if (s[i] == 's') {
                ss += "arcsin";
            }
            else if (s[i] == 'C') {
                ss += "cos";
            }
            else if (s[i] == 'c') {
                ss += "arccos";
            }
            else if (s[i] == 'T') {
                ss += "tan";
            }
            else if (s[i] == 't') {
                ss += "tan";
            }
            else if (s[i] == 'L') {
                ss += "ln";
            }
            else if (s[i] == 'l') {
                ss += "log";
            }
            // 特殊操作符 --- 需要变体的
            else if (s[i] == '@') {
                ss += "!!";
            }
            else if (s[i] == 'M') {
                ss += " MOD ";
            }
            else if (s[i] == '*') {
                ss += "×";
            }
            else if (s[i] == '/') {
                ss += "÷";
            }
            // 特殊数字
            else if (s[i] == 'P') {
                ss += "π";
            }
            else if (s[i] == 'E') {
                ss += "e";
            }
            // 普通符号直接加入
            else {
                ss += s[i];
            }
        }

        // 处理错误字符尾缀
        if (wrong_pos[i]) {
            ss += "</font>";
        }
    }

    // 暂时将输入行显示内容替换为 ss
    this->ui->label->setText(QString::fromStdString(ss));
}

// 结果调用按键响应槽函数
void MainWindow::ans_clicked()
{
    this->formula_text += QString("%1").arg(this->result);
    this->formula_cal_text += QString("%1").arg(this->result);
    this->formula_display();
}

// 普通模式样式调整
void MainWindow::normal_mode_style_set()
{
    // 先调整窗口大小
    this->setFixedSize(400, 600);
    // 随后将窗口右移 200px 防止原地缩短影响视觉效果
    this->move(this->pos().x()+200, this->pos().y());
    // 将模式切换文字改成 Scientific
    this->ui->actionScientific->setText("Scientific");
    // 接着将所有按钮的大小尺寸设置为小尺寸 40*40 并隐藏特有的8个按钮
    for (auto i = 0; i < buttons.size(); i++) {
        buttons[i]->setMinimumHeight(46);
        buttons[i]->setMinimumWidth(i == 3 ? 122 : 56);
        buttons[i]->setMaximumHeight(46);
        buttons[i]->setMaximumWidth(i == 3 ? 122 : 56);
        if (i >= 29) {
            buttons[i]->setFixedSize(0, 0);
            buttons[i]->setVisible(false);
        }
    }
    // 隐藏掉科学模式特有的弹簧以及 LOGO 标签
    this->ui->label_3->setFixedSize(0, 0);
    this->ui->label_3->setVisible(false);
    for (auto spacer:sci_spacers) {
        spacer->changeSize(0, 0);
    }
}

// 科学计算模式样式调整
void MainWindow::sci_mode_style_set()
{
    // 先调整窗口大小
    this->setFixedSize(800, 600);
    // 随后将窗口左移 200px 防止原地缩短影响视觉效果
    this->move(this->pos().x()-200, this->pos().y());
    // 将模式切换文字改成 Normal
    this->ui->actionScientific->setText("Normal");
    // 接着将所有按钮的大小尺寸设置为小尺寸 60*60 并显示特有的8个按钮
    for (auto i = 0; i < buttons.size(); i++) {
        buttons[i]->setMinimumHeight(60);
        buttons[i]->setMinimumWidth(i == 3 ? 162 : 60);
        buttons[i]->setMaximumHeight(60);
        buttons[i]->setMaximumWidth(i == 3 ? 162 : 60);
        if (i >= 29) {
            buttons[i]->setVisible(true);
        }
    }
    // 显示出科学模式特有的弹簧以及 LOGO 标签
    this->ui->label_3->setFixedSize(164, 60);
    this->ui->label_3->setVisible(true);
    for (auto spacer:sci_spacers) {
        spacer->changeSize(40, 20, QSizePolicy::Expanding);
    }
}

// 模式切换槽函数
void MainWindow::mode_change() {
    if (this->width() == 400) {
        sci_mode_style_set();
    }
    else {
        normal_mode_style_set();
    }
    // 如果有历史记录窗口 则移动到变化后的窗口右侧
    if (this->history_view) {
        // 移动到此时窗口的正右方
        this->history_view->move(this->pos().x()+this->width(),
                                 this->pos().y());
    }
}

/* 样式设置 */
// 浅色背景
void MainWindow::light_style_set() {
    this->setStyleSheet("QMainWindow {"\
                        "background-color: rgb(255, 255, 255);"\
                        "};");
}

// 深色背景
void MainWindow::dark_style_set() {
    this->setStyleSheet("QMainWindow {"\
                        "background-color: rgb(0, 0, 0);"\
                        "};");
}

/* 历史记录查看 */
void MainWindow::all_history_display() {
    // 防止重复打开
    if (this->history_view != NULL) {
        this->history_view->close();
    }
    // 构造窗口
    this->history_view = new HistoryView(nullptr, true);
    // 移动到此时窗口的正右方
    this->history_view->move(this->pos().x()+this->width(),
                             this->pos().y());
    // 将所有数据加载入页面
    QVector<QVector<QString>> data = this->QueryAllData();
    // 倒置 --- 因为数据插入的顺序是从旧到新的 默认顺序越后面越新
    reverse(data.begin(), data.end());
    this->history_view->page_create(data);
    // 显示
    this->history_view->show();
}

void MainWindow::cur_history_display() {
    // 防止重复打开
    if (this->history_view != NULL) {
        this->history_view->close();
    }
    // 构造窗口
    this->history_view = new HistoryView(nullptr, false);
    // 移动到此时窗口的正右方
    this->history_view->move(this->pos().x()+this->width(),
                             this->pos().y());
    // 将当前历史数据加载入页面
    QVector<QVector<QString>> data = this->QuerySpecificData("timestamp",
                                                             this->open_time,
                                                             ">=");
    // 倒置 --- 因为数据插入的顺序是从旧到新的 默认顺序越后面越新
    reverse(data.begin(), data.end());
    this->history_view->page_create(data);
    // 显示
    this->history_view->show();
}

/* ============================ 数据库相关函数 ================================= */
/* ======================= Functions About Database ========================== */

// 数据库建立
void MainWindow::DB_Create(QString File_Name){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(File_Name);
    db.setUserName("Admin");
    db.setPassword("12345678");
}

// 打开数据库
void MainWindow::Open_DB()
{
    if (!db.open()) {
        QMessageBox::warning(this, QObject::tr("Database Error"),
                             db.lastError().text());
    }
    // 当表格不存在时建立历史记录表
    QString table_create = "CREATE TABLE IF NOT EXISTS Histories ("\
        "input_formula TEXT,"\
        "cal_result TEXT,"\
        "timestamp DATETIME"\
        ");";
    QSqlQuery table_query;
    table_query.exec(table_create);
}

// 关闭数据库
void MainWindow::Close_DB(){
    db.close();
}

QVector<QVector<QString>> MainWindow::QueryAllData(void)
{
    QString select_all_sql = "select * from Histories;";
    QSqlQuery sql_query;
    sql_query.exec(select_all_sql);
    // Return Data
    QVector<QVector<QString>> result = {};
    while(sql_query.next())
    {
        QVector<QString> tmp;
        tmp.append(sql_query.value("input_formula").toString());
        tmp.append(sql_query.value("cal_result").toString());
        tmp.append(sql_query.value("timestamp").toString());
        result.append(tmp);
    }
    return result;
}

// 查询指定列的指定数据
QVector<QVector<QString>> MainWindow::QuerySpecificData(QString col_name, QString val,
                                                        QString op){
    QString select_sql = "select * from Histories where ";
    select_sql.append(col_name);
    select_sql.append(op+"\"");
    select_sql.append(val);
    select_sql.append("\";");
    QSqlQuery sql_query;
    sql_query.exec(select_sql);
    // Return Data
    QVector<QVector<QString>> result = {};
    while(sql_query.next())
    {
        QVector<QString> tmp;
        tmp.append(sql_query.value("input_formula").toString());
        tmp.append(sql_query.value("cal_result").toString());
        tmp.append(sql_query.value("timestamp").toString());
        result.append(tmp);
    }
    return result;
}

// 写入当前输入的算式和计算结果到数据库中
void MainWindow::write2database() {
    // 获取当前时间戳
    QString current_time = QString::fromStdString(getCurrentTimestamp());

    // 准备 SQL 查询
    QSqlQuery query;
    query.prepare("INSERT INTO Histories (input_formula, cal_result, timestamp) "
                  "VALUES (:input_formula, :cal_result, :timestamp)");

    // 绑定值到查询中
    query.bindValue(":input_formula", this->formula_text);
    query.bindValue(":cal_result", this->result_text);
    query.bindValue(":timestamp", current_time);

    // 执行查询并检查错误
    if (!query.exec()) {
        qDebug() << "Error inserting into table:\n" << query.lastError();
    } else {
        qDebug() << "Record inserted successfully at " << current_time;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    // 检查是否按下 Ctrl+V
    if (event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_V) {
        // 获取剪贴板内容
        QClipboard *clipboard = QApplication::clipboard();
        QString clipboardText = clipboard->text();

        // 调试输出剪贴板内容
        // qDebug() << "Clipboard content:" << clipboardText;

        // 处理剪贴板内容 --- 处理前赋值给 formula_text
        this->formula_text = clipboardText;
        // 处理后给 formula_cal_text
        // 用符号反向映射表替换剪贴板内容中的子串
        for (auto it = sysmbol_rmap.begin(); it != sysmbol_rmap.end(); ++it) {
            clipboardText.replace(it.key(), it.value());
        }
        this->formula_cal_text = clipboardText;

        // 更新公式展示框
        this->formula_display();

        return;
    }

    // 调用基类的事件处理函数
    QWidget::keyPressEvent(event);
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "utils.h"
#include "qutils.h"

// 样式头文件
#include "styles.h"

// 关于页面
#include "aboutpagelite.h"

// 帮助页面
#include "helpdialog.h"

// 数据库
QSqlDatabase db;

vector<double> num_vec;

MainWindow::MainWindow(QWidget *parent, bool lite)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , liteVersion(lite)
{
    ui->setupUi(this);
    // 为 Logo 标签绑上点击事件
    logoFilter = new ClickableLabelFilter(this);
    this->ui->label_3->installEventFilter(logoFilter);
    // 初始化辅助显示框
    aidInit();
    // 将软件主窗口标题后缀加上版本号
    this->setWindowTitle("CCalculator v"+this->current_version);
    // 检查初始化文件
    ini_check();
    // 载入所有按钮到容器中
    buttons_loadin();
    sci_spacers_loadin();
    // 默认是普通模式
    normal_mode_style_set();
    // 移动到屏幕正中央
    move_to_center(this);
    // 链接所有槽函数
    slots_connected();
    // 反向建立符号映射表
    for (auto it = this->symbol_map.begin(); it != this->symbol_map.end(); ++it) {
        // 插入到反向映射表中
        this->sysmbol_rmap.insert(it.value(), it.key());
    }
    // 建立数据库并链接
    this->DB_Create("History.db");
    // 打开数据库
    Open_DB();
    // 获取当前时间戳
    open_time = QString::fromStdString(getCurrentTimestamp());
    // 设置上一次使用的配色方案
    style_initialize();
    // 设置上一次关闭时选中的角度模式
    angle_initialize();

    // 主窗口捕获所有键盘事件
    this->setFocusPolicy(Qt::StrongFocus);

    // 延迟执行 setAidQSS 函数
    QTimer::singleShot(0, this, &MainWindow::setAidQSS);
    // 初始化光标控制计时器
    cursorTimerInit();

    // 初始化完成发射信号
    // emit initFinished();
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
    // 关闭打开了的 About 窗口
    if (this->aboutPage) {
        this->aboutPage->close();
    }
    // 关闭打开了的 Help 窗口
    if (this->helpPage) {
        this->helpPage->close();
    }
    QMainWindow::closeEvent(event);
}

void MainWindow::move_to_center(QWidget* widget) {
    // 获取屏幕的可用几何区域
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();

    // 获取窗口的大小
    QSize windowSize = widget->size();

    // 计算窗口移动到中央的位置
    int x = (screenGeometry.width() - windowSize.width()) / 2;
    int y = (screenGeometry.height() - windowSize.height()) / 2;

    // 移动窗口到新的位置
    widget->move(x, y);
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
    // 除了自检按钮外都绑定清空浏览状态的槽函数
    for (auto i = 1; i < this->buttons.size(); i++) {
        connect(this->buttons[i],
                &QPushButton::clicked,
                this,
                &MainWindow::resetViewState);
    }
    // 分类装载
    // 数字/小数点/Answer
    this->normal_buts.append(this->ui->pushButton_6);
    this->normal_buts.append(this->ui->pushButton_7);
    this->normal_buts.append(this->ui->pushButton_8);
    this->normal_buts.append(this->ui->pushButton_12);
    this->normal_buts.append(this->ui->pushButton_13);
    this->normal_buts.append(this->ui->pushButton_14);
    this->normal_buts.append(this->ui->pushButton_18);
    this->normal_buts.append(this->ui->pushButton_19);
    this->normal_buts.append(this->ui->pushButton_20);
    this->normal_buts.append(this->ui->pushButton_24);
    this->normal_buts.append(this->ui->pushButton_25);
    this->normal_buts.append(this->ui->pushButton_26);
    // 第一列按钮
    this->col1_buts.append(this->ui->pushButton_9);
    this->col1_buts.append(this->ui->pushButton_15);
    this->col1_buts.append(this->ui->pushButton_21);
    // 第二列按钮
    this->col2_buts.append(this->ui->pushButton_10);
    this->col2_buts.append(this->ui->pushButton_16);
    this->col2_buts.append(this->ui->pushButton_22);
    // 第三列按钮
    this->col3_buts.append(this->ui->pushButton_11);
    this->col3_buts.append(this->ui->pushButton_17);
    this->col3_buts.append(this->ui->pushButton_23);
    // 括号按钮
    this->bracket_buts.append(this->ui->pushButton_2);
    this->bracket_buts.append(this->ui->pushButton_3);
    // 退格和清除按钮
    this->clear_buts.append(this->ui->pushButton_4);
    this->clear_buts.append(this->ui->pushButton_5);
    // 特殊数字按钮
    this->special_buts.append(this->ui->pushButton_27);
    this->special_buts.append(this->ui->pushButton_28);
    // 函数按钮
    this->function_buts.append(this->ui->pushButton_30);
    this->function_buts.append(this->ui->pushButton_31);
    this->function_buts.append(this->ui->pushButton_32);
    this->function_buts.append(this->ui->pushButton_33);
    this->function_buts.append(this->ui->pushButton_34);
    this->function_buts.append(this->ui->pushButton_35);
    this->function_buts.append(this->ui->pushButton_36);
    this->function_buts.append(this->ui->pushButton_37);
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
    // 所有预设方案的样式设置槽函数
    for (auto action : this->ui->menuStyle->actions()) {
        // 加入方案组
        styleActionGroup->addAction(action);
    }
    styleActionGroup->setExclusive(true);
    // 连接所有 QAction 的 triggered 信号到同一个槽函数
    connect(styleActionGroup,
            &QActionGroup::triggered,
            this,
            &MainWindow::style_set);
    /* 历史记录相关槽函数 */
    connect(this->ui->actionAll_History,
            &QAction::triggered,
            this,
            &MainWindow::all_history_display);
    connect(this->ui->actionCurrent_History,
            &QAction::triggered,
            this,
            &MainWindow::cur_history_display);
    /* About 页面打开 */
    connect(this->ui->actionAbout,
            &QAction::triggered,
            this,
            &MainWindow::about_display);
    /* Help 页面打开 */
    connect(this->ui->actionHelp,
            &QAction::triggered,
            this,
            &MainWindow::help_display);
    /* 点击联系我们 */
    connect(this->ui->actionContact_us,
            &QAction::triggered,
            this,
            &MainWindow::contactUs);
    /* 角度设置 */
    // 所有角度设置槽函数
    for (auto action : this->ui->menuAngle_Mode->actions()) {
        // 加入方案组
        angleActionGroup->addAction(action);
    }
    angleActionGroup->setExclusive(true);
    // 连接所有 QAction 的 triggered 信号到同一个槽函数
    connect(angleActionGroup,
            &QActionGroup::triggered,
            this,
            &MainWindow::angle_set);

    /* Logo 点击 */
    connect(this->logoFilter,
            &ClickableLabelFilter::labelClicked,
            this,
            &MainWindow::logoClicked);
}

// 输入算式显示
void MainWindow::formula_display()
{
    this->ui->label->setText(this->formula_text);
    // 刷新光标显示
    cursorDisplay = true;
    updateLabel();
}

// 结果显示
void MainWindow::result_display()
{
    this->ui->label_2->setText(QString("%1").arg(this->result));
    // 将光标归于表达式的末尾
    currentCursor.first = this->formula_text.size();
    currentCursor.second = this->formula_cal_text.size();
}

// 数字键响应槽函数
void MainWindow::num0_clicked()
{
    this->insertInput("0", "0");
}
void MainWindow::num1_clicked()
{
    this->insertInput("1", "1");
}
void MainWindow::num2_clicked()
{
    this->insertInput("2", "2");
}
void MainWindow::num3_clicked()
{
    this->insertInput("3", "3");
}
void MainWindow::num4_clicked()
{
    this->insertInput("4", "4");
}
void MainWindow::num5_clicked()
{
    this->insertInput("5", "5");
}
void MainWindow::num6_clicked()
{
    this->insertInput("6", "6");
}
void MainWindow::num7_clicked()
{
    this->insertInput("7", "7");
}
void MainWindow::num8_clicked()
{
    this->insertInput("8", "8");
}
void MainWindow::num9_clicked()
{
    this->insertInput("9", "9");
}

// 单独输入符号 补result
void MainWindow::single_symbol_fix()
{
    // 若当前输入为空但直接按下符号键 则默认在其前面补一个result
    if (this->formula_text == "") {
        ans_clicked();
    }
}

// 小数点按键响应槽函数
void MainWindow::dot_clicked()
{
    single_symbol_fix();
    this->insertInput(".", ".");
}

// 括号按键响应槽函数
void MainWindow::left_bracket_clicked()
{
    this->insertInput("(", "(");
}
void MainWindow::right_bracket_clicked()
{
    this->insertInput(")", ")");
}

// 退格按键响应槽函数
void MainWindow::back_clicked()
{
    // 当前无内容时啥也不干
    if (this->formula_text.size() == 0) {
        return;
    }

    // 获取 formula_cal_text 的当前字符
    QChar currentCalChar = formula_cal_text[currentCursor.second-1];
    QString newFormula = "";
    QString newCalFormula = "";

    // 特殊处理函数自带的左括号
    if (currentCalChar == '(' && currentCursor.second >= 2 && isFunctionSymbol(formula_cal_text[currentCursor.second-2])) {
        QChar functionChar = formula_cal_text[currentCursor.second-2];
        // 此时需要把函数和左括号一块删咯 然后更新光标位置
        // 如果被删部分前面还有内容就加上
        if (currentCursor.second > 2) {
            newFormula += formula_text.mid(0, currentCursor.first-symbol_map[functionChar].size()-1);
            newCalFormula += formula_cal_text.mid(0, currentCursor.second-2);
        }
        // 如果被删部分后面还有内容也加上
        if (currentCursor.second < formula_cal_text.size()) {
            newFormula += formula_text.mid(currentCursor.first, formula_text.size()-currentCursor.first);
            newCalFormula += formula_cal_text.mid(currentCursor.second, formula_cal_text.size()-currentCursor.second);
        }
        // 更新光标位置
        currentCursor.first = currentCursor.first-symbol_map[functionChar].size()-1;
        currentCursor.second -= 2;
    }
    // 否则正常处理
    else {
        // 如果被删部分前面还有内容就加上
        if (currentCursor.second >= 2) {
            newFormula += formula_text.mid(0, currentCursor.first-symbol_map[currentCalChar].size());
            newCalFormula += formula_cal_text.mid(0, currentCursor.second-1);
        }
        // 如果被删部分后面还有内容也加上
        if (currentCursor.second < formula_cal_text.size()) {
            newFormula += formula_text.mid(currentCursor.first, formula_text.size()-currentCursor.first);
            newCalFormula += formula_cal_text.mid(currentCursor.second, formula_cal_text.size()-currentCursor.second);
        }
        // 更新光标位置
        currentCursor.first -= symbol_map[currentCalChar].size();
        currentCursor.second -= 1;
    }

    // 更新到两个显示字符串
    this->formula_text = newFormula;
    this->formula_cal_text = newCalFormula;

    // 如果此时显示串不为空 但是光标位置归于(0, 0) 则还原回显示串的开头
    if (currentCursor.second == 0 && this->formula_text.size() != 0) {
        currentCursor.first = 1;
        currentCursor.second = 1;
    }

    // 如果更新后的光标位置在一个函数上那么则特殊处理一下
    if (currentCursor.second > 0 && isFunctionSymbol(this->formula_cal_text[currentCursor.second-1])) {
        currentCursor.first += symbol_map[this->formula_cal_text[currentCursor.second-1]].size();
        currentCursor.second += 1;
    }

    // 更新显示
    formula_display();
}

// 清空按键响应槽函数
void MainWindow::clear_clicked()
{
    this->formula_text = "";
    this->formula_cal_text = "";
    // 还原查找状态
    resetViewState();
    // 还原光标
    currentCursor = {0, 0};
    // 刷新输入框显示
    formula_display();
}

// 特殊数字按键响应槽函数
void MainWindow::pi_clicked()
{
    this->insertInput("π", "P");
}
void MainWindow::e_clicked()
{
    this->insertInput("e", "E");
}

// 函数运算符
void MainWindow::sin_clicked()
{
    this->insertInput("sin(", "S(");
}

void MainWindow::asin_clicked()
{
    this->insertInput("arcsin(", "s(");
}

void MainWindow::cos_clicked()
{
    this->insertInput("cos(", "C(");
}

void MainWindow::acos_clicked()
{
    this->insertInput("arccos(", "c(");
}

void MainWindow::tan_clicked()
{
    this->insertInput("tan(", "T(");
}

void MainWindow::atan_clicked()
{
    this->insertInput("arctan(", "t(");
}

void MainWindow::ln_clicked()
{
    this->insertInput("ln(", "L(");
}

void MainWindow::log_clicked()
{
    this->insertInput("log(", "l(");
}

// 运算符按键响应槽函数
void MainWindow::add_clicked()
{
    this->insertInput("+", "+");
}
void MainWindow::minus_clicked()
{
    this->insertInput("-", "-");
}
void MainWindow::multi_clicked()
{
    single_symbol_fix();
    this->insertInput("×", "*");
}
void MainWindow::divid_clicked()
{
    single_symbol_fix();
    this->insertInput("÷", "/");
}
void MainWindow::percent_clicked()
{
    single_symbol_fix();
    this->insertInput("%", "%");
}
void MainWindow::mod_clicked()
{
    single_symbol_fix();
    this->insertInput(" MOD ", "M");
}
void MainWindow::pow_clicked()
{
    single_symbol_fix();
    this->insertInput("^(", "^(");
}
void MainWindow::prod_clicked()
{
    single_symbol_fix();
    this->insertInput("!", "!");
}
void MainWindow::pprod_clicked()
{
    single_symbol_fix();
    this->insertInput("!!", "@");
}
// 等于号按键响应槽函数
void MainWindow::equal_clicked()
{
    // 先检验计算式的小数点和尾字符是否合法
    if (!checkDots(this->formula_cal_text)) {
        QMessageBox::critical(this, "表达式输入错误",
                              "存在不合法的小数点，请仔细检查您的输入！");
        return;
    }
    if (!checkTail(this->formula_cal_text)) {
        QMessageBox::critical(this, "表达式输入错误",
                              "末尾输入了不可孤立存在的操作符，请仔细检查您的输入！");
        return;
    }

    // 重置数字列表
    num_vec = {};

    // 解析算式并显示计算结果
    string processed_formula = num_extract(this->formula_cal_text.toStdString(),
                                           num_vec);

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
                                      num_vec,
                                      this->rad));
        // 如果result是 inf 或 -inf
        if (_finite(result) == 0) {
            QMessageBox::critical(this, "超出计算范围",
                                  "您要计算的数据太大啦！我无能为力！");
            return;
        }
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
                                  "空表达式无法运算！");
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
    // 将结果解析为 QString
    QString qres = QString("%1").arg(this->result);

    // 处理科学计数法
    int e_ind = qres.indexOf('e');
    if (e_ind != -1) {
        qres = qres.mid(0, e_ind) + "*10^(" + qres.mid(e_ind+1, qres.size()-e_ind-1) +")";
    }

    // 将结果模拟按键输入到计算器中
    for (auto i = 0; i < qres.size(); i++) {
        QChar c = qres[i];
        if (c == '+') {
            add_clicked();
        }
        else if (c == '-') {
            minus_clicked();
        }
        else if (c == '*') {
            multi_clicked();
        }
        else if (c == '/') {
            divid_clicked();
        }
        else if (c == '^') {
            this->pow_clicked();
            // 右移一位忽略左括号
            i += 1;
        }
        else if (c == '0') {
            num0_clicked();
        }
        else if (c == '1') {
            num1_clicked();
        }
        else if (c == '2') {
            num2_clicked();
        }
        else if (c == '3') {
            num3_clicked();
        }
        else if (c == '4') {
            num4_clicked();
        }
        else if (c == '5') {
            num5_clicked();
        }
        else if (c == '6') {
            num6_clicked();
        }
        else if (c == '7') {
            num7_clicked();
        }
        else if (c == '8') {
            num8_clicked();
        }
        else if (c == '9') {
            num9_clicked();
        }
        else if (c == '.') {
            dot_clicked();
        }
        else if (c == ')') {
            this->right_bracket_clicked();
        }
    }

    // 刷新显示
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

// 通过方案名称直接从 style 中读取 QSS 方案
void MainWindow::style_set(QAction* action) {
    QString current_style = action->objectName();
    // 获取方案名称
    current_style = current_style.mid(6);
    // 方案名称不存在 style.h 中则报错
    if (!styleMap.contains(current_style)) {
        QMessageBox::critical(this, "配色方案未找到",
                              "请检查您的配色方案是否正确写入style.h或您的action是否正确设置了对象名称！");
        return;
    }
    // 设置对应的颜色
    this->style_diy_set(styleMap[current_style]);
    change_ini_style(current_style);
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

/* 打开 About 页面 */
void MainWindow::about_display() {
    // 防止重复打开
    if (this->aboutPage != NULL) {
        this->aboutPage->close();
    }
    // 构造窗口
    if (liteVersion) {
        this->aboutPage = new AboutPageLite(nullptr, "about_Lite.html");
    }
    else {
        this->aboutPage = new AboutPageLite(nullptr, "about_Lite.html");
    }
    this->aboutPage->setWindowTitle("About CCalculator v"+this->current_version);
    // 移动到屏幕中间
    move_to_center(this->aboutPage);
    // 显示
    this->aboutPage->show();
}

/* 打开 Help 页面 */
void MainWindow::help_display() {
    // 防止重复打开
    if (this->helpPage != NULL) {
        this->helpPage->close();
    }
    // 构造窗口
    this->helpPage = new HelpDialog();
    // 移动到屏幕中间
    move_to_center(this->helpPage);
    // 显示
    this->helpPage->show();
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
    QString table_create = "CREATE TABLE IF NOT EXISTS Histories (";

    for(auto i = 0; i < this->dataBaseCols.size(); i++) {
        QPair<QString, QString> col = this->dataBaseCols.at(i);
        table_create += col.first + " " + col.second + ",";
    }
    table_create = table_create.mid(0, table_create.size()-1);

    table_create += ");";
    QSqlQuery table_query;
    table_query.exec(table_create);
}

// 关闭数据库
void MainWindow::Close_DB(){
    db.close();
}

// 查询所有数据
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
        for(auto i = 0; i < this->dataBaseCols.size(); i++) {
            QPair<QString, QString> col = this->dataBaseCols.at(i);
            tmp.append(sql_query.value(col.first).toString());
        }
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
        for(auto i = 0; i < this->dataBaseCols.size(); i++) {
            QPair<QString, QString> col = this->dataBaseCols.at(i);
            tmp.append(sql_query.value(col.first).toString());
        }
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
    QString querystring = "INSERT INTO Histories (";
    for(auto i = 0; i < this->dataBaseCols.size(); i++) {
        QPair<QString, QString> col = this->dataBaseCols.at(i);
        querystring += col.first + ",";
    }
    querystring = querystring.mid(0, querystring.size()-1);
    querystring += ") VALUES (";
    for(auto i = 0; i < this->dataBaseCols.size(); i++) {
        QPair<QString, QString> col = this->dataBaseCols.at(i);
        querystring += ":" + col.first + ",";
    }
    querystring = querystring.mid(0, querystring.size()-1);
    querystring += ")";

    // 准备好插值语句
    query.prepare(querystring);

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

// 键盘事件响应
void MainWindow::keyPressEvent(QKeyEvent *event) {
    // 检查是否按下 Ctrl+V
    if (event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_V) {
        // 获取剪贴板内容
        QClipboard *clipboard = QApplication::clipboard();
        QString clipboardText = clipboard->text();

        // 处理剪贴板内容 --- 处理前赋值给 formula_text
        this->formula_text = clipboardText;
        // 处理后给 formula_cal_text
        // 用符号反向映射表替换剪贴板内容中的子串
        for (auto it = sysmbol_rmap.begin(); it != sysmbol_rmap.end(); ++it) {
            clipboardText.replace(it.key(), it.value());
        }
        this->formula_cal_text = clipboardText;

        // 更新光标到最尾
        currentCursor.first = formula_text.size();
        currentCursor.second = formula_cal_text.size();

        // 更新公式展示框
        this->formula_display();

        return;
    }

    // 检查是否按下 Ctrl+W 关闭窗口
    else if (event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_W) {
        this->close();
    }

    // 检查是否输入上下按键
    else if (event->key() == Qt::Key_Up) {
        // 看看上面有没有公式
        QVector<QVector<QString>> data = this->QuerySpecificData("timestamp",
                                                                 this->open_time,
                                                                 ">=");
        if (data.empty() || previousFormulaID == data.size()) {
            return;
        }
        auto dataSize = data.size();
        // 当前非空公式直接入向下浏览栈
        if (this->formula_text != "") {
            downView.push(this->formula_text);
        }
        // 调出上一条
        this->formula_text = data[dataSize-previousFormulaID-1][0];
        QString tmp = this->formula_text;
        for (auto it = sysmbol_rmap.begin(); it != sysmbol_rmap.end(); ++it) {
            tmp.replace(it.key(), it.value());
        }
        this->formula_cal_text = tmp;
        // 刷新右侧浏览记录辅助框
        this->aidViewLabel->setText(QString::number(++previousFormulaID)+"/"+\
                                    QString::number(dataSize));
        // 更新光标到最尾
        currentCursor.first = formula_text.size();
        currentCursor.second = formula_cal_text.size();
        // 刷新显示框
        this->formula_display();
    }
    else if (event->key() == Qt::Key_Down) {
        // 看看下面有没有公式
        if (downView.empty()) {
            return;
        }
        QVector<QVector<QString>> data = this->QuerySpecificData("timestamp",
                                                                 this->open_time,
                                                                 ">=");
        // 调出下一条
        this->formula_text = downView.top();
        QString tmp = this->formula_text;
        for (auto it = sysmbol_rmap.begin(); it != sysmbol_rmap.end(); ++it) {
            tmp.replace(it.key(), it.value());
        }
        this->formula_cal_text = tmp;
        // 刷新右侧浏览记录辅助框
        if (previousFormulaID > 1) {
            this->aidViewLabel->setText(QString::number(previousFormulaID-1)+"/"+\
                                        QString::number(data.size()));
        }
        else {
            this->aidViewLabel->setText("");
        }
        previousFormulaID -= 1;
        // 弹掉栈顶
        downView.pop();
        // 更新光标到最尾
        currentCursor.first = formula_text.size();
        currentCursor.second = formula_cal_text.size();
        // 刷新显示框
        this->formula_display();
    }

    // 左右按钮调整光标位置
    else if (event->key() == Qt::Key_Left) {
        QChar currentChar = formula_cal_text[currentCursor.second-1];
        // 左边没位置了不响应
        if (currentCursor.second < 2) {
            return;
        }
        // 特殊处理左括号
        else if (currentChar=='(') {
            // 判断前面那个字符是不是某个函数
            QChar previousChar = formula_cal_text[currentCursor.second-2];
            if (isFunctionSymbol(previousChar)) {
                // 是的话则需要跳过他到下一个左边的字符
                // 首先判断计算式左边的左边是否还有冗余 没有就不能动了
                if (currentCursor.second-3 > 0) {
                    // 直接将计算式位置移到左边的左边
                    currentCursor.second -= 2;
                    // 接着将显示式的光标位置先左移一格再左移该函数的长度
                    currentCursor.first -= 1;
                    currentCursor.first -= symbol_map[previousChar].size();
                }
            }
            else {
                // 不是的话正常处理即可
                // 直接将计算式位置移到左边
                currentCursor.second -= 1;
                // 接着将显示式的光标位置左移一格
                currentCursor.first -= 1;
            }
        }
        // 非左括号直接处理
        else {
            // 直接将计算式位置移到左边
            currentCursor.second -= 1;
            // 接着将显示式的光标位置左移对应长度
            currentCursor.first -= symbol_map[currentChar].size();
        }
        // 刷新光标显示
        cursorDisplay = true;
        updateLabel();
    }
    else if (event->key() == Qt::Key_Right) {
        QChar currentChar = formula_cal_text[currentCursor.second-1];
        // 右边没位置了不响应
        if (currentCursor.second == formula_cal_text.size()) {}
        // 特殊处理右边是函数的情况
        else if (isFunctionSymbol(formula_cal_text[currentCursor.second])) {
            // 将显示式的光标位置右先右移对应长度再右移一位
            currentCursor.first += symbol_map[formula_cal_text[currentCursor.second]].size()+1;
            // 直接将计算式位置移到右边的右边
            currentCursor.second += 2;
            // 如果此时恰好移到了一个函数字符则还需要右移一位
            if (isFunctionSymbol(formula_cal_text[currentCursor.second-1])) {
                // 计算式和显示式都右移一位
                currentCursor.second += 1;
                currentCursor.first += 1;
            }
        }
        // 非函数直接处理
        else {
            // 直接将计算式位置移到右边
            currentCursor.second += 1;
            // 接着将显示式的光标位置右移对应长度
            currentCursor.first += symbol_map[currentChar].size();
        }
        // 刷新光标显示
        cursorDisplay = true;
        updateLabel();
    }

    // 调用基类的事件处理函数
    QWidget::keyPressEvent(event);
}

// 通过传入的字符串数组批量设置各组控件的样式
void MainWindow::style_diy_set(QVector<QString> styles) {
    // 窗口背景颜色设置
    this->setStyleSheet(styles[0]);
    // 数字/小数点/Answer 按钮组
    for (auto but:normal_buts) {
        updateStyleSheet(but, styles[1]);
    }
    // 第一列运算符 按钮组
    for (auto but:col1_buts) {
        updateStyleSheet(but, styles[2]);
    }
    // 第二列运算符 按钮组
    for (auto but:col2_buts) {
        updateStyleSheet(but, styles[3]);
    }
    // 第三列运算符 按钮组
    for (auto but:col3_buts) {
        updateStyleSheet(but, styles[4]);
    }
    // 括号 按钮组
    for (auto but:bracket_buts) {
        updateStyleSheet(but, styles[5]);
    }
    // 退格和清空 按钮组
    for (auto but:clear_buts) {
        updateStyleSheet(but, styles[6]);
    }
    // 特殊数字 按钮组
    for (auto but:special_buts) {
        updateStyleSheet(but, styles[7]);
    }
    // 函数 按钮组
    for (auto but:function_buts) {
        updateStyleSheet(but, styles[8]);
    }
    // 错误自检按钮
    updateStyleSheet(this->ui->pushButton, styles[9]);
    // 等于按钮
    updateStyleSheet(this->ui->pushButton_29, styles[10]);
    // 算式输入框
    updateStyleSheet(this->ui->label, styles[11]);
    // 结果展示框
    updateStyleSheet(this->ui->label_2, styles[12]);
    // 更新辅助文本颜色
    setAidQSS();
}

/* 初始化设置相关函数 */

// 检查初始化配置文件
void MainWindow::ini_check() {
    QFileInfo int_file(this->iniFile);
    // 不存在就新建一个默认的ini文件
    if (!int_file.isFile()) {
        change_ini_style("Light");
    }
}

QString MainWindow::getAidQSS() {
    // 辅助显示的 QSS
    // 字体颜色为当前字体颜色各通道-35
    QString fontColor = this->ui->label->palette().color(QPalette::WindowText).name();
    QVector<int> rgbColors = hex2rgb(fontColor);
    QString aidQSS = "QLabel {color: rgb(";
    aidQSS += QString::number(abs(rgbColors[0]-35))+", ";
    aidQSS += QString::number(abs(rgbColors[1]-35))+", ";
    aidQSS += QString::number(abs(rgbColors[2]-35))+");";
    aidQSS += R"(font: 700 8pt;
border: none;})";
    return aidQSS;
}

void MainWindow::setAidQSS() {
    QString aidQSS = getAidQSS();
    this->aidRadLabel->setStyleSheet(aidQSS);
    this->aidViewLabel->setStyleSheet(aidQSS);
}

// 初始化输入框上的辅助标签
void MainWindow::aidInit() {
    // 将辅助标签和水平弹簧加入水平布局并调整尺度
    aidHLayout = new QHBoxLayout();
    aidRadLabel = new QLabel(this);
    aidRadLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    aidRadLabel->setContentsMargins(0, 0, 0, 0);
    aidViewLabel = new QLabel(this);
    aidViewLabel->setAlignment(Qt::AlignTop | Qt::AlignRight);
    aidViewLabel->setContentsMargins(0, 0, 0, 0);
    setAidQSS();
    hspacer = new QSpacerItem(20, 10, QSizePolicy::Expanding, QSizePolicy::Expanding);
    aidHLayout->addWidget(aidRadLabel);
    aidHLayout->addSpacerItem(hspacer);
    aidHLayout->addWidget(aidViewLabel);
    aidHLayout->setStretch(0, 5);
    aidHLayout->setStretch(1, 30);
    aidHLayout->setStretch(2, 5);

    // 定义一个垂直布局并向其中添加水平布局和垂直弹簧
    aidVLayout = new QVBoxLayout(this->ui->label);
    vspacer = new QSpacerItem(20, 60, QSizePolicy::Expanding, QSizePolicy::Expanding);
    aidVLayout->addLayout(aidHLayout);
    aidVLayout->addSpacerItem(vspacer);
    aidVLayout->setStretch(0, 1);
    aidVLayout->setStretch(1, 10);

    // 绑定给输入框
    this->ui->label->setLayout(aidVLayout);
}

// 修改当前初始化文件的配色方案值
void MainWindow::change_ini_style(QString style) {
    // 打开文件并指定为ini格式
    QSettings*  m_IniFile = new QSettings(this->iniFile, QSettings::IniFormat);
    //通过setValue函数将键值对放在相对于的节下面
    m_IniFile->setValue( "PreSettings/style",  style);
    delete m_IniFile;
}

// 初始化设置上一次设置的颜色方案
void MainWindow::style_initialize() {
    // 打开文件并指定为ini格式
    QSettings*  m_IniFile = new QSettings(this->iniFile, QSettings::IniFormat);
    // 通过Value函数将节下相对应的键值读取出来
    QString pre_style = "Light";

    try {
        pre_style = m_IniFile->value("PreSettings/style").toString();
    }
    catch(const char* msg) {
        qDebug() << msg;
        change_ini_style("Light");
    }

    this->style_diy_set(styleMap[pre_style]);

    // 同时调整当前 checked 的颜色方案
    for (auto action:this->styleActionGroup->actions()) {
        if (action->objectName() == "action"+pre_style) {
            action->setChecked(true);
            break;
        }
    }
}

// 初始化设置上一次设置的角度模式
void MainWindow::angle_initialize() {
    // 打开文件并指定为ini格式
    QSettings*  m_IniFile = new QSettings(this->iniFile, QSettings::IniFormat);
    // 通过Value函数将节下相对应的键值读取出来
    QString pre_angle = "RAD";

    try {
        pre_angle = m_IniFile->value("PreSettings/angle").toString();
    }
    catch(const char* msg) {
        qDebug() << msg;
    }

    if (pre_angle == "RAD") {
        this->ui->actionRad->setChecked(true);
        this->aidRadLabel->setText("RAD");
    }
    else {
        this->ui->actionDeg->setChecked(true);
        this->aidRadLabel->setText("DEG");
    }
}

// 角度模式设置
void MainWindow::angle_set(QAction* action) {
    QString current_mode = action->objectName();
    // 打开文件并指定为ini格式
    QSettings*  m_IniFile = new QSettings(this->iniFile, QSettings::IniFormat);

    // 获取第七个字符
    if (current_mode[6] == 'R') {
        this->rad = true;
        this->aidRadLabel->setText("RAD");
        //通过setValue函数将键值对放在相对于的节下面
        m_IniFile->setValue( "PreSettings/angle",  "RAD");
    }
    else {
        this->rad = false;
        this->aidRadLabel->setText("DEG");
        //通过setValue函数将键值对放在相对于的节下面
        m_IniFile->setValue( "PreSettings/angle",  "DEG");
    }
    delete m_IniFile;
}

/* 上下翻找输入记录 */
// 还原查找状态
void MainWindow::resetViewState() {
    // 还原浏览栈与前向浏览ID
    previousFormulaID = 0;
    downView.clear();
    // 还原辅助显示框
    this->aidViewLabel->setText("");
}

/* 生成随机数 */
int MainWindow::randomIntGenerate(int minimum, int maximum) {
    // 初始化随机数生成器
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minimum, maximum);
    return dis(gen);
}

// 点击 Logo 标签生成随机数填充入算式
void MainWindow::logoClicked() {
    // 生成位数 4-6 位
    int bits = randomIntGenerate(4, 6);
    // 输入零和小数点
    num0_clicked();
    dot_clicked();
    // 接着按位数输入随机数
    for (auto i = 0; i < bits; i++) {
        int num = randomIntGenerate(0, 9);
        switch (num) {
        case 0:
            num0_clicked();
            break;
        case 1:
            num1_clicked();
            break;
        case 2:
            num2_clicked();
            break;
        case 3:
            num3_clicked();
            break;
        case 4:
            num4_clicked();
            break;
        case 5:
            num5_clicked();
            break;
        case 6:
            num6_clicked();
            break;
        case 7:
            num7_clicked();
            break;
        case 8:
            num8_clicked();
            break;
        case 9:
            num9_clicked();
            break;
        default:
            break;
        }
    }
}

/* 输入光标控制变化函数 */
void MainWindow::updateLabel() {
    QString formulaText = this->formula_text;
    if (formulaText != "" && cursorDisplay) {
        int cursorLength = symbol_map[this->formula_cal_text[currentCursor.second-1]].size();
        // 获取光标当前内容
        QString currentFocusText = formulaText.mid(currentCursor.first-1, cursorLength);
        // 如果是左括号并且前一个是函数字符则需要特殊处理
        if (currentFocusText == "(" && currentCursor.second > 1) {
            if (isFunctionSymbol(formula_cal_text[currentCursor.second-2])) {
                // 计算该函数的长度
                int functionLength = symbol_map[this->formula_cal_text[currentCursor.second-2]].size();
                currentFocusText = formulaText.mid(currentCursor.first-functionLength-1, functionLength+1);
                formulaText = formulaText.mid(0, currentCursor.first-functionLength-1) + "<u>" \
                              + currentFocusText + "</u>";
                // 看看函数后还有没有内容
                if (currentCursor.first+cursorLength < this->formula_text.size()) {
                    formulaText += this->formula_text.mid(currentCursor.first+cursorLength-1,
                                                          this->formula_text.size()-currentCursor.first-cursorLength+1);
                }
            }
        }
        // 其他情况正常按照对应长度显示即可
        else {
            formulaText = formulaText.mid(0, currentCursor.first-1) + "<u>" \
                          + currentFocusText + "</u>";
            if (currentCursor.first+cursorLength-1 < this->formula_text.size()) {
                formulaText += this->formula_text.mid(currentCursor.first+cursorLength-1,
                                                      this->formula_text.size()-currentCursor.first-cursorLength+1);
            }
        }
    }
    this->ui->label->setText(formulaText);
    cursorDisplay = !cursorDisplay;
}

/* 初始化光标计时器 */
void MainWindow::cursorTimerInit() {
    cursorTimer = new QTimer(this);
    connect(cursorTimer,
            &QTimer::timeout,
            this,
            &MainWindow::updateLabel);
    // 每0.5秒刷新一次输入光标
    cursorTimer->start(500);
}

// 在光标后插入输入的数据或符号
void MainWindow::insertInput(QString displayText, QString calculateText) {
    // 插入到光标之后
    formula_text.insert(currentCursor.first, displayText.toUtf8());
    formula_cal_text.insert(currentCursor.second, calculateText.toUtf8());

    // 更新光标位置
    currentCursor.first += displayText.size();
    currentCursor.second += calculateText.size();

    // 刷新显示框
    formula_display();
}

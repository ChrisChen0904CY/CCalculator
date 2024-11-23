#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// 软件版本号
#define CURRENT_VERSION "1.7.0"

#include <QApplication>
#include <QScreen>
#include <QMainWindow>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include <QStack>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QMap>
#include <QFont>
#include <QActionGroup>
#include <QDesktopServices>
#include <QTimer>
#include <QFileInfo>
#include <QElapsedTimer>

// SQL 数据库相关包的导入
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

// 响应键盘事件
#include <QKeyEvent>
#include <QClipboard>

// 初始配色方案设置
#include <QSettings>
#include <QFileInfo>

#include "historyview.h"
#include "clickablelabelfilter.h"

// 生成随机数
#include <random>

// 大数库
#include "cbignum.h"

// 设置页面
#include "settingpage.h"

// 结果展示页面
#include "resultview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, bool lite=true);
    ~MainWindow();
    // CBigNum&CBigMath测试函数
    void cbignum_test();
    // 窗口移动到屏幕中央
    void move_to_center(QWidget* widget);
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
    // 通过传入的字符串数组批量设置各组控件的样式
    void style_diy_set(QVector<QString> styles);
    /* 检查最新版本 */
    void version_check();
    /* 初始化光标计时器 */
    void cursorTimerInit();

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

    /* 初始化设置 */
    // 检查初始化配置文件
    void ini_check();
    // 初始化输入框上的辅助标签
    void aidInit();
    // 初始化设置上一次设置的颜色方案
    void style_initialize();
    // 初始化设置上一次设置的角度模式
    void angle_initialize();

    /* 样式设置 */
    // 通过方案名称直接从 style 中读取 QSS 方案
    void style_set(QAction* action);
    // 修改当前初始化文件的配色方案值
    void change_ini_style(QString style);

    /* 历史记录查看 */
    void all_history_display();
    void cur_history_display();

    /* 打开 About 页面 */
    void about_display();

    /* 打开 Help 页面 */
    void help_display();

    /* 联系我们 */
    void contactUs() {
        QUrl mailtoUrl = QUrl("mailto:chrischanyedu@gmail.com");
        QDesktopServices::openUrl(mailtoUrl);
    }

    /* 角度模式设置 */
    void angle_set(QAction* action);

    /* 获取辅助显示文本的QSS */
    QString getAidQSS();
    void setAidQSS();

    /* 上下翻找输入记录 */
    // 还原查找状态
    void resetViewState();

    /* 随机数生成 */
    int randomIntGenerate(int minimum, int maximum);
    // 点击 Logo 标签生成随机数填充入算式
    void logoClicked();

    /* 输入光标控制变化函数 */
    void updateLabel();
    // 在光标后插入输入的数据或符号
    void insertInput(QString displayText, QString calculateText);

    /* 长结果查看 */
    // 初始化结果辅助查看按钮
    void resAidInit();
    // 初始化两个辅助按钮的QSS
    void setResAidQSS();
    // 隐藏两个辅助按钮
    void hideResButtons();
    // 显示两个辅助按钮
    void showResButtons();
    // 复制完整结果
    void copy2Clipboard();
    // 展示完整结果
    void resultview_display();

    /* 设置页面相关函数 */
    void setting_display();
    // 默认系统参数设置
    void defaultSysParaSet();
    // 初始化系统参数
    void sysParameterInit();
    // 应用系统参数
    void sysParameterApply(QMap<QString, QString> sysParam);
    // 单独更新一个系统参数
    void sysParameterUpdate(QPair<QString, QString> param);

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

signals:
    void initFinished();

private:
    Ui::MainWindow *ui;
    // 当前输入的算式文本
    QString formula_text = "";
    // 将显示文本转成易解析的文本
    QString formula_cal_text = "";
    // 计算结果
    CBigNum result = 0.0;
    // 从文本提取出的数字
    vector<CBigNum> num_vec = {};
    // 结果文本
    QString result_text = "";
    // 结果完全展示按钮以及复制按钮
    QPushButton* completeShowButton = NULL;
    QPushButton* copyButton = NULL;
    // 输出框上的辅助按钮布局
    QVBoxLayout* resVLayout = NULL;
    QHBoxLayout* resHLayout = NULL;
    // 两个弹簧用以调整位置
    QSpacerItem* resVspacer = NULL;
    QSpacerItem* resHspacer = NULL;
    // 结果完全展示页面
    ResultView* resultView = NULL;
    // 解析字符对应的显示字符串
    QMap<QChar, QString> symbol_map = {{'0', "0"},
                                        {'1', "1"},
                                        {'2', "2"},
                                        {'3', "3"},
                                        {'4', "4"},
                                        {'5', "5"},
                                        {'6', "6"},
                                        {'7', "7"},
                                        {'8', "8"},
                                        {'9', "9"},
                                        {'.', "."},
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
    // 当前软件版本
    QString current_version = CURRENT_VERSION;


    /* 以下是用于 UI 色板方案批量设置的控件分类容器 */
    // 数字/小数点/上一次运算结果 按钮组
    QVector<QPushButton*> normal_buts;
    // 第一列计算按钮 --- +, -, ^
    QVector<QPushButton*> col1_buts;
    // 第二列计算按钮 --- ×, ÷, !
    QVector<QPushButton*> col2_buts;
    // 第三列计算按钮 --- %, MOD, !!
    QVector<QPushButton*> col3_buts;
    // 括号按钮
    QVector<QPushButton*> bracket_buts;
    // 退格/清除按钮
    QVector<QPushButton*> clear_buts;
    // 特殊数字按钮
    QVector<QPushButton*> special_buts;
    // 函数按钮
    QVector<QPushButton*> function_buts;
    // 数据库列名与类型
    QVector<QPair<QString, QString>> dataBaseCols = {{"input_formula", "TEXT"},
                                                     {"cal_result", "TEXT"},
                                                     {"timestamp", "DATETIME"},};
    // 初始配置文件名称
    QString iniFile = "./iniConfig.ini";
    // 所有 Style 预设方案 Action 所在组
    QActionGroup* styleActionGroup = new QActionGroup(this);
    // 角度设置方案组
    QActionGroup* angleActionGroup = new QActionGroup(this);
    // About 页面
    QWidget* aboutPage = NULL;
    // Help 页面
    QWidget* helpPage = NULL;
    // 是否为 Lite 版本
    bool liteVersion = false;
    // 是否为弧度制
    bool rad = true;

    // 输入框上的辅助显示
    QVBoxLayout* aidVLayout = NULL;
    QHBoxLayout* aidHLayout = NULL;
    // 度数模式辅助显示以及算式浏览辅助条数显示
    QLabel* aidRadLabel = NULL;
    QLabel* aidViewLabel = NULL;
    // 两个弹簧用来调整位置
    QSpacerItem* vspacer = NULL;
    QSpacerItem* hspacer = NULL;

    /* 上下按钮浏览算式 */
    // 向下浏览栈
    QStack<QString> downView;
    // 上一个输入算式的 ID
    int previousFormulaID = 0;

    /* Logo标签点击事件捕获过滤器 */
    ClickableLabelFilter* logoFilter = NULL;
    // 随机数生成器
    // 创建随机数生成器
    std::random_device rd;  // 获取随机数种子

    // 当前光标所处的位置和计算式中的位置
    QPair<int, int> currentCursor = {0, 0};
    // 光标控制计时器
    QTimer* cursorTimer = NULL;
    // 光标状态
    bool cursorDisplay = false;

    /* 设置页面 */
    SettingPage* settingPage = NULL;
    // 系统参数
    QString sysParameterFile = "./sysParameters.ini";
    // 默认系统参数
    QMap<QString, QString> defaultSysParameters = {{"precision", "8"},
                                                   {"resDisplayMode", "SCI"},
                                                   {"copyAll", "1"},
                                                   {"suffixZero", "0"},
                                                   {"ePower", "1"},
                                                   {"PI", "3.14159265358979324"},
                                                   {"fd", "1"}};
    QMap<QString, QString> sysParameters = {};
    // 缓存的圆周率
    CBigNum PI_Cached = defaultSysParameters["PI"].toStdString();
};

#endif // MAINWINDOW_H

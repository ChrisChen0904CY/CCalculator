#include "compute.h"
#include <cmath>
#include <algorithm>

#define M_PI 3.14159265358979323846
#define M_E  2.7182818284590452354

using namespace std;

bool is_num(char c)
{
    return ('0'<=c && c<='9');
}

double prod(double n) {
    if (n-int(n) != 0) {
        throw "非整数不可用于阶乘运算！";
    }
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return double(res);
}

double pprod(double n) {
    if (n-int(n) != 0) {
        throw "非整数不可用于阶乘运算！";
    }
    if (int(n)==0) {
        return 1.0;
    }
    int res = (((int(n))&1)==0) ? 2 : 1;
    for (int i = res+2; i <= n; i+=2) {
        res *= i;
    }
    return double(res);
}

double logx(double a, double b) {
    // 真数和底数的定义域检验
    if (a <= 0 || a == 1) {
        throw "对数运算错误！底数必须为不是1的非负数！";
    }
    // 真数检验
    if (b <= 0) {
        throw "对数运算中真数必须为非负数！";
    }
    // 通过检验直接计算
    return log(a)/log(b);
}

// ε --- 用于确定是否是 Pi 的整数倍
double epsilon = 1e-10;

double sinx(double x) {
    if (fabs(x - M_PI*int(x/M_PI)) <= epsilon) {
        return 0.0;
    }
    return sin(x);
}

double cosx(double x) {
    if (fabs((x - M_PI/2) - M_PI*int((x - M_PI/2)/M_PI)) <= epsilon) {
        return 0.0;
    }
    return sin(x);
}

double tanx(double x) {
    if (fabs(x - M_PI*int(x/M_PI)) <= epsilon) {
        return 0.0;
    }
    return tan(x);
}

string num_extract(string formula, vector<double>& vec)
{
    string tmp = "";
    string processed_formula = "";
    int id = 0;
    for (auto c:formula) {
        if (is_num(c) || c=='.') {
            tmp += c;
        }
        else {
            if (tmp.size() > 0 && tmp != "-") {
                vec.push_back(stod(tmp));
                processed_formula += to_string(id++);
                tmp = "";
            }
            processed_formula += c;
        }
    }
    // 尾处理
    if (tmp.size() > 0) {
        vec.push_back(stod(tmp));
        processed_formula += to_string(id++);
        tmp = "";
    }
    return processed_formula;
}

void vec_display(vector<double> vec)
{
    for (auto num:vec) {
        cout << num << endl;
    }
}

// 计算函数
double compute(string formula, vector<double> &num_vec, bool rad)
{
    // 空表达式
    if (formula.size() == 0) {
        throw "空表达式！";
    }
    // 单操作栈
    stack<double> nums;
    stack<char> ops;
    // 左括号位置栈
    stack<int> bracket_pos;
    // 数字存储下标串
    string tmp = "";
    // 计算结果
    double res = 0;

    // 扫描公式字符串并处理连续放置的数字
    // 连续数字长度
    int continus_nums_len = 0;
    for (int i = 0; i < formula.size(); i++) {
        // 若当前位置是右括号 则弹出栈顶左括号位置 进行截取计算入栈
        if (formula[i] == ')') {
            // 栈空报错
            if (bracket_pos.empty()) {
                throw "非法的括号表达式！";
            }
            // 括号内容为空报错
            if (i-bracket_pos.top() == 1) {
                throw "无内容的括号对是不被允许的！括号内必须有表达式！";
            }
            // 将连续数字相乘处理
            if (continus_nums_len > 1) {
                double prods = 1;
                while (continus_nums_len > 0) {
                    continus_nums_len--;
                    prods *= nums.top();
                    nums.pop();
                }
                nums.push(prods);
            }
            // 清空连续数字数
            continus_nums_len = 0;
            // 如果非最外层括号则弹掉一个左括号继续
            if (bracket_pos.size() != 1) {
                bracket_pos.pop();
                continue;
            }
            string sub_formula = formula.substr(bracket_pos.top()+1,
                                                i-bracket_pos.top()-1);

            // 将括号内内容计算入数字栈
            double cur_res = compute(sub_formula, num_vec, rad);
            // 判断是否需要进行函数操作
            if (bracket_pos.top() > 0) {
                // sin
                if (formula[bracket_pos.top()-1] == 'S') {
                    if (!rad) {
                        cur_res = cur_res/180*M_PI;
                    }
                    cur_res = sinx(cur_res);
                }
                // arcsin
                else if (formula[bracket_pos.top()-1] == 's') {
                    cur_res = asin(cur_res);
                }
                // cos
                else if (formula[bracket_pos.top()-1] == 'C') {
                    if (!rad) {
                        cur_res = cur_res/180*M_PI;
                    }
                    cur_res = cosx(cur_res);
                }
                // arccos
                else if (formula[bracket_pos.top()-1] == 'c') {
                    cur_res = acos(cur_res);
                }
                // tan
                else if (formula[bracket_pos.top()-1] == 'T') {
                    if (!rad) {
                        cur_res = cur_res/180*M_PI;
                    }
                    cur_res = tanx(cur_res);
                }
                // arctan
                else if (formula[bracket_pos.top()-1] == 't') {
                    cur_res = atan(cur_res);
                }
                // ln
                else if (formula[bracket_pos.top()-1] == 'L') {
                    // 定义域检验
                    if (cur_res <= 0) {
                        throw "对数运算中真数必须为非负数！";
                    }
                    cur_res = log(cur_res);
                }
            }
            // 结果入数字栈
            nums.push(cur_res);
            continus_nums_len++;
            // cout << sub_formula << " = " << cur_res << endl;
            // 弹出左括号
            bracket_pos.pop();
        }
        // 若当前位置是左括号 则将下标入左括号位置栈 方便后续截取括号内内容
        else if (formula[i] == '(') {
            bracket_pos.push(i);
        }
        // 特殊数字入栈
        else if (formula[i] == 'P') {
            if (bracket_pos.empty()) {
                nums.push(M_PI);
                continus_nums_len++;
            }
        }
        else if (formula[i] == 'E') {
            if (bracket_pos.empty()) {
                nums.push(M_E);
                continus_nums_len++;
            }
        }
        // 普通数字入栈
        // cout << i << " " << formula[i] << " " << bracket_pos.empty() << endl;
        if (is_num(formula[i]) && bracket_pos.empty()) {
            tmp += formula[i];
        }
        else {
            if (tmp.size() > 0) {
                // 如果当前不在括号内则直接入栈
                nums.push(num_vec[stoi(tmp)]);
                continus_nums_len++;
                // cout << num_vec[stoi(tmp)] << endl;
            }
            tmp = "";
        }
        // 操作入栈
        if (formula[i] == '+' || formula[i] == '-' || formula[i] == '*' ||\
            formula[i] == '/' || formula[i] == '^' || formula[i] == '!' ||\
            formula[i] == '@' || formula[i] == '%' || formula[i] == 'M' ||\
            formula[i] == 'l') {
            if (bracket_pos.empty()) {
                ops.push(formula[i]);
                // 将连续数字相乘处理
                if (continus_nums_len > 1) {
                    double prods = 1;
                    while (continus_nums_len > 0) {
                        continus_nums_len--;
                        prods *= nums.top();
                        nums.pop();
                    }
                    nums.push(prods);
                }
                // 清空连续数字数
                continus_nums_len = 0;
            }
        }

    }

    // 尾部数字处理
    if (tmp.size() > 0) {
        nums.push(num_vec[stoi(tmp)]);
        continus_nums_len++;
        tmp = "";
    }
    // 将连续数字相乘处理
    if (continus_nums_len > 1) {
        double prods = 1;
        while (continus_nums_len > 0) {
            continus_nums_len--;
            prods *= nums.top();
            nums.pop();
        }
        nums.push(prods);
    }

    // 扫描完括号还没配对完
    if (!bracket_pos.empty()) {
        throw "非法的括号表达式！";
    }

    // 特殊情况处理 --- 无操作符直接返回
    if (ops.empty()) {
        return nums.top();
    }

    // 数据检查
    // stack_display(nums);
    // 操作符栈检查
    // stack_display(ops);

    // 处理特殊操作符 --- ^, !, !!, %, l
    vector<char> nos_ops = {};
    vector<double> nos_num = {};
    while (!ops.empty()) {
        // !!
        if (ops.top() == '@') {
            if (nums.empty()) {
                throw "非法表达式！";
            }
            double tmp = pprod(nums.top());
            nums.pop();
            nums.push(tmp);
        }
        // !
        else if (ops.top() == '!') {
            if (nums.empty()) {
                throw "非法表达式！";
            }
            double tmp = prod(nums.top());
            nums.pop();
            nums.push(tmp);
        }
        // ^
        else if (ops.top() == '^') {
            if (nums.empty()) {
                throw "非法表达式！";
            }
            double tmp = nums.top();
            nums.pop();
            if (nums.empty()) {
                throw "非法表达式！";
            }
            tmp = pow(nums.top(), tmp);
            nums.pop();
            nums.push(tmp);
        }
        // log
        else if (ops.top() == 'l') {
            if (nums.empty()) {
                throw "非法表达式！";
            }
            double tmp = nums.top();
            nums.pop();
            if (nums.empty()) {
                throw "非法表达式！";
            }
            tmp = logx(nums.top(), tmp);
            nums.pop();
            nums.push(tmp);
        }
        // %
        else if (ops.top() == '%') {
            if (nums.empty()) {
                throw "非法表达式！";
            }
            double tmp = nums.top()*0.01;
            nums.pop();
            nums.push(tmp);
        }
        else {
            if (!nums.empty()) {
                nos_num.push_back(nums.top());
                nums.pop();
            }
            nos_ops.push_back(ops.top());
        }
        ops.pop();
    }

    // 数据检查
    // stack_display(nums);
    // 操作符栈检查
    // stack_display(ops);

    // 将处理后的数字和操作符入栈
    if (!nos_num.empty()) {
        for (int i = nos_num.size()-1; i >= 0; i--) {
            nums.push(nos_num[i]);
        }
    }
    if (!nos_ops.empty()) {
        for (int i = nos_ops.size()-1; i >= 0; i--) {
            ops.push(nos_ops[i]);
        }
    }

    // 数据检查
    // stack_display(nums);
    // 操作符栈检查
    // stack_display(ops);

    // 特殊情况直接返回
    if (ops.empty()) {
        return nums.top();
    }

    // 开始计算
    while (!ops.empty()) {
        // 获取当前操作符
        char op = ops.top();
        // 临时操作栈 & 临时数字栈
        stack<char> tmp_ops;
        stack<double> tmp_nums;

        // 遍历
        // 若当前为一级操作符+, - 或 MOD则直接加入结果 因为所有括号已去除
        if (op == '+' || op == '-' || op == 'M') {
            if (nums.empty()) {
                throw "非法表达式！";
            }
            if (op != 'M') {
                res += nums.top()*(op == '+' ? 1 : -1);
                nums.pop();
                ops.pop();
            }
            else {
                double num1 = nums.top();
                nums.pop();
                ops.pop();
                if (nums.empty()) {
                    throw "非法表达式！";
                }
                if (ops.empty() || ops.top() == '+') {
                    res += fmod(nums.top(), num1);
                }
                else {
                    res -= fmod(nums.top(), num1);
                }
                nums.pop();
                // 弹出前面的加减符号
                if (!ops.empty()) {
                    ops.pop();
                }
            }
        }
        // 高级操作符则入临时栈最后依次操作
        else {
            double tmp_res = 0;
            // 先将连续高级运算部分反向入栈恢复正序
            while (!ops.empty() && ops.top() != '+' && ops.top() != '-') {
                if (nums.empty()) {
                    throw "非法表达式！";
                }
                tmp_ops.push(ops.top());
                ops.pop();
                tmp_nums.push(nums.top());
                nums.pop();
            }
            if (nums.empty()) {
                throw "非法表达式！";
            }
            // 如果高级表达式左边没有操作符或是+则*1后加入结果
            if (ops.empty() || ops.top() == '+') {
                tmp_res = nums.top()*1;
                nums.pop();
                if (!ops.empty()) {
                    ops.pop();
                }
            }
            else {
                tmp_res = nums.top()*(-1);
                nums.pop();
                ops.pop();
            }
            // 随后依次进行高级操作
            while (!tmp_ops.empty()) {
                if (tmp_ops.top() == '*') {
                    tmp_res *= tmp_nums.top();
                }
                else {
                    // 判断是否存在 0 除错误
                    if (tmp_nums.top() == 0) {
                        throw "不能用0作分母！！！";
                    }
                    tmp_res /= tmp_nums.top();
                }
                // 操作完弹出当前临时操作符和数字
                tmp_ops.pop();
                tmp_nums.pop();
            }
            res += tmp_res;
        }
    }
    // 如果最左边有残余数字直接加入结果
    if (!nums.empty()) {
        res += nums.top();
        nums.pop();
    }
    // 返回计算结果
    return res;
}

// 将浮点数字符串的多余前缀0和尾缀0去除
string beautiful_double_string(string s) {
    // 检验传入字符串是不是浮点数
    try {
        s = to_string(stof(s));
    }
    catch(const char* msg) {
        string errorMsg(msg);
        throw (errorMsg);
    }

    // 通过检验则开始处理
    string int_s = "";
    string frac_s = "";
    // 是否是多余的0
    bool residual_zero = true;

    // 正向处理整数部分
    for (int i = 0; i < s.size(); i++) {
        // 遇到小数点就溜了
        if (s[i] == '.') {
            break;
        }
        // 处理 0
        if (s[i] == '0') {
            // 多余就啥也不干
            if (residual_zero) {
                continue;
            }
        }
        // 非0的字符
        // 数字字符
        if ('0' < s[i] && s[i] <= '9') {
            // 从此开始整数部分每一个0都不会冗余
            residual_zero = false;
        }
        // 无脑加入整数部分字符
        int_s += s[i];
    }

    // 重置冗余0标志
    residual_zero = true;
    // 反向处理小数部分
    for (int i = s.size()-1; i >= 0; i--) {
        // 遇到小数点就溜了
        if (s[i] == '.') {
            break;
        }
        // 处理 0
        if (s[i] == '0') {
            // 多余就啥也不干
            if (residual_zero) {
                continue;
            }
        }
        // 非0的字符
        else {
            // 从此开始整数部分每一个0都不会冗余
            residual_zero = false;
        }
        // 无脑加入小数部分字符
        frac_s += s[i];
    }

    // 倒置小数部分
    if (frac_s != "") {
        reverse(frac_s.begin(),frac_s.end());
    }

    // 合起来
    // 特殊的小数情况 --- 没有小数位
    if (frac_s == "") {
        if (int_s == "") {
            return "0";
        }
        return int_s;
    }
    // 特殊的整数情况
    // 只有0
    if (int_s == "") {
        return "0."+frac_s;
    }
    // -0
    if (int_s == "-") {
        return "-0."+frac_s;
    }
    return int_s+"."+frac_s;
}

int main()
{
    string formula;
    string processed_formula;
    while (1) {
        cout << "> ";
        cin >> formula;
        if (formula == "exit") {
            break;
        }
        vector<double> num_vec = {};
        processed_formula = num_extract(formula, num_vec);
        try{
            cout << formula << " = " << compute(processed_formula, num_vec, true) << endl;
        }
        catch(const char* msg){
            cout << "Error: " << msg << endl;
        }
    }
    return 0;
}


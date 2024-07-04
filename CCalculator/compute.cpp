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
        throw "�������������ڽ׳����㣡";
    }
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return double(res);
}

double pprod(double n) {
    if (n-int(n) != 0) {
        throw "�������������ڽ׳����㣡";
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
    // �����͵����Ķ��������
    if (a <= 0 || a == 1) {
        throw "����������󣡵�������Ϊ����1�ķǸ�����";
    }
    // ��������
    if (b <= 0) {
        throw "������������������Ϊ�Ǹ�����";
    }
    // ͨ������ֱ�Ӽ���
    return log(a)/log(b);
}

// �� --- ����ȷ���Ƿ��� Pi ��������
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
    // β����
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

// ���㺯��
double compute(string formula, vector<double> &num_vec, bool rad)
{
    // �ձ��ʽ
    if (formula.size() == 0) {
        throw "�ձ��ʽ��";
    }
    // ������ջ
    stack<double> nums;
    stack<char> ops;
    // ������λ��ջ
    stack<int> bracket_pos;
    // ���ִ洢�±괮
    string tmp = "";
    // ������
    double res = 0;

    // ɨ�蹫ʽ�ַ����������������õ�����
    // �������ֳ���
    int continus_nums_len = 0;
    for (int i = 0; i < formula.size(); i++) {
        // ����ǰλ���������� �򵯳�ջ��������λ�� ���н�ȡ������ջ
        if (formula[i] == ')') {
            // ջ�ձ���
            if (bracket_pos.empty()) {
                throw "�Ƿ������ű��ʽ��";
            }
            // ��������Ϊ�ձ���
            if (i-bracket_pos.top() == 1) {
                throw "�����ݵ����Ŷ��ǲ�������ģ������ڱ����б��ʽ��";
            }
            // ������������˴���
            if (continus_nums_len > 1) {
                double prods = 1;
                while (continus_nums_len > 0) {
                    continus_nums_len--;
                    prods *= nums.top();
                    nums.pop();
                }
                nums.push(prods);
            }
            // �������������
            continus_nums_len = 0;
            // ���������������򵯵�һ�������ż���
            if (bracket_pos.size() != 1) {
                bracket_pos.pop();
                continue;
            }
            string sub_formula = formula.substr(bracket_pos.top()+1,
                                                i-bracket_pos.top()-1);

            // �����������ݼ���������ջ
            double cur_res = compute(sub_formula, num_vec, rad);
            // �ж��Ƿ���Ҫ���к�������
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
                    // ���������
                    if (cur_res <= 0) {
                        throw "������������������Ϊ�Ǹ�����";
                    }
                    cur_res = log(cur_res);
                }
            }
            // ���������ջ
            nums.push(cur_res);
            continus_nums_len++;
            // cout << sub_formula << " = " << cur_res << endl;
            // ����������
            bracket_pos.pop();
        }
        // ����ǰλ���������� ���±���������λ��ջ ���������ȡ����������
        else if (formula[i] == '(') {
            bracket_pos.push(i);
        }
        // ����������ջ
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
        // ��ͨ������ջ
        // cout << i << " " << formula[i] << " " << bracket_pos.empty() << endl;
        if (is_num(formula[i]) && bracket_pos.empty()) {
            tmp += formula[i];
        }
        else {
            if (tmp.size() > 0) {
                // �����ǰ������������ֱ����ջ
                nums.push(num_vec[stoi(tmp)]);
                continus_nums_len++;
                // cout << num_vec[stoi(tmp)] << endl;
            }
            tmp = "";
        }
        // ������ջ
        if (formula[i] == '+' || formula[i] == '-' || formula[i] == '*' ||\
            formula[i] == '/' || formula[i] == '^' || formula[i] == '!' ||\
            formula[i] == '@' || formula[i] == '%' || formula[i] == 'M' ||\
            formula[i] == 'l') {
            if (bracket_pos.empty()) {
                ops.push(formula[i]);
                // ������������˴���
                if (continus_nums_len > 1) {
                    double prods = 1;
                    while (continus_nums_len > 0) {
                        continus_nums_len--;
                        prods *= nums.top();
                        nums.pop();
                    }
                    nums.push(prods);
                }
                // �������������
                continus_nums_len = 0;
            }
        }

    }

    // β�����ִ���
    if (tmp.size() > 0) {
        nums.push(num_vec[stoi(tmp)]);
        continus_nums_len++;
        tmp = "";
    }
    // ������������˴���
    if (continus_nums_len > 1) {
        double prods = 1;
        while (continus_nums_len > 0) {
            continus_nums_len--;
            prods *= nums.top();
            nums.pop();
        }
        nums.push(prods);
    }

    // ɨ�������Ż�û�����
    if (!bracket_pos.empty()) {
        throw "�Ƿ������ű��ʽ��";
    }

    // ����������� --- �޲�����ֱ�ӷ���
    if (ops.empty()) {
        return nums.top();
    }

    // ���ݼ��
    // stack_display(nums);
    // ������ջ���
    // stack_display(ops);

    // ������������� --- ^, !, !!, %, l
    vector<char> nos_ops = {};
    vector<double> nos_num = {};
    while (!ops.empty()) {
        // !!
        if (ops.top() == '@') {
            if (nums.empty()) {
                throw "�Ƿ����ʽ��";
            }
            double tmp = pprod(nums.top());
            nums.pop();
            nums.push(tmp);
        }
        // !
        else if (ops.top() == '!') {
            if (nums.empty()) {
                throw "�Ƿ����ʽ��";
            }
            double tmp = prod(nums.top());
            nums.pop();
            nums.push(tmp);
        }
        // ^
        else if (ops.top() == '^') {
            if (nums.empty()) {
                throw "�Ƿ����ʽ��";
            }
            double tmp = nums.top();
            nums.pop();
            if (nums.empty()) {
                throw "�Ƿ����ʽ��";
            }
            tmp = pow(nums.top(), tmp);
            nums.pop();
            nums.push(tmp);
        }
        // log
        else if (ops.top() == 'l') {
            if (nums.empty()) {
                throw "�Ƿ����ʽ��";
            }
            double tmp = nums.top();
            nums.pop();
            if (nums.empty()) {
                throw "�Ƿ����ʽ��";
            }
            tmp = logx(nums.top(), tmp);
            nums.pop();
            nums.push(tmp);
        }
        // %
        else if (ops.top() == '%') {
            if (nums.empty()) {
                throw "�Ƿ����ʽ��";
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

    // ���ݼ��
    // stack_display(nums);
    // ������ջ���
    // stack_display(ops);

    // �����������ֺͲ�������ջ
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

    // ���ݼ��
    // stack_display(nums);
    // ������ջ���
    // stack_display(ops);

    // �������ֱ�ӷ���
    if (ops.empty()) {
        return nums.top();
    }

    // ��ʼ����
    while (!ops.empty()) {
        // ��ȡ��ǰ������
        char op = ops.top();
        // ��ʱ����ջ & ��ʱ����ջ
        stack<char> tmp_ops;
        stack<double> tmp_nums;

        // ����
        // ����ǰΪһ��������+, - �� MOD��ֱ�Ӽ����� ��Ϊ����������ȥ��
        if (op == '+' || op == '-' || op == 'M') {
            if (nums.empty()) {
                throw "�Ƿ����ʽ��";
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
                    throw "�Ƿ����ʽ��";
                }
                if (ops.empty() || ops.top() == '+') {
                    res += fmod(nums.top(), num1);
                }
                else {
                    res -= fmod(nums.top(), num1);
                }
                nums.pop();
                // ����ǰ��ļӼ�����
                if (!ops.empty()) {
                    ops.pop();
                }
            }
        }
        // �߼�������������ʱջ������β���
        else {
            double tmp_res = 0;
            // �Ƚ������߼����㲿�ַ�����ջ�ָ�����
            while (!ops.empty() && ops.top() != '+' && ops.top() != '-') {
                if (nums.empty()) {
                    throw "�Ƿ����ʽ��";
                }
                tmp_ops.push(ops.top());
                ops.pop();
                tmp_nums.push(nums.top());
                nums.pop();
            }
            if (nums.empty()) {
                throw "�Ƿ����ʽ��";
            }
            // ����߼����ʽ���û�в���������+��*1�������
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
            // ������ν��и߼�����
            while (!tmp_ops.empty()) {
                if (tmp_ops.top() == '*') {
                    tmp_res *= tmp_nums.top();
                }
                else {
                    // �ж��Ƿ���� 0 ������
                    if (tmp_nums.top() == 0) {
                        throw "������0����ĸ������";
                    }
                    tmp_res /= tmp_nums.top();
                }
                // �����굯����ǰ��ʱ������������
                tmp_ops.pop();
                tmp_nums.pop();
            }
            res += tmp_res;
        }
    }
    // ���������в�������ֱ�Ӽ�����
    if (!nums.empty()) {
        res += nums.top();
        nums.pop();
    }
    // ���ؼ�����
    return res;
}

// ���������ַ����Ķ���ǰ׺0��β׺0ȥ��
string beautiful_double_string(string s) {
    // ���鴫���ַ����ǲ��Ǹ�����
    try {
        s = to_string(stof(s));
    }
    catch(const char* msg) {
        string errorMsg(msg);
        throw (errorMsg);
    }

    // ͨ��������ʼ����
    string int_s = "";
    string frac_s = "";
    // �Ƿ��Ƕ����0
    bool residual_zero = true;

    // ��������������
    for (int i = 0; i < s.size(); i++) {
        // ����С���������
        if (s[i] == '.') {
            break;
        }
        // ���� 0
        if (s[i] == '0') {
            // �����ɶҲ����
            if (residual_zero) {
                continue;
            }
        }
        // ��0���ַ�
        // �����ַ�
        if ('0' < s[i] && s[i] <= '9') {
            // �Ӵ˿�ʼ��������ÿһ��0����������
            residual_zero = false;
        }
        // ���Լ������������ַ�
        int_s += s[i];
    }

    // ��������0��־
    residual_zero = true;
    // ������С������
    for (int i = s.size()-1; i >= 0; i--) {
        // ����С���������
        if (s[i] == '.') {
            break;
        }
        // ���� 0
        if (s[i] == '0') {
            // �����ɶҲ����
            if (residual_zero) {
                continue;
            }
        }
        // ��0���ַ�
        else {
            // �Ӵ˿�ʼ��������ÿһ��0����������
            residual_zero = false;
        }
        // ���Լ���С�������ַ�
        frac_s += s[i];
    }

    // ����С������
    if (frac_s != "") {
        reverse(frac_s.begin(),frac_s.end());
    }

    // ������
    // �����С����� --- û��С��λ
    if (frac_s == "") {
        if (int_s == "") {
            return "0";
        }
        return int_s;
    }
    // ������������
    // ֻ��0
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


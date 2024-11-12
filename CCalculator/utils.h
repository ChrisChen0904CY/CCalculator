#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <stack>
#include <iostream>

// 大数及大数科学计算库
#include "cbignum.h"
#include "cbigmath.h"

using namespace std;

string getCurrentTimestamp();

template <class T>
void stack_display(stack<T>& s) {
    vector<T> tmp = {};
    while (!s.empty()) {
        cout << s.top() << endl;
        tmp.push_back(s.top());
        s.pop();
    }
    for (int i = tmp.size()-1; i >= 0; i--) {
        s.push(tmp[i]);
    }

}

bool is_num(char c);
CBigNum prod(CBigNum n);
CBigNum pprod(CBigNum n);
string num_extract(string formula, vector<CBigNum>& vec, long long bits);
CBigNum compute(string formula, vector<CBigNum> &num_vec, CBigNum &PI_Cached,
                bool rad=true,
                long long bits=8,
                bool fd=true);
string beautiful_double_string(string s);

#endif // UTILS_H

#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <stack>
#include <iostream>

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
double prod(double n);
double pprod(double n);
double logx(double a, double b);
double sinx(double x);
double cosx(double x);
double tanx(double x);
string num_extract(string formula, vector<double>& vec);
void vec_display(vector<double> vec);
double compute(string formula, vector<double> &num_vec, bool rad=true);
string beautiful_double_string(string s);

#endif // UTILS_H

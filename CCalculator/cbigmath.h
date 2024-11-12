#ifndef CBIGMATH_H
#define CBIGMATH_H

#include "cbignum.h"

// PI
#define PI   3.14159265358979324
#define PI_2 1.57079632679489662
#define PI_4 0.78539816339744831
#define SINA4 0.70710678118654752
#define COSA4 0.70710678118654752
#define PI_6 0.52359877559829887
#define SINA3 0.5
#define COSA3 0.86602540378443865
#define PI_12 0.26179938779914944
#define SINA2 0.25881094510252076
#define COSA2 0.96592582628906829
#define PI_24 0.13089969389957472
#define SINA1 0.13052619222005159
#define COSA1 0.99144486137381041

template <typename T>
CBigNum any2BigNum(T value) {
    CBigNum num(value);
    return num;
}

/**
* @Brief: Better Division optimized by Repeating Decimal Period Theorem
* @Author: Chris Chan
* @Date: 2024/11/12
*/
template <typename T>
CBigNum fdivision(const CBigNum& a, const T& b) {
    bool positive = a.getPositive() && (CBigNum(b).getPositive());
    CBigNum num1 = abs(a);
    CBigNum num2 = abs(CBigNum(b));
    if(num2 == 0) {
        throw "Unsupport Operation: Divided by 0.";
        return CBigNum(-1);
    }
    if(num1 == 0) {
        return CBigNum(0);
    }
    // Integerize
    long long num1FracBits = num1.getFracs().size();
    long long num2FracBits = num2.getFracs().size();
    num1 <<= max(num1FracBits, num2FracBits);
    num2 <<= max(num1FracBits, num2FracBits);
    // Simplify
    CBigNum _gcd = gcd(num1, num2);
    num1 /= _gcd;
    num2 /= _gcd;
    // Find the Largest Repeat Decimal Period
    long long unrepeat_cnt = 0;
    CBigNum tmp = num2;
    while(tmp % 2 == 0 || tmp % 5 == 0) {
        if(tmp % 2 == 0){
            tmp /= 2;
            unrepeat_cnt++;
        }
        if(tmp % 5 == 0){
            tmp /= 5;
            unrepeat_cnt++;
        }
    }
    // Unrepeat
    if(tmp == 1){
        return positive ? num1/num2 : -num1/num2;
    }
    // Do Exist a Repeat Period
    else{
        CBigNum tens(10);
        while(tens % tmp != 1) {
            if(tens.getInts().size() == num1.getResFracBits()) {
                break;
            }
            tens <<= 1;
        }
        if(tens.getInts().size() == num1.getResFracBits()) {
            return positive ? num1/num2 : -num1/num2;
        }
        // Extract the integer part first
        pair<CBigNum, CBigNum> res = num1.intDivision(num2);
        num1 = res.second << 1;
        short tmp = 0;
        vector<char> repeats;
        while(repeats.size() < tens.getInts().size()-1) {
            if (num1 < num2) {
                num1 <<= 1;
                res.first.pushFrac('0'+tmp%10);
                if(res.first.getFracs().size() > unrepeat_cnt)  {
                    repeats.push_back('0'+tmp%10);
                }
                tmp = 0;
            }
            else {
                num1 -= num2;
                tmp++;
            }
        }
        // Fill the rest part with the repeat period
        for(long long i = 0; i <= num1.getResFracBits()-res.first.getFracs().size(); i++) {
            res.first.pushFrac(repeats[i%repeats.size()]);
        }
        res.first.round(num1.getResFracBits());
        return positive ? res.first : -res.first;
    }
}

/**
* @Brief: Polynomial Calculation
* @Author: Chris Chan
* @Date: 2024/09/20
*/
template <typename T>
CBigNum poly_value(const T& value, T* A, long long n) {
    CBigNum y(A[n]);
    CBigNum x(value);
    // QinJiuShao Algorithm(Also known as horner's algorithm)
    for(long long i = n-1; i >= 0; i--) {
    	y = y*x + A[i];
		}
		return y;
}
template <typename T>
CBigNum poly_value(const T& value, vector<T> A) {
	  long long n = A.size()-1;
    CBigNum y(A[n]);
    CBigNum x(value);
    // QinJiuShao Algorithm(Also known as horner's algorithm)
    for(long long i = n-1; i >= 0; i--) {
    	y = y*x + A[i];
		}
		return y;
}

/**
* @Brief: Power operation for Integer power
* @Author: Chris Chan
* @Date: 2024/09/18
*/
CBigNum pow(const CBigNum& num, long long value, bool fd = true);

/**
* @Brief: nrt, sqrt, cbrt for positive integer n
* @Author: Chris Chan
* @Date: 2024/09/20
*/
template <typename T>
CBigNum nrt(const T& value, long long n, bool fd = true) {
	  CBigNum a(value);
	  // Value Check
	  if (a < 0) {
	  	throw "sqrt(num, n) can only work on non-negative number!";
		}
		if (a == 0 || a == 1) {
			return a;
		}
    // Right Bound
    CBigNum right_bound = CBigNum(1) << n;
    // Shift Counts
    long long shift_counts = 0;
    // Shift the given number to [1, 10^n]
    while (1) {
    	if (a >= 1 && a <= right_bound) {
    		break;
			}
    	else if (a < 1) {
    		a <<= n;
    		shift_counts += 1;
			}
			else{
				a >>= n;
    		shift_counts -= 1;
			}
		}
		// Newton Iteration
        CBigNum x0(10.5), x1;
        if(fd) {
            CBigNum x1 = x0*(n-1)/n + fdivision(fdivision(a, n), pow(x0, n-1));
        }
        else {
            CBigNum x1 = x0*(n-1)/n + a/n/pow(x0, n-1);
        }
		// The num of iteration limitation
		int iter_limit = 100;
		int k = 0;
		while(k < iter_limit && abs(x1*x1 - a) >= (CBigNum(1) >> (a.getResFracBits()+1))) {
            if(fd) {
                x1 = x0*(1-1.0/n) + fdivision(fdivision(a, n), pow(x0, n-1));
            }
            else {
                x1 = x0*(1-1.0/n) + a/n/pow(x0, n-1);
            }
			x1.round(a.getResFracBits()+1);
			if (x0 == x1) {
				break;
			}
			x0 = x1;
			k++;
		}
		x1 >>= (shift_counts);
		x1.round(a.getResFracBits());
		return x1;
}

template <typename T>
CBigNum sqrt(const T& value, bool fd = true) {
    return nrt(value, 2, fd);
}

template <typename T>
CBigNum cbrt(const T& value, bool fd = true) {
    return nrt(value, 3, fd);
}

/**
* @Brief: Ln & Log
* @Author: Chris Chan
* @Date: 2024/09/19
*/
// Find the log_N
long long log_N_find(const CBigNum& a, bool fd = true);

// ln
CBigNum ln(const CBigNum& a, bool fd = true);
template <typename T>
CBigNum ln(const T& value, bool fd = true) {
    CBigNum num = any2BigNum(value);
    return ln(num, fd);
}
// log
template <typename T>
CBigNum log(const CBigNum& base, const T& value, bool fd = true) {
	// Check the base first
	if (base <= 0 || base == 1) {
		throw "Log Base Error: Base must be positive and not 1.";
	}
	CBigNum natrual = CBigNum(value);
	natrual.setResFracBits(base.getResFracBits());
	// Check the natrual then
	if (natrual <= 0) {
		throw "Log Natrual Error: Natrual must be positive.";
	}
	// Return 1 when natrual == base
	if (natrual == base) {
		CBigNum one(1);
		one.setResFracBits(base.getResFracBits());
		return one;
	}
    if(fd) {
        return fdivision(ln(natrual), ln(base));
    }
    return ln(natrual, false) / ln(base, false);
}

/**
* @Brief: Sin and Cos simulation
* @Author: Chris Chan
* @Date: 2024/09/21
*/
long long SINCOS_N_find(const CBigNum& x, bool fd = true);
CBigNum SINTNV(const CBigNum& x, bool fd = true);
CBigNum COSTNV(const CBigNum& x, bool fd = true);

/**
* @Brief: Trigonometric functions
* @Author: Chris Chan
* @Date: 2024/09/21
*/
// sin
CBigNum sin(const CBigNum& a, bool fd = true);
template <typename T>
CBigNum sin(const T& value, bool fd = true) {
    CBigNum num = any2BigNum(value);
    return sin(num, fd);
}
// cos
CBigNum cos(const CBigNum& a, bool fd = true);
template <typename T>
CBigNum cos(const T& value, bool fd = true) {
    CBigNum num = any2BigNum(value);
    return cos(num, fd);
}
// tan
CBigNum tan(const CBigNum& a, bool fd = true);
template <typename T>
CBigNum tan(const T& value, bool fd = true) {
    CBigNum num = any2BigNum(value);
    return tan(num, fd);
}
// cot
CBigNum cot(const CBigNum& a, bool fd = true);
template <typename T>
CBigNum cot(const T& value, bool fd = true) {
    CBigNum num = any2BigNum(value);
    return cot(num, fd);
}

/**
* @Brief: e^x simulation
* @Author: Chris Chan
* @Date: 2024/09/22
*/
long long EXP_N_find(const CBigNum& x, bool fd = true);
CBigNum EXPTNV(const CBigNum& x, bool fd = true);
// e^x
CBigNum exp(const CBigNum& a, bool fd = true);
template <typename T>
CBigNum exp(const T& value, bool fd = true) {
    CBigNum num = any2BigNum(value);
    return exp(num, fd);
}

/**
* @Brief: Power operation
* @Author: Chris Chan
* @Date: 2024/09/18
*/
template <typename T>
CBigNum pow(const CBigNum& num, const T& value, bool fd = true) {
    CBigNum other = CBigNum(value);
    // Deal with 0 power
    if (other == 0) {
        return CBigNum(1);
    }
    if (num == 0) {
    	return CBigNum(0);
    }
    CBigNum res(1);
    bool posPower = other.getPositive();
    other = abs(other);
    // Integer Power
    if (other.getFracs().empty()) {
    	CBigNum base = num;
        while (other > 0) {
            if (other % 2 == 1) {
                res *= base;
                res.round(num.getResFracBits()+1);
            }
            base *= base;
            base.round(num.getResFracBits()+1);
            other = other.intDivision(2).first;
   		}
   		res.round(num.getResFracBits());
   		// Deal with the negative power
   		CBigNum one(1);
   		one.setResFracBits(num.getResFracBits());
        return posPower ? res : (fd ? fdivision(one, res) : one/res);
    }
    // a^x = e^(x*lna)
    else {
        if (num < 0) {
            throw "Can't deal with a^x when a<0.";
        }
        CBigNum tmp = other*ln(num, fd);
        tmp.setResFracBits(num.getResFracBits());
        res = exp(tmp, fd);
        // Deal with the negative power
   		CBigNum one(1);
   		one.setResFracBits(num.getResFracBits());
        return posPower ? res : (fd ? fdivision(one, res) : one/res);
    }
}

/**
* @Brief: Anti-Trigonometric functions
* @Author: Chris Chan
* @Date: 2024/09/23
*/
// ASin Iteratoin
long long ASIN_N_find(const CBigNum& x, bool fd = true);
CBigNum ASINTNV(const CBigNum& x, bool fd = true);
// ATan Iteratoin
long long ATAN_N_find(const CBigNum& x, bool fd = true);
CBigNum ATANTNV(const CBigNum& x, bool fd = true);
// arcsin
CBigNum asin(const CBigNum& a, CBigNum PI_Given=PI, bool fd = true);
template <typename T>
CBigNum asin(const T& value, CBigNum PI_Given=PI, bool fd = true) {
    CBigNum num = any2BigNum(value);
    return asin(num, PI_Given, fd);
}
// arccos
CBigNum acos(const CBigNum& a, CBigNum PI_Given=PI, bool fd = true);
template <typename T>
CBigNum acos(const T& value, CBigNum PI_Given=PI, bool fd = true) {
    CBigNum num = any2BigNum(value);
    return acos(num, PI_Given, fd);
}
// arctan
CBigNum atan(const CBigNum& a, CBigNum PI_Given=PI, bool fd = true);
template <typename T>
CBigNum atan(const T& value, CBigNum PI_Given=PI, bool fd = true) {
    CBigNum num = any2BigNum(value);
    return atan(num, PI_Given, fd);
}
// arccot
CBigNum acot(const CBigNum& a, CBigNum PI_Given=PI, bool fd = true);
template <typename T>
CBigNum acot(const T& value, CBigNum PI_Given=PI, bool fd = true) {
    CBigNum num = any2BigNum(value);
    return acot(num, PI_Given, fd);
}

// Calculate π
CBigNum PI_Calculate(long long bits, bool fd = true);

#endif

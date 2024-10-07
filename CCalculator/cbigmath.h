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
CBigNum pow(const CBigNum& num, long long value);

/**
* @Brief: nrt, sqrt, cbrt for positive integer n
* @Author: Chris Chan
* @Date: 2024/09/20
*/
template <typename T>
CBigNum nrt(const T& value, long long n) {
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
		CBigNum x0(10.5);
		CBigNum x1 = x0*(n-1)/n + a/n/pow(x0, n-1);
		// The num of iteration limitation
		int iter_limit = 100;
		int k = 0;
		while(k < iter_limit && abs(x1*x1 - a) >= (CBigNum(1) >> (a.getResFracBits()+1))) {
			x1 = x0*(1-1.0/n) + a/n/pow(x0, n-1);
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
CBigNum sqrt(const T& value) {
	return nrt(value, 2);
}

template <typename T>
CBigNum cbrt(const T& value) {
	return nrt(value, 3);
}

/**
* @Brief: Ln & Log
* @Author: Chris Chan
* @Date: 2024/09/19
*/
// Find the log_N
long long log_N_find(const CBigNum& a);

// ln
CBigNum ln(const CBigNum& a);
template <typename T>
CBigNum ln(const T& value) {
    CBigNum num = any2BigNum(value);
    return ln(num);
}
// log
template <typename T>
CBigNum log(const CBigNum& base, const T& value) {
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
	return ln(natrual) / ln(base);
}

/**
* @Brief: Sin and Cos simulation
* @Author: Chris Chan
* @Date: 2024/09/21
*/
long long SINCOS_N_find(const CBigNum& x);
CBigNum SINTNV(const CBigNum& x);
CBigNum COSTNV(const CBigNum& x);

/**
* @Brief: Trigonometric functions
* @Author: Chris Chan
* @Date: 2024/09/21
*/
// sin
CBigNum sin(const CBigNum& a);
template <typename T>
CBigNum sin(const T& value) {
    CBigNum num = any2BigNum(value);
    return sin(num);
}
// cos
CBigNum cos(const CBigNum& a);
template <typename T>
CBigNum cos(const T& value) {
    CBigNum num = any2BigNum(value);
    return cos(num);
}
// tan
CBigNum tan(const CBigNum& a);
template <typename T>
CBigNum tan(const T& value) {
    CBigNum num = any2BigNum(value);
    return tan(num);
}
// cot
CBigNum cot(const CBigNum& a);
template <typename T>
CBigNum cot(const T& value) {
    CBigNum num = any2BigNum(value);
    return cot(num);
}

/**
* @Brief: e^x simulation
* @Author: Chris Chan
* @Date: 2024/09/22
*/
long long EXP_N_find(const CBigNum& x);
CBigNum EXPTNV(const CBigNum& x);
// e^x
CBigNum exp(const CBigNum& a);
template <typename T>
CBigNum exp(const T& value) {
    CBigNum num = any2BigNum(value);
    return exp(num);
}

/**
* @Brief: Power operation
* @Author: Chris Chan
* @Date: 2024/09/18
*/
template <typename T>
CBigNum pow(const CBigNum& num, const T& value) {
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
   		return posPower ? res : (one/res);
    }
    // a^x = e^(x*lna)
    else {
        if (num < 0) {
            throw "Can't deal with a^x when a<0.";
        }
        CBigNum tmp = other*ln(num);
        tmp.setResFracBits(num.getResFracBits());
        res = exp(tmp);
        // Deal with the negative power
   		CBigNum one(1);
   		one.setResFracBits(num.getResFracBits());
   		return posPower ? res : (one/res);
    }
}

/**
* @Brief: Anti-Trigonometric functions
* @Author: Chris Chan
* @Date: 2024/09/23
*/
// ASin Iteratoin
long long ASIN_N_find(const CBigNum& x);
CBigNum ASINTNV(const CBigNum& x);
// ATan Iteratoin
long long ATAN_N_find(const CBigNum& x);
CBigNum ATANTNV(const CBigNum& x);
// arcsin
CBigNum asin(const CBigNum& a, CBigNum PI_Given=PI);
template <typename T>
CBigNum asin(const T& value, CBigNum PI_Given=PI) {
    CBigNum num = any2BigNum(value);
    return asin(num, PI_Given);
}
// arccos
CBigNum acos(const CBigNum& a, CBigNum PI_Given=PI);
template <typename T>
CBigNum acos(const T& value, CBigNum PI_Given=PI) {
    CBigNum num = any2BigNum(value);
    return acos(num, PI_Given);
}
// arctan
CBigNum atan(const CBigNum& a, CBigNum PI_Given=PI);
template <typename T>
CBigNum atan(const T& value, CBigNum PI_Given=PI) {
    CBigNum num = any2BigNum(value);
    return atan(num, PI_Given);
}
// arccot
CBigNum acot(const CBigNum& a, CBigNum PI_Given=PI);
template <typename T>
CBigNum acot(const T& value, CBigNum PI_Given=PI) {
    CBigNum num = any2BigNum(value);
    return acot(num, PI_Given);
}

// Calculate π
CBigNum PI_Calculate(long long bits);

#endif

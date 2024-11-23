#include "cbigmath.h"

CBigNum pow(const CBigNum& num, long long value, bool fd) {
    CBigNum other = value;
    // Deal with 0 power
    if (other == 0) {
        return CBigNum(1);
    }
    CBigNum res(1);
    bool posPower = other.getPositive();
    other = abs(other);
    // Integer Power
    CBigNum base = num;
    while (other > 0) {
        if (other % 2 == 1) {
            res *= base;
        }
        base *= base;
        other = other.intDivision(2).first;
    }
    // Deal with the negative power
    CBigNum one(1);
    one.setResFracBits(num.getResFracBits());
    return posPower ? res : (fd ? fdivision(one, res) : one/res);
}

// Find the log_N
long long log_N_find(const CBigNum& a, bool fd) {
	long long log_N = 1;
    CBigNum one = 1;
	CBigNum xx = a*a;
    CBigNum Rn;
    if(fd) {
        Rn = fdivision(xx, (log_N*2))*fdivision(one, (one-xx));
    }
    else {
        Rn = xx/(log_N*2)*(one/(one-xx));
    }
	CBigNum epsilon = CBigNum(1) >> (a.getResFracBits()+1);
	while (1) {
		if (abs(Rn) < epsilon) {
			break;
		}
		log_N += 1;
        Rn *= xx*(-1/(log_N+1)+1);
	}
	return log_N;
}

CBigNum ln(const CBigNum& a, bool fd, bool naive) {
    CBigNum num = a;
    long long scaled_k = 0;
    
    // Check the natural first
    if (num <= 0) {
      throw "Log Natural Error: Natural must be positive.";
      return CBigNum(0);  
    }

    while (num < 1) {
        num <<= 1;
        scaled_k++;
    }

    // Handle numbers greater than 1 by reducing them
    long long k = 0;
    while (num > 10) {
        num >>= 1;
        k++;
    }

    CBigNum x;
    if(fd) {
        x = fdivision(num - 1, num + 1);
    }
    else {
        x = naive ? (num - 1).ndivision(num + 1) : (num - 1)/(num + 1);
    }
    CBigNum xx = x*x;
    long long log_N = log_N_find(x, fd);
    long long nk = 2*log_N+1;
    CBigNum y = CBigNum(1)/nk;
    
    for(long long i = 0; i < log_N; i++)
    {
        nk = nk - 2;
        if(fd) {
            y = fdivision(CBigNum(1), nk)+xx*y;
        }
        else {
            y = naive ? CBigNum(1).ndivision(CBigNum(nk)) : CBigNum(1)/nk+xx*y;
        }
        y.round(num.getResFracBits()+1);
    }

    // Adding the correction term for the number of divisions we performed
    CBigNum ln10("2.302585092994046");
    CBigNum result = x*y*2.0 + ln10 * (k-scaled_k);

    result.round(num.getResFracBits());
    result.setResFracBits(num.getResFracBits());
    return result;
}

CBigNum naive_ln(const CBigNum& a, bool fd, bool naive) {
    CBigNum num = a;

    // Check the natural first
    if (num <= 0) {
        throw "Log Natural Error: Natural must be positive.";
        return CBigNum(0);
    }

    CBigNum x;
    if(fd) {
        x = fdivision(num - 1, num + 1);
    }
    else {
        x = naive ? (num - 1).ndivision(num + 1) : (num - 1)/(num + 1);
    }
    CBigNum xx = x*x;
    long long log_N = log_N_find(x, fd);
    long long nk = 2*log_N+1;
    CBigNum y = CBigNum(1)/nk;

    for(long long i = 0; i < log_N; i++)
    {
        nk = nk - 2;
        if(fd) {
            y = fdivision(CBigNum(1), nk)+xx*y;
        }
        else {
            y = naive ? CBigNum(1).ndivision(CBigNum(nk)) : CBigNum(1)/nk+xx*y;
        }
        y.round(num.getResFracBits()+1);
    }

    // Adding the correction term for the number of divisions we performed
    CBigNum result = x*y*2.0;

    result.round(num.getResFracBits());
    result.setResFracBits(num.getResFracBits());
    return result;
}

/* Trigonometric functions */
long long SINCOS_N_find(const CBigNum& x, bool fd) {
	long long N = 1;
	CBigNum xx = x*x;
    CBigNum Rn;
    if(fd) {
        Rn = fdivision(xx, 2);
    }
    else {
        Rn = xx/2;
    }
	CBigNum epsilon = CBigNum(1) >> (x.getResFracBits()+1);
	while (1) {
		if (abs(Rn) < epsilon) {
			break;
		}
		N += 1;
        if(fd) {
            Rn *= fdivision(xx, 2*N*(2*N-1));
        }
        else {
            Rn *= xx/(2*N*(2*N-1));
        }
	}
	return N;
}
CBigNum SINTNV(const CBigNum& x, bool fd) {
    long long N = SINCOS_N_find(x, fd);
    CBigNum y(1), xx(x*x), tmp, one(1);
	CBigNum k(2*N);
	while (k > 0) {
        if(fd) {
            y = one - fdivision(fdivision(y*xx, k), k+1);
        }
        else {
            y = one - y*xx/k/(k+1);
        }
		k -= 2;
		y.round(x.getResFracBits()+1);
	}
	y *= x;
	y.round(x.getResFracBits());
	return y;
}
CBigNum COSTNV(const CBigNum& x, bool fd) {
    long long N = SINCOS_N_find(x, fd);
    CBigNum y(1), xx(x*x), tmp, one(1);
	CBigNum k(2*N);
	while (k > 0) {
        if(fd) {
            CBigNum tmp = y*fdivision(xx, k);
            tmp.round(x.getResFracBits()+1);
            y = one - fdivision(tmp, k-1);
        }
        else {
            y = one - y*xx/k/(k-1);
        }
		k -= 2;
		y.round(x.getResFracBits()+1);
	}
	y.round(x.getResFracBits());
	return y;
}
// sin
CBigNum sin(const CBigNum& a, bool fd) {
	if (a < 0) {
		return -sin(-a);
	}
	CBigNum rad(a);
	// Scaled to [0, 2pi) first
	rad %= 2*PI;
	// Judge for special value
	if (rad % PI == 0) {
		return CBigNum(0);
	}
	else if (rad == PI_2) {
		return CBigNum(1);
	}
	else if (rad == 3*PI_2) {
		return CBigNum(-1);
	}
	// Scaled to [0, pi/2) then
	pair<CBigNum, CBigNum> intd;
	intd = rad.intDivision(CBigNum(PI_2));
	CBigNum k = intd.first;
	CBigNum x = intd.second;
	// sin(0+x) = sin(x)
	// sin(PI+x) = sin(x)
	if (k == 0 || k == 2) {
        CBigNum ans = SINTNV(x, fd);
		ans = (k==0) ? ans : -ans;
		return ans;
	}
	// sin(PI/2+x) = cos(x)
	// sin(3PI/2+x) = -cos(x)
	else {
        CBigNum ans = COSTNV(x, fd);
		ans = (k==1) ? ans : -ans;
		return ans;
	}
}

// cos
CBigNum cos(const CBigNum& a, bool fd) {
	if (a < 0) {
        return cos(-a, fd);
	}
	CBigNum rad(a);
	// Scaled to [0, 2pi) first
	rad = abs(rad % (2*PI));
	// Judge for special value
	if (rad == 0) {
		return CBigNum(1);
	}
	else if (rad == PI_2 || rad == 3*PI_2) {
		return CBigNum(0);
	}
	else if (rad == PI) {
		return CBigNum(-1);
	}
	// Scaled to [0, pi/2) then
	pair<CBigNum, CBigNum> intd;
	intd = rad.intDivision(CBigNum(PI_2));
	CBigNum k = intd.first;
	CBigNum x = intd.second;
	// cos(0+x) = cos(x)
	// cos(PI+x) = -cos(x)
	if (k == 0 || k == 2) {
        CBigNum ans = COSTNV(x, fd);
		return (k==0) ? ans : -ans;
	}
	// cos(PI/2+x) = -sin(x)
	// cos(3PI/2+x) = sin(x)
	else {
        CBigNum ans = SINTNV(x, fd);
		return (k==1) ? -ans : ans;
	}
}

// tan
CBigNum tan(const CBigNum& a, bool fd) {
	if (cos(a) == 0) {
		throw "Unavailable to compute undefine tan(x).";
	}
    return fd ? fdivision(sin(a, fd), cos(a, fd)) : sin(a, fd)/cos(a, fd);
}

// cot
CBigNum cot(const CBigNum& a, bool fd) {
    if (sin(a, fd) == 0) {
		throw "Unavailable to compute undefine cot(x).";
	}
    return fd ? fdivision(cos(a, fd), sin(a, fd)) : cos(a, fd)/sin(a, fd);
}

/* e^x */
long long EXP_N_find(const CBigNum& x, bool fd) {
	long long n = 1;
    CBigNum one(1);
    one.setResFracBits(x.getResFracBits());
    CBigNum Rn;
    if(fd) {
        Rn = x * fdivision(one, one - x);
    }
    else {
        Rn = x * (one/(one - x));
    }
	CBigNum epsilon = CBigNum(1) >> (x.getResFracBits());
	while (abs(Rn) >= epsilon) {
        if(fd) {
            Rn *= fdivision(x, ++n);
        }
        else {
            Rn *= x/(++n);
        }
		Rn.round(x.getResFracBits()+1);
	}
	return n;
}

CBigNum EXPTNV(const CBigNum& x, bool fd) {
    long long EXP_N = EXP_N_find(x, fd);
    CBigNum y(1.0), one(1);
    one.setResFracBits(x.getResFracBits());
	for(long long k = EXP_N; k > 0; k--) {
        if(fd) {
            y = one + y*fdivision(x, k);
        }
        else {
            y = one + y*x/k;
        }
        y.setResFracBits(x.getResFracBits()+1);
	}
	y.round(x.getResFracBits());
	return y;
}

CBigNum exp(const CBigNum& a, bool fd, bool naive) {
    CBigNum one(1);
    one.setResFracBits(a.getResFracBits());
    if (a == 0) {
        return one;
    }
    else if (a < 0) {
        return fd ? fdivision(one, exp(-a, fd, naive)) : one/exp(-a, fd, naive);
	}
	// Scaled bit number to (0, 10)
    CBigNum x(a);
    if (naive) {
        CBigNum ans = EXPTNV(x, fd);
        ans.round(a.getResFracBits());
        return ans;
    }
    long long k = 0;
	if (x > 10) {
        k = (long long)(x.getInts().size()) - 1;
        x >>= k;
    }
    CBigNum ans = pow(EXPTNV(x, fd), one<<k);
	ans.round(a.getResFracBits()); 
	return ans;
}

// ASin Iteratoin
long long ASIN_N_find(const CBigNum& x, bool fd) {
	long long N = 1;
	CBigNum epsilon = CBigNum(1) >> (x.getResFracBits());
    CBigNum xx = x*x;
    CBigNum one(1);
    CBigNum tmp = fd ? fdivision(one, one-xx) : one/(one-xx);
    CBigNum Rn = fd ? fdivision(tmp, N*2) : tmp/(N*2);
	long long k1, k2;
	k1 = 1; k2 = 2;
	while(1) {
		if(Rn < epsilon) break;
        tmp *= fd ? xx*fdivision(k1, k2) : xx*k1/k2;
        Rn = fd ? fdivision(tmp, 2*N) : tmp/(2*N);
		tmp.round(x.getResFracBits()+1);
		Rn.round(x.getResFracBits()+1);
		k1 += 2;
		k2 += 2;
		N++;
	}
	return N;
}
CBigNum ASINTNV(const CBigNum& x, bool fd) {
  long long N = ASIN_N_find(x, fd);
	CBigNum y(1);
	long long k2 = 2*N;
	long long k1 = k2 - 1;
	CBigNum xx = x*x;
	CBigNum one(1);
	one.setResFracBits(x.getResFracBits());
	for(long long k = N; k >= 1; k--) {
        y = fd ? y*fdivision(xx*k1, k2) + fdivision(one, k1) : y*xx*k1/k2 + one/k1;
		y.round(x.getResFracBits()+1);
		k1 -= 2;
		k2 -= 2;
	}
	y *= x; 
	y.round(x.getResFracBits());
	return y;
}

// arcsin
CBigNum asin(const CBigNum& a, CBigNum PI_Given, bool fd) {
	// Check the given number first
	if(a < -1 || a > 1) {
		throw "Out of the domain of definition when compute asin().";
	}
	if (a < 0) {
        return -asin(-a, PI_Given, fd);
	}
	// Deal with special case
	if (a == 1) {
		return CBigNum(PI_2);
	}
	else if (a == 0) {
		return CBigNum(0);
	}
    // Fetch more precious PI while needed
    if(PI_Given.getFracs().size() >= a.getResFracBits()) {
        PI_Given.round(a.getResFracBits());
    }
	// Shift Simplification
	CBigNum x(a);
    CBigNum y(0), y0(0), x0(0), one(1);
    one.setResFracBits(a.getResFracBits());
	while (x > SINA4) {
        if(PI_Given.getResFracBits() > 17) {
            CBigNum PI_Given_6 = PI_Given / 6;
            x0 = x; y0 += PI_Given_6;
            x = x0*cos(PI_Given_6, fd)-sqrt(one-x0*x0, fd)*sin(PI_Given_6, fd);
        }
        else{
            x0 = x; y0 += PI_6;
            x = x0*COSA3-sqrt(one-x0*x0, fd)*SINA3;
        }
	}
	while (x > SINA3) {
        if(PI_Given.getResFracBits() > 17) {
            CBigNum PI_Given_12 = PI_Given / 12;
            x0 = x; y0 += PI_Given_12;
            x = x0*cos(PI_Given_12, fd)-sqrt(one-x0*x0, fd)*sin(PI_Given_12, fd);
        }
        else{
            x0 = x; y0 += PI_12;
            x = x0*COSA2-sqrt(one-x0*x0, fd)*SINA2;
        }
	}
	while (x > SINA2) {
        if(PI_Given.getResFracBits() > 17) {
            CBigNum PI_Given_24 = PI_Given / 24;
            x0 = x; y0 += PI_Given_24;
            x = x0*cos(PI_Given_24, fd)-sqrt(one-x0*x0, fd)*sin(PI_Given_24, fd);
        }
        else{
            x0 = x; y0 += PI_24;
            x = x0*COSA1-sqrt(one-x0*x0, fd)*SINA1;
        }
	}
    y = ASINTNV(x, fd)+y0;
	y.round(a.getResFracBits());
	return y;
}

// arccos
CBigNum acos(const CBigNum& a, CBigNum PI_Given, bool fd) {
	// Check the given number first
	if(a < -1 || a > 1) {
        throw "Out of the domain of definition when compute acos().";
	}
    CBigNum one(1);
    one.setResFracBits(a.getResFracBits());
    return asin(sqrt(one-(a*a), fd), PI_Given, fd);
}

// ATan Iteratoin
long long ATAN_N_find(const CBigNum& x, bool fd) {
	long long N = 1;
	CBigNum epsilon = CBigNum(x) >> x.getResFracBits();
	CBigNum xx = x*x;
	CBigNum y = xx;
    CBigNum Rn = fd ? fdivision(y, 3) : y/3;
	while(Rn >= epsilon) {
		y *= xx;
        Rn = fd ? fdivision(y, (2*(++N)+1)) : y/(2*(++N)+1);
	}
	return N;
}
CBigNum ATANTNV(const CBigNum& x, bool fd) {
    long long N = ATAN_N_find(x, fd);
	CBigNum xx = x*x;
	long long nk = 2*N - 1;
	CBigNum one(1);
	one.setResFracBits(x.getResFracBits());
    CBigNum y = fd ? fdivision(one, nk+2) : one/(nk+2);
	for(long long k = N; k > 0; k--) {
        y = fd ? fdivision(one, nk) : one/nk - xx*y;
		nk -= 2;
		y.round(x.getResFracBits()+1);
	}
	y *= x;
	y.round(x.getResFracBits());
	return y;
}

// arctan
CBigNum atan(const CBigNum& a, CBigNum PI_Given, bool fd) {
	if (a < 0) {
        return -atan(-a, fd);
	}
	else if (a <= (CBigNum(1) >> 16)) {
		return CBigNum(0);
	}
    CBigNum x(a), y(0), one(1);
    one.setResFracBits(a.getResFracBits());
	long long k = 1;
	while(1) {
		if (x < 0.26) break;
		k <<= 1;
        y = fd ? fdivision(x, one+sqrt(one+x*x, fd)) : x/(one+sqrt(one+x*x, fd));
		y.round(x.getResFracBits()+1);
		x=y;
    }
    if(PI_Given.getFracs().size() >= a.getResFracBits()) {
        PI_Given.round(a.getResFracBits());
        y = (ATANTNV(x, fd)*k)%PI_Given;
    }
    else {
        y = (ATANTNV(x, fd)*k)%PI;
    }
	y.round(x.getResFracBits());
	return y;
}

// arccot
CBigNum acot(const CBigNum& a, CBigNum PI_Given, bool fd) {
	if (a < 0) {
        return -acot(-a, PI_Given, fd);
	}
	CBigNum one(1);
	one.setResFracBits(a.getResFracBits());
    if (a > 0.5) return atan(fd ? fdivision(one, a) : one/a, PI_Given, fd);
    if(PI_Given.getFracs().size() >= a.getResFracBits()) {
        PI_Given.round(a.getResFracBits());
    }
    return -((PI_Given.getResFracBits() > 17 ? PI_Given/2 : PI_2)-atan(a, PI_Given, fd));
}

// Calculate π
CBigNum PI_Calculate(long long bits, bool fd) {
    CBigNum root(10005);
    CBigNum M = 1;
    CBigNum L = 13591409;
    CBigNum X = 1;
    CBigNum pi = 0;

    // Set Precision
    M.setResFracBits(L.getResFracBits()+bits+1);

    CBigNum i(0);
    i.setResFracBits(1);
    CBigNum ten(10);
    ten.setResFracBits(2);
    for(i = 0; i <= bits/14+1; i++) {
        pi += fd ? fdivision(M * L,  X) : (M * L) / X;
        CBigNum i6 = i*6;
        CBigNum i3 = i6/2;
        M *= (i6+1)*(i6+2)*(i6+3)*(i6+4)*(i6+5)*(i6+6);
        M = fd ? fdivision(fdivision(fdivision(M, i3+1), i3+2), i3+3) : M / (i3+1) / (i3+2) / (i3+3);
        M = fd ? fdivision(M, (i+1)*(i+1)*(i+1)) : M / ((i+1)*(i+1)*(i+1));
        L += 545140134;
        X *= -262537412640768000;
    }

    root.setResFracBits(pi.getResFracBits()+1);
    CBigNum C = sqrt(root, fd)*426880;
    C.setResFracBits(M.getResFracBits());
    CBigNum res = fd ? fdivision(C, pi) : C / pi;
    res.round(bits);

    return res;
}

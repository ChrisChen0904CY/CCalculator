#ifndef CBIGNUM_H
#define CBIGNUM_H

#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

using namespace std;

// Display a vector
template <typename T>
void vecDisplay(vector<T> vec) {
	for (auto element:vec) {
		cout << element << " " << endl;
	}
}

// Check the typename
template<typename T>
struct is_supported_type : std::disjunction<
                               std::is_arithmetic<T>,         // int, long, float etc.
                               std::is_same<T, std::string>   // std::string
                               > {};

template<typename T>
constexpr bool is_supported_type_v = is_supported_type<T>::value;

/**
* @Brief: A Big Num Class store data in two vectors
* @Author: Chris Chan
* @Date: 2024/08/19
*/
class CBigNum {

friend ostream& operator<<(ostream& os, const CBigNum& num);
friend ostream& operator<<(ostream& os, const CBigNum* num);
template <typename T>
CBigNum any2BigNum(T value) {
    CBigNum num(value);
    return num;
}

public:
	/**
	* @Breif: Construct & Deconstruct Functions
	* @Author: Chris Chan
	* @Date: 2024/08/19
	*/
	CBigNum();
	// Copy Construction
	CBigNum(const CBigNum& other);
	CBigNum& operator=(const CBigNum& other);
	// Signed Num
	CBigNum(short n) : CBigNum(static_cast<long long int>(n)) {};
	CBigNum(int n) : CBigNum(static_cast<long long int>(n)) {};
	CBigNum(long int n) : CBigNum(static_cast<long long int>(n)) {};
	CBigNum(long long int n);
	CBigNum(float n) : CBigNum(to_string(n)) {};
	CBigNum(double n) : CBigNum(to_string(n)) {};
	CBigNum(long double n) : CBigNum(to_string(n)) {};
	// Unsigned Num
	CBigNum(unsigned short n) : CBigNum(static_cast<unsigned long long int>(n)) {};
	CBigNum(unsigned int n) : CBigNum(static_cast<unsigned long long int>(n)) {};
	CBigNum(unsigned long int n) : CBigNum(static_cast<unsigned long long int>(n)) {};
	CBigNum(unsigned long long int n);
	// String & Vector
	CBigNum(string s);
	CBigNum(vector<char> ints, vector<char> fracs);
	~CBigNum();
	
	/**
	* @Breif: Get & Set functions
	* @Author: Chris Chan
	* @Date: 2024/08/19
	*/
	bool getPositive() const;
	vector<char> getInts() const;
	vector<char> getFracs() const;
	long long getResFracBits() const;
	void setPositive(bool p);
	void setInts(vector<char> newInts);
	void setFracs(vector<char> newFracs);
	
	/**
	* @Breif: Aid functions
	* @Author: Chris Chan
	* @Date: 2024/08/19
	*/
	bool isNum(char c);
	void zeroClear();
	CBigNum getInt() const;
	CBigNum getFrac() const;
	void round(long long bits);
	string to_str() const;
	
	/**
	* @Breif: Compare Operators
	* @Author: Chris Chan
	* @Date: 2024/08/20
	*/
	bool operator>(const CBigNum other) const;
	bool operator<(const CBigNum other) const;
	bool operator==(const CBigNum other) const;
	bool operator!=(const CBigNum other) const;
	bool operator>=(const CBigNum other) const;
	bool operator<=(const CBigNum other) const;
	
	/**
	* @Breif: Compute Operators
	* @Author: Chris Chan
	* @Date: 2024/08/20
	*/
	// Add
	CBigNum operator+(const CBigNum& other) const;
	void operator+=(const CBigNum& other);
	// Minus
	CBigNum operator-() const;
	CBigNum operator-(const CBigNum& other) const;
	void operator-=(const CBigNum& other);
	// Self-Add
	// Prefix ++
  CBigNum& operator++() {
    (*this) += 1;
    return *this;
  }
	// Postfix ++
	CBigNum operator++(int) {
    CBigNum temp = *this;
    (*this) += 1;
    return temp;
  }
  // Self-Minus
	// Prefix --
  CBigNum& operator--() {
    (*this) -= 1;
    return *this;
  }
	// Postfix --
	CBigNum operator--(int) {
    CBigNum temp = *this;
    (*this) -= 1;
    return temp;
  }
	// Move Left
	CBigNum operator<<(const long long& bits) const;
	void operator<<=(const long long& bits);
	// Move Right
	CBigNum operator>>(const long long& bits) const;
	void operator>>=(const long long& bits);
	// Multiply
	CBigNum operator*(const CBigNum& other) const;
	void operator*=(const CBigNum& other);
	// Int Division
	pair<CBigNum, CBigNum> intDivision(const CBigNum& other) const;
	// Division
	CBigNum operator/(const CBigNum& other) const;
	void operator/=(const CBigNum& other);
	void setResFracBits(long long bits);
	// Mod
	CBigNum operator%(const CBigNum& other) const;
	void operator%=(const CBigNum& other);

    // Addition Template
    template <typename T>
    typename std::enable_if<is_supported_type_v<T>, CBigNum>::type operator+(const T& value) {
        CBigNum other = any2BigNum(value);
        return *(this) + other;
    }
    // +=
    template <typename T>
    typename std::enable_if<is_supported_type_v<T>, void>::type operator+=(const T& value) {
        *(this) += any2BigNum(value);
    }

    // Subtraction Template
    template <typename T>
    typename std::enable_if<is_supported_type_v<T>, CBigNum>::type operator-(const T& value) {
        CBigNum other = any2BigNum(value);
        return *(this) - other;
    }
    // -=
    template <typename T>
    typename std::enable_if<is_supported_type_v<T>, void>::type operator-=(const T& value) {
        *(this) -= any2BigNum(value);
    }

    // Multiplication Template
    template <typename T>
    typename std::enable_if<is_supported_type_v<T>, CBigNum>::type operator*(const T& value) {
        CBigNum other = any2BigNum(value);
        return *(this) * other;
    }
    // *=
    template <typename T>
    typename std::enable_if<is_supported_type_v<T>, void>::type operator*=(const T& value) {
        *(this) *= any2BigNum(value);
    }

    // Division Template
    template <typename T>
    typename std::enable_if<is_supported_type_v<T>, CBigNum>::type operator/(const T& value) {
        CBigNum other = any2BigNum(value);
        return *(this) / other;
    }
    // /=
    template <typename T>
    typename std::enable_if<is_supported_type_v<T>, void>::type operator/=(const T& value) {
        *(this) /= any2BigNum(value);
    }

    // Modulo Template
    template <typename T>
    typename std::enable_if<is_supported_type_v<T>, CBigNum>::type operator%(const T& value) {
        CBigNum other = any2BigNum(value);
        return *(this) % other;
    }
    // %=
    template <typename T>
    typename std::enable_if<is_supported_type_v<T>, void>::type operator%=(const T& value) {
        *(this) %= any2BigNum(value);
    }

    /* Compare Template */
    // > & >=
    template <typename T>
    typename std::enable_if<is_supported_type_v<T>, bool>::type operator>(const T& value) {
        CBigNum other = any2BigNum(value);
        return *(this) > other;
    }
    template <typename T>
    typename std::enable_if<is_supported_type_v<T>, bool>::type operator>=(const T& value) {
        CBigNum other = any2BigNum(value);
        return *(this) >= other;
    }
    // < & <=
    template <typename T>
    typename std::enable_if<is_supported_type_v<T>, bool>::type operator<(const T& value) {
        CBigNum other = any2BigNum(value);
        return *(this) < other;
    }
    template <typename T>
    typename std::enable_if<is_supported_type_v<T>, bool>::type operator<=(const T& value) {
        CBigNum other = any2BigNum(value);
        return *(this) <= other;
    }
    // == & !=
    template <typename T>
    typename std::enable_if<is_supported_type_v<T>, bool>::type operator==(const T& value) {
        CBigNum other = any2BigNum(value);
        return *(this) == other;
    }
    template <typename T>
    typename std::enable_if<is_supported_type_v<T>, bool>::type operator!=(const T& value) {
        CBigNum other = any2BigNum(value);
        return *(this) != other;
    }

private:
	/* Main Data Struct */
	bool positive = true;
	vector<char> ints;
	vector<char> fracs;
	// Residual fraction bits
	long long resFracBits = 8;
};

// abs Function
CBigNum abs(const CBigNum& num);

#endif

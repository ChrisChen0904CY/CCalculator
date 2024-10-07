#include "cbignum.h"

/* ====== Aid Functions ====== */
bool CBigNum::isNum(char c) {
	return ('0' <= c && c <= '9');
}

CBigNum abs(const CBigNum& num) {
	if (num.getPositive()) {
		return num;
	}
	return -num;
}

void CBigNum::zeroClear() {
	size_t pos = 0;
	// Eliminate prefix zeros
	for (auto c:this->ints) {
		if (c == '0') {
			pos++;
		}
		else {
			break;
		}
	}
	if (pos > 0) {
		this->ints.erase(this->ints.begin(), this->ints.begin() + pos);
	}
	// If all bits of integer are zero then keep one available
	if (this->ints.empty()) {
		this->ints.push_back('0');
	}
	// Eliminate subfix zeros
	if (!this->fracs.empty()) {
		pos = 0;
        for (long long i = this->fracs.size()-1; i >= 0; i--) {
			if (this->fracs[i] == '0') {
				pos++;
			}
			else {
				break;
			}
		}
		this->fracs.erase(this->fracs.end()-pos, this->fracs.end());
	}
}

CBigNum CBigNum::getInt() const {
	return CBigNum(this->ints, {});
}

CBigNum CBigNum::getFrac() const {
	return CBigNum({}, this->fracs);
}

void CBigNum::round(long long bits) {
	if (this->fracs.size() <= bits) {
		return;
	}
	this->fracs.erase(this->fracs.begin()+bits, this->fracs.end());
    if (this->fracs.size() > bits && this->fracs[bits] >= '5') {
		*(this) += CBigNum(1) >> bits;
	}
	this->setResFracBits(bits);
}

string CBigNum::to_str() const {
	// Zero is the special case
	if (this->ints.empty() && this->fracs.empty()) {
		return "0";
	}
  string s = this->positive ? "" : "-";
  for (auto c:this->ints) {
  	s.push_back(c);
	}
	if (!this->fracs.empty()) {
		s.push_back('.');
	}
	for (auto c:this->fracs) {
  	s.push_back(c);
	}
	return s;
}

/* ====== Construct & Deconstruct Functions ====== */
CBigNum::CBigNum() {
	ints = {};
	fracs = {};
}

// Copy Construction
CBigNum::CBigNum(const CBigNum& other) {
	this->positive = other.positive;
	this->ints = other.ints;
	this->fracs = other.fracs;
	this->resFracBits = other.resFracBits;
}
CBigNum& CBigNum::operator=(const CBigNum& other) {
	this->positive = other.positive;
	this->ints = other.ints;
	this->fracs = other.fracs;
	this->resFracBits = other.resFracBits;
	return *this;
}

// Signed Num
CBigNum::CBigNum(long long int n) {
	// Deal with the symbol
	this->positive = n > 0;
	if (n < 0) {
		n *= -1;
	}
	// Store the int section
	while(n != 0) {
		this->ints.insert(this->ints.begin(), '0'+(n%10));
		n /= 10;
	}
	this->fracs = {};
}

// Unsigned Num
CBigNum::CBigNum(unsigned long long int n) {
	// Deal with the symbol
	this->positive = true;
	// Store the int section
	while(n != 0) {
		this->ints.insert(this->ints.begin(), '0'+(n%10));
		n /= 10;
	}
	this->fracs = {};
}

// String & Vector

CBigNum::CBigNum(string s) {
	// Check the string first
	// Check the first character
	if (s[0] != '+' && s[0] != '-' && s[0] != '.' && !isNum(s[0])) {
		ints = {};
		fracs = {};
		return;
	}
	// Convert scientific mode to normal mode
	size_t pos = s.find_first_of("eE");
	long long moveBits = 0;
	if (pos != std::string::npos) {
    moveBits = std::stoll(s.substr(pos + 1));
    s = s.substr(0, pos);
  }
	// Check the other characters
	bool dotFind = false;
    for (long long i = 1; i < s.size(); i++) {
		if (s[i] == '.') {
			if (!dotFind) {
				dotFind = true;
			}
			else {
				ints = {};
				fracs = {};
				return;
			}
		}
		else if (!isNum(s[i])) {
			ints = {};
			fracs = {};
			return;
		}
	}
	// Deal with the verified string
	dotFind = false;
	for (char c:s) {
		// Dot
		if (c == '.') {
			dotFind = true;
		}
		// Symbol
		else if (c == '+' || c == '-') {
			this->positive = (c=='+');
		}
		// Num Data
		else {
			if (!dotFind) {
				this->ints.push_back(c);
			}
			else {
				this->fracs.push_back(c);
			}
		}
	}
	// Shift when needed
	if (moveBits != 0) {
		(*this) <<= moveBits;
	}
	if (this->fracs.size() > 8) {
		this->resFracBits = this->fracs.size();
	}
	this->zeroClear();
}

CBigNum::CBigNum(vector<char> ints, vector<char> fracs) {
	// Check when copy values from given vector
	for (auto c:ints) {
		if (!isNum(c)) {
			this->ints = {};
			break;
		}
		this->ints.push_back(c);
	}
	for (auto c:fracs) {
		if (!isNum(c)) {
			this->fracs = {};
			break;
		}
		this->fracs.push_back(c);
	}
	if (this->fracs.size() > 8) {
		this->resFracBits = this->fracs.size();
	}
}

CBigNum::~CBigNum() {
	
}

/* ====== Get & Set functions ====== */
bool CBigNum::getPositive() const {
	return this->positive;
}
vector<char> CBigNum::getInts() const {
	return this->ints;
}
vector<char> CBigNum::getFracs() const {
	return this->fracs;
}
long long CBigNum::getResFracBits() const {
  return this->resFracBits;
}
void CBigNum::setPositive(bool p) {
	this->positive = p;
}
void CBigNum::setInts(vector<char> newInts) {
	this->ints = newInts;
}
void CBigNum::setFracs(vector<char> newFracs) {
	this->fracs = newFracs;
}

/* ====== Output ====== */
ostream& operator<<(ostream& os, const CBigNum& num) {
	// Deal with zero
	if (num.getInts().empty() && num.getFracs().empty()) {
		os << 0;
	}
	else {
		os << (num.getPositive() ? "" : "-");
		for (auto c:num.getInts()) {
			os << c;
		}
		if (num.getInts().empty()) {
			os << 0;
		}
		if (!num.getFracs().empty()) {
			os << ".";
			for (auto c:num.getFracs()) {
				os << c;
			}
		}
	}
	return os;
}

ostream& operator<<(ostream& os, const CBigNum* num) {
	// Deal with zero
	if (num->getInts().empty() && num->getFracs().empty()) {
		os << 0;
	}
	else {
		os << (num->getPositive() ? "" : "-");
		for (auto c:num->getInts()) {
			os << c;
		}
		if (!num->getFracs().empty()) {
			os << ".";
			for (auto c:num->getFracs()) {
				os << c;
			}
		}
	}
	return os;
}

/* ====== Compare ====== */
bool CBigNum::operator>(const CBigNum other) const {
	if ((*this) == other) {
		return false;
	}
	return !((*this) < other);
}

bool CBigNum::operator<(const CBigNum other) const {
	// Check the symbol first
	if (this->positive != other.positive) {
		return !this->positive;
	}
	// If the symbols are the same then compare the data
	if (this->ints.size() != other.ints.size()) {
		if (this->positive) {
			return this->ints.size() < other.ints.size();
		}
		else {
			return this->ints.size() > other.ints.size();
		}
	}
	else if (this->ints != other.ints) {
        for (long long i = 0; i < this->ints.size(); i++) {
			if (this->ints[i] != other.ints[i]) {
				return this->positive ? this->ints[i] < other.ints[i] : this->ints[i] > other.ints[i];
			}
		}
	}
	// Compare the fraction part
    for (long long i = 0; i < min(this->fracs.size(), other.fracs.size()); i++) {
		if (this->fracs[i] != other.fracs[i]) {
		  return this->positive ? this->fracs[i] < other.fracs[i] : this->fracs[i] > other.fracs[i];
		}
	}
	if (this->fracs.size() > other.fracs.size()) {
		return !this->positive;
	}
	else if (this->fracs.size() < other.fracs.size()) {
		return this->positive;
	}
	return false;
}

bool CBigNum::operator==(const CBigNum other) const {
	// 0 and 0 don't take care of positive
	if ((this->ints.empty() && other.ints.empty()) && (this->fracs.empty() && other.fracs.empty())) {
		return true;
	}
	return (this->positive == other.positive) && (this->ints == other.ints) && (this->fracs == other.fracs);
}

bool CBigNum::operator!=(const CBigNum other) const {
	return !(*this == other);
}

bool CBigNum::operator>=(const CBigNum other) const {
	return !(*this < other);
}

bool CBigNum::operator<=(const CBigNum other) const {
	return !(*this > other);
}

/* ====== Operating ====== */
// Add
CBigNum CBigNum::operator+(const CBigNum& other) const {
	if (other == 0) {
		return *(this);
	}
	// Same Symbol
	if (this->positive == other.positive) {
		// Prepare two new vectors to construct the answer
		vector<char> newInts, newFracs;
		// Add from tail to head
		// Deal the fractional part first
		long long maxSize = max(this->fracs.size(), other.fracs.size());
		// Carry Flag
		short cy = 0;
		if (maxSize > 0) {
            for(long long i = maxSize-1; i >= 0; i--) {
				// If there exist a blank, then insert to new num directly
				if (i >= this->fracs.size()) {
					newFracs.insert(newFracs.begin(), other.fracs[i]);
				}
				else if (i >= other.fracs.size()) {
					newFracs.insert(newFracs.begin(), this->fracs[i]);
				}
				// Add one by one
				else {
					short tmp = (this->fracs[i]-'0')+(other.fracs[i]-'0')+cy;
					cy = tmp / 10;
					newFracs.insert(newFracs.begin(), '0'+(tmp%10));
				}
			}
		}
		// Deal the integer part with two pointers
		long long i, j;
		i = this->ints.size()-1; j = other.ints.size()-1;
		while (i >= 0 && j >= 0) {
			short tmp = (this->ints[i]-'0')+(other.ints[j]-'0')+cy;
			cy = tmp / 10;
			newInts.insert(newInts.begin(), '0'+(tmp%10));
			// Move on
			i--;
			j--;
		}
		// Deal with the remaining interger section
		// No more numbers remain
		while (i >= 0) {
			short tmp = (this->ints[i]-'0')+cy;
			cy = tmp / 10;
			newInts.insert(newInts.begin(), '0'+(tmp%10));
			// Move on
			i--;
		}
		while (j >= 0) {
			short tmp = (other.ints[j]-'0')+cy;
			cy = tmp / 10;
			newInts.insert(newInts.begin(), '0'+(tmp%10));
			// Move on
			j--;
		}
		if (cy > 0) {
			newInts.insert(newInts.begin(), '0'+cy);
		}
		// Return the answer
		CBigNum res(newInts, newFracs);
		res.setPositive(this->positive);
		// Set the resFracBits
		res.setResFracBits(max(this->resFracBits, other.getResFracBits()));
		res.zeroClear();
		return res;
	}
	// Different symbol called minus operation
	else {
		if (this->positive) {
			return *this-(-other);
		}
		else {
			return other-(-(*this));
		}
	}
}

void CBigNum::operator+=(const CBigNum& other) {
	(*this) = (*this) + other;	
}

// Minus
CBigNum CBigNum::operator-() const {
	CBigNum newNum = *this;
	// Flip the symbol
	newNum.setPositive(!newNum.getPositive());
	return newNum;
}

CBigNum CBigNum::operator-(const CBigNum& other) const {
	if (other == 0) {
		return *(this);
	}
	// Two same number get a zero
	if ((*this) == other) {
		return CBigNum(0);
	}
	// Convert to Add --- (+)-(-) OR (-)-(+)
	if (this->positive != other.positive) {
		if (!this->positive) {
			return -(-(*this)+other);
		}
		else {
			return (-other+(*this));
		}
	}
	// (-)-(-) OR (+)-(+)
	else {
		// (-)-(-) CONVERT TO (+)-(+)
		if (!this->positive) {
			return (-other)+(*this);
		}
		// (+)-(+) --- The normal condition
		else {
			// IF the latter one is bigger
			if (*this < other) {
				return -(other-(*this));
			}
			// Prepare two new vectors to construct the answer
			vector<char> newInts, newFracs;
			// Copy the given number for the operation
			CBigNum num1(*this);
			CBigNum num2(other);
			// Deal the fractional part first
			long long maxSize = max(num1.fracs.size(), num2.fracs.size());
			if (maxSize > 0) {
				// Fill the redundant tail with subfix zero
				if (num1.fracs.size() < maxSize) {
					long long zeros = maxSize - num1.fracs.size();
                    for(long long i = 0; i < zeros; i++) {
						num1.fracs.push_back('0');
					}
				}
				else if (num2.fracs.size() < maxSize) {
					long long zeros = maxSize - num2.fracs.size();
                    for(long long i = 0; i < zeros; i++) {
						num2.fracs.push_back('0');
					}
				}
				// Minus from tail to head --- Deal the FRACTIONAL part first
                for (long long i = maxSize - 1; i >= 0; i--) {
					// Borrow from the previous bit
					if (num1.fracs[i] < num2.fracs[i]) {
						newFracs.insert(newFracs.begin(), 
										char(short(num1.fracs[i]-'0')+10-short(num2.fracs[i]-'0'))+'0');
						if (i != 0) {
							num1.fracs[i-1]--;
						}
						else {
							// Borrow from the integer part
							num1.ints[num1.ints.size()-1]--;
						}
					}
					// Enough big to operate
					else {
						newFracs.insert(newFracs.begin(), 
										char(short(num1.fracs[i]-'0')-short(num2.fracs[i]-'0'))+'0');
					}
				}
			}
			// Deal the integer part then
			maxSize = max(num1.ints.size(), num2.ints.size());
			if (maxSize > 0) {
				// Fill the redundant head with prefix zero
				if (num1.ints.size() < maxSize) {
					long long zeros = maxSize - num1.ints.size();
                    for(long long i = 0; i < zeros; i++) {
						num1.ints.insert(num1.ints.begin(), '0');
					}
				}
				else if (num2.ints.size() < maxSize) {
					long long zeros = maxSize - num2.ints.size();
                    for(long long i = 0; i < zeros; i++) {
						num2.ints.insert(num2.ints.begin(), '0');
					}
				}
				// Minus from tail to head --- Deal the INTEGER part
                for (long long i = maxSize - 1; i >= 0; i--) {
					// Borrow from the previous bit
					if (num1.ints[i] < num2.ints[i]) {
						newInts.insert(newInts.begin(),
									   char(short(num1.ints[i]-'0')+10-short(num2.ints[i]-'0'))+'0');
						num1.ints[i-1]--;
					}
					// Enough big to operate
					else {
						newInts.insert(newInts.begin(), 
									   char(short(num1.ints[i]-'0')-short(num2.ints[i]-'0'))+'0');
					}
				}
			}
			// Return the answer
			CBigNum res(newInts, newFracs);
			res.zeroClear();
			// Set the resFracBits
            res.setResFracBits(max(this->resFracBits, other.getResFracBits()));
			res.zeroClear();
			return res;
		}
	}
}

void CBigNum::operator-=(const CBigNum& other) {
	*this = (*this) - other;
}

// Move Left
CBigNum CBigNum::operator<<(const long long& bits) const {
	if (bits == 0) {
		return *this;
	}
	else if (bits < 0) {
		return (*this) >> (-bits);
	}
	// Copy the given number
	CBigNum res(*this);
    for (long long i = 0; i < bits; i++) {
		if (i >= this->fracs.size()) {
			res.ints.push_back('0');
		}
		else {
			res.ints.push_back(this->fracs[i]);
			// Remove the element in res
			res.fracs.erase(res.fracs.begin(), res.fracs.begin()+1);
		}
	}
	res.zeroClear();
	return res;
}

void CBigNum::operator<<=(const long long& bits) {
	*this = (*this) << bits;
}

// Move Right
CBigNum CBigNum::operator>>(const long long& bits) const {
	if (bits == 0) {
		return *this;
	}
	else if (bits < 0) {
		return (*this) << (-bits);
	}
	// Copy the given number
	CBigNum res(*this);
	// Need to move more than the ints
	if (bits >= this->ints.size()) {
		res.fracs.insert(res.fracs.begin(), res.ints.begin(), res.ints.end());
		res.ints.clear();
		if (bits > this->ints.size()) {
            for (long long i = 0; i < bits-this->ints.size(); i++) {
				res.fracs.insert(res.fracs.begin(), '0');
			}
		}
	}
	else {
		res.fracs.insert(res.fracs.begin(), res.ints.end()-bits, res.ints.end());
		res.ints.erase(res.ints.end()-bits, res.ints.end());
	}
	res.zeroClear();
	return res;
}

void CBigNum::operator>>=(const long long& bits) {
	*this = (*this) >> bits;
}

// Multiply
// The Naive Simulation O(MN) 
CBigNum CBigNum::operator*(const CBigNum& other) const {
	// Deal with the symbol first
	if (!this->positive || !other.positive) {
		if (other.positive) {
			return -(-(*this)*other);
		}
		else if (this->positive) {
			return -((*this)*(-other));
		}
		else {
			return (-(*this))*(-other);
		}
	}
	// Only Deal With (+)*(+)
	// Count the bits of fractional part
	long long fracBits = this->fracs.size() + other.fracs.size();
	// Copy for futher operation
	CBigNum num1(*this); CBigNum num2(other);
	// Move Left to Eliminate the fractional part
	num1 = num1 << this->fracs.size(); 
	num2 = num2 << other.fracs.size();
	CBigNum res;
	// Compute the num1 * i for i from 0 to 9
	vector<CBigNum> num1s = {CBigNum(0)};
	for (auto i = 0; i < 9; i++) {
		num1s.push_back(num1+num1s.back());
	}
	// Compute the multiplication by bits
	long long moveBits = 0;
	for (long long i = num2.ints.size()-1; i >= 0; i--) {
		res += (num1s[num2.ints[i] - '0'] << moveBits);
		moveBits++;
	}
	// Set the resFracBits
	res >>= fracBits;
    res.setResFracBits(max(this->resFracBits, other.getResFracBits()));
  // Push a zero to ints while it's empty
	if (res.getInts().empty()) {
		res.setInts({'0'});
	}
	res.zeroClear();
	// Revert the fractional part
	return res;
}

void CBigNum::operator*=(const CBigNum& other) {
	*this = (*this) * other;
}

// Int Division
pair<CBigNum, CBigNum> CBigNum::intDivision(const CBigNum& other) const {
	// Check whetcher the number is divided by 0
	if (other == CBigNum(0)) {
		throw "Unsupport Operation: Divided by 0.";
		return {};
	}
	// Convert all conditions to (+)//(+)
	bool isPositive = this->positive == other.positive;
	CBigNum res;
	// Integerize
	long long num1FracBits, num2FracBits;
	num1FracBits = this->fracs.size();
	num2FracBits = other.fracs.size();
	CBigNum num1 = abs(*this) << max(num1FracBits, num2FracBits);
	CBigNum num2 = abs(other) << max(num1FracBits, num2FracBits);
	if (num1 < num2) {
		return {res, *(this)};
	}
	// Divsion draft bits
	long long draftBits = num1.getInts().size()-num2.getInts().size();
	// Do Minus by bits
	while (num1 >= num2) {
		// Update the draft bits
		if (num1 < (num2 << draftBits)) {
			draftBits--;
			continue;
		}
		num1 -= num2 << draftBits;
		res += CBigNum(1) << draftBits;
	}
	// Flip the symbol
	if (!isPositive) {
		res = -res;
		num1 = -num1;
	}
	return {res, num1 >> max(num1FracBits, num2FracBits)};
}

// Division
void CBigNum::setResFracBits(long long bits) {
	resFracBits = bits;
}

CBigNum CBigNum::operator/(const CBigNum& other) const {
	// Check whetcher the number is divided by 0
	if (other == CBigNum(0)) {
		throw "Unsupport Operation: Divided by 0.";
		return {};
	}
	pair<CBigNum, CBigNum> intRes = this->intDivision(other);
	CBigNum res, num1;
	res = intRes.first; num1 = intRes.second;
	// Integerize
	long long num1FracBits, num2FracBits;
	num1FracBits = num1.fracs.size();
	num2FracBits = other.fracs.size();
	num1 = abs(num1) << max(num1FracBits, num2FracBits)+1;
    CBigNum num2 = abs(other) << max(num1FracBits, num2FracBits);
	// Compute one more bit to rounding off
	short tmp = 0;
	while (res.fracs.size() <= resFracBits) {
		if (num1 < num2) {
			num1 <<= 1;
			res.fracs.push_back('0'+tmp%10);
			tmp = 0;
		}
		else {
			num1 -= num2;
			tmp++;
		}
	}
	// Rounding off
	if (res.fracs.back() >= '5') {
		res += CBigNum(1) >> (long long)(resFracBits);
	}
	// Flip the sysmbol while needed
	if (res.positive != (this->getPositive() == other.getPositive())) {
		res = -res;
	}
	// Chop the last one
	res.fracs.erase(res.fracs.end()-1);
	// Set the resFracBits
	res.setResFracBits(this->resFracBits);
	// Push a zero to ints while it's empty
	if (res.getInts().empty()) {
		res.setInts({'0'});
	}
	res.zeroClear();
	return res;
}

void CBigNum::operator/=(const CBigNum& other) {
	*this = (*this) / other;
}

// Mod
CBigNum CBigNum::operator%(const CBigNum& other) const {
	return this->intDivision(other).second;
}

void CBigNum::operator%=(const CBigNum& other) {
	*this = (*this) % other;
}

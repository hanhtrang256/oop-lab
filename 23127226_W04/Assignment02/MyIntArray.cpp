#include "MyIntArray.h"
#include <iostream>
#include <algorithm>
#include <sstream>

/**
 * @brief Default constructor for array
 */
myIntArray::myIntArray() : n(0), a(nullptr) {
    std::cout << "myIntArray::myIntArray() default constructor\n";
}

/**
 * @brief Parameterized constructor
 * @param n input size 
 */
myIntArray::myIntArray(int n) : n(n), a(new int[n]) {
    reset(0); 
    std::cout << "myIntArray::myIntArray(int) parameterized constructor\n";
}

/**
 * @brief Parameterized constructor
 * @param n new size
 * @param a new pointer
 * @note perform deep copy
 */
myIntArray::myIntArray(int n, int *a) : n(n), a(new int[n]) {
    for (int i = 0; i < n; ++i) (this->a)[i] = a[i];
    std::cout << "myIntArray::myIntArray(int, int*) parameterized constructor\n";
}

/**
 * @brief Parameterized constructor
 * @param s string. Format: n a0 a1 a2 ... an-1
 */
myIntArray::myIntArray(std::string s) {
    std::stringstream buffer(s);
    buffer >> this->n;
    this->a = new int[n];
    for (int i = 0; i < n; ++i) 
        buffer >> a[i];
}

/**
 * @brief Copy constructor (must specify because has dynamic memory allocated)
 * @param other same-class object to copy
 * @note perform deep copy to create new object for the sake of memory safety
 */
myIntArray::myIntArray(const myIntArray& other) {
    this->n = other.n;
    this->a = new int[n];
    for (int i = 0; i < n; ++i) a[i] = other.a[i];
    std::cout << "myIntArray::myIntArray(const myIntArray&) copy constructor\n";
}

/**
 * @brief Move constructor
 * @param other temporary same-class object
 * @note move all the content of other to current
 * @note set the pointer of other to nullptr
 * @note noexception
 */
myIntArray::myIntArray(myIntArray&& other) noexcept {
    this->n = std::exchange(other.n, 0);
    a = other.a;
    other.a = nullptr;
    std::cout << "myIntArray::myIntArray(myIntArray&&) move constructor\n";
}

/**
 * @brief Destructor
 * @note delete a pointer
 */
myIntArray::~myIntArray() {
    delete a;
    std::cout << "myIntArray::~myIntArray() destructor\n";
}

/**
 * @brief Some basic methods for array
 * @note modify value at index i with value x
 * @note reset array to value x
 * @note input array  
 * @note output array
 * @note toString()
 * @note clone()
 */
void myIntArray::modify(int i, int x) {
    a[i] = x;
}

void myIntArray::reset(int x) {
    for (int i = 0; i < this->n; ++i) 
        a[i] = x;
}

void myIntArray::input() {
    std::cout << "Input n: ";
    std::cin >> n;
    a = new int[n];
    std::cout << "Input a: ";
    for (int i = 0; i < this->n; ++i) 
        std::cin >> a[i];
}

void myIntArray::output() {
	if (a == nullptr) {
		std::cout << "empty";
	}
	else {
    	for (int i = 0; i < this->n; ++i)
        	std::cout << a[i] << " ";
	}
    std::cout << '\n';
}

int myIntArray::getN() { return this->n; }
int* myIntArray::getA() { return this->a; }

std::string myIntArray::toString() {
    std::stringstream buffer;
    std::string ret = "";
    buffer << n;
    ret += buffer.str() + (n > 0 ? " " : "");
    for (int i = 0; i < n; ++i) {
        buffer.clear();
        buffer << a[i];
        ret += buffer.str();
        if (i + 1 < n) ret += " ";
    }
    return ret;
}

myIntArray myIntArray::clone(const myIntArray &other) {
    return myIntArray(other);
}

/**
 * @brief Arithmetic Operators
 */
std::ostream& operator << (std::ostream& out, const myIntArray& other) {
    out << "n = " << other.n << '\n';
    for (int i = 0; i < other.n; ++i) out << other.a[i] << " ";
    out << '\n';
    return out;
}
std::istream& operator >> (std::istream& in, myIntArray& other) {
    std::cout << "Input n: "; 
    in >> other.n;
    other.a = new int[other.n];
    std::cout << "Input a: "; 
    for (int i = 0; i < other.n; ++i) in >> other.a[i];
    return in;
}

myIntArray& myIntArray::operator = (const myIntArray& other) {
    if (this == &other) return *this;
    n = other.n;
    delete a;
    a = new int[n];
    for (int i = 0; i < n; ++i) a[i] = other.a[i];
    return *this;
}
myIntArray myIntArray::operator + (const myIntArray& other) const {
    myIntArray ret(n); 
    for (int i = 0; i < n; ++i) ret.a[i] = a[i] + other.a[i];
    return ret;
}
myIntArray myIntArray::operator + (const int& other) const { // plus other to all number in array
    myIntArray ret(n);
    ret = *this;
    for (int i = 0; i < n; ++i) ret.a[i] += other;
    return ret;
} 
myIntArray operator + (const int& num, const myIntArray& other) { // plus other to all number in array
    myIntArray ret(other.n);
    ret = other;
    for (int i = 0; i < other.n; ++i) ret.a[i] += num;
    return ret;
}

myIntArray& myIntArray::operator += (const myIntArray& other) {
    for (int i = 0; i < n; ++i) a[i] += other.a[i];
    return *this;
}
myIntArray myIntArray::operator - (const myIntArray& other) const {
    myIntArray ret(n); 
    for (int i = 0; i < n; ++i) ret.a[i] = a[i] + other.a[i];
    return ret;
}
myIntArray myIntArray::operator - (const int& other) const {
    myIntArray ret(n);
    ret = *this;
    for (int i = 0; i < n; ++i) ret.a[i] -= other;
    return ret;
}
myIntArray operator - (const int& num, const myIntArray& other) {
    myIntArray ret(other);
    for (int i = 0; i < other.n; ++i) ret.a[i] -= num;
    return ret;
}
myIntArray& myIntArray::operator -= (const myIntArray& other) {
    for (int i = 0; i < n; ++i) a[i] -= other.a[i];
    return *this;
}
myIntArray myIntArray::operator * (const myIntArray& other) const {
    myIntArray ret(n); 
    for (int i = 0; i < n; ++i) ret.a[i] = a[i] * other.a[i];
}
myIntArray myIntArray::operator * (const int& other) const {
    myIntArray ret(*this);
    for (int i = 0; i < n; ++i) ret.a[i] *= other;
    return ret;
}
myIntArray operator * (const int& num, const myIntArray& other) {
    myIntArray ret(other);
    for (int i = 0; i < other.n; ++i) ret.a[i] *= num;
    return ret;
}
myIntArray& myIntArray::operator *= (const myIntArray& other) {
    for (int i = 0; i < n; ++i) a[i] *= other.a[i];
    return *this;
}
myIntArray myIntArray::operator / (const int& other) const {
    if (other == 0) throw "divide by zero"; 
    myIntArray ret(*this); 
    for (int i = 0; i < n; ++i) ret.a[i] /= other; 
    return ret;
}
myIntArray& myIntArray::operator /= (const int& other) {
    if (other == 0) throw "divide by zero";
    for (int i = 0; i < n; ++i) a[i] /= other;
    return *this;
}

/**
 * @brief Relational Operators
 */
bool myIntArray::operator == (const myIntArray& other) const {
    for (int i = 0; i < n; ++i) if (a[i] != other.a[i]) return false;
    return true;
}
bool myIntArray::operator != (const myIntArray& other) const {
    return (*this == other ? false : true);
}
bool myIntArray::operator > (const myIntArray& other) const {
    for (int i = 0; i < n; ++i) if (a[i] < other.a[i]) return false;
    return true;
}
bool myIntArray::operator < (const myIntArray& other) const {
    for (int i = 0; i < n; ++i) if (a[i] > other.a[i]) return false;
    return true;
}

/**
 * @brief Incremental, Decremental operators
 */
myIntArray& myIntArray::operator ++ () { // plus all element by 1
    for (int i = 0; i < n; ++i) ++a[i];
    return *this;
} 
myIntArray myIntArray::operator ++ (int) {
    myIntArray temp = *this;
    for (int i = 0; i < n; ++i) ++a[i];
    return temp;
}
myIntArray& myIntArray::operator -- () { // minus all element by 1
    for (int i = 0; i < n; ++i) --a[i];
    return *this;
}
myIntArray myIntArray::operator -- (int) {
    myIntArray temp = *this;
    for (int i = 0; i < n; ++i) --a[i];
    return temp;
}

/**
 * @brief Casting 
 */
myIntArray::operator int() const {
    return n;
}

/**
 * @brief get index of array operator
 */
int& myIntArray::operator[](int index) const {
    return a[index];
}
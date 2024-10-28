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

#include "Point2D.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>

Point2D::Point2D() {
    this->x = 0.0;
    this->y = 0.0;
    std::cout << "Point2D::Point2D() default constructor\n";
}

Point2D::Point2D(double x) {
    this->x = x;
    y = 0;
    std::cout << "Point2D::Point2D(double x) parameterized constructor\n";
}

Point2D::Point2D(double x, double y) {
    this->x = x;
    this->y = y;
    std::cout << "Point2D::Point2D(double x, double y) parameterized constructor\n";
}

Point2D::Point2D(const Point2D &other) {
    this->x = other.x;
    this->y = other.y;
    std::cout << "Point2D::Point2D(const Point2D &other) copy constructor\n";
}

Point2D::Point2D(std::string s) {
    for (int i = 0; i < (int)s.size(); ++i) 
        if (s[i] == ',' || s[i] == ';') s[i] = ' ';
    std::stringstream buffer(s);
    double x = 0;
    double y = 0;
    buffer >> x >> y;
    this->x = x;
    this->y = y;
    std::cout << "Point2D::Point2D(std::string s) parameterized constructor\n";
}

Point2D::Point2D(Point2D&& other) noexcept : x(std::exchange(other.x, 0)), y(std::exchange(other.y, 0)) {
    std::cout << "Point2D::Point2D(Point2D&&) move constructor\n";
}

Point2D::~Point2D() {
    // do nothing since no dynamic memory allocation
    std::cout << "Point2D::~Point2D() destructor\n";
}

std::string Point2D::toString() {
    std::string ret = "";
    std::ostringstream xx;
    xx << x;
    ret += xx.str();
    std::ostringstream yy;
    yy << y;
    ret += ", ";
    ret += yy.str();
    return ret;
}

Point2D Point2D::clone() {
    Point2D tmp(*this);
    return tmp;
}

void Point2D::setX(double x) {
    this->x = x;
}

void Point2D::setY(double y) {
    this->y = y;
}

double Point2D::getX() {
    return this->x;
}

double Point2D::getY() {
    return this->y;
}

void Point2D::input() {
    std::cout << "Input x: "; 
    std::cin >> x;
    std::cout << "Input y: ";
    std::cin >> y;
}

void Point2D::output() {
    std::cout << "(" << x << ", " << y << ")" << '\n';
}

double Point2D::distToPoint(const Point2D &other) {
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

double Point2D::distToOX() {
    return fabs(y);
}

double Point2D::distToOY() {
    return fabs(x);
}

Point2D& Point2D::operator = (const Point2D& other) {
    this->x = other.x;
    this->y = other.y;
    return *this;
}


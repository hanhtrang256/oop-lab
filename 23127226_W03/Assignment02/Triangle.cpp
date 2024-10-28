#include <iostream>
#include "Triangle.h"
#include "math.h"
using namespace std;

Triangle::Triangle() : A(Point2D()), B(Point2D()), C(Point2D()) {
    std::cout << "Triangle::Triangle() default constructor\n";
}

Triangle::Triangle(const Point2D &A) : A(A) {
    std::cout << "Triangle::Triangle(const Point2D &A) parameterized constructor\n";
}

Triangle::Triangle(const Point2D &A, const Point2D &B) : A(A), B(B) {
    std::cout << "Triangle::Triangle(const Point2D &A, const Point2D &B) parameterized constructor\n";
}

Triangle::Triangle(const Point2D &A, const Point2D &B, const Point2D &C) : A(A), B(B), C(C) {
    std::cout << "Triangle::Triangle(const Point2D &A, const Point2D &B, const Point2D &C) parameterized constructor\n";
}

Triangle::Triangle(const Triangle &other) : A(other.A), B(other.B), C(other.C) {
    std::cout << "Triangle::Triangle(const Triangle &other) copy constructor\n";
}

Triangle::Triangle(Triangle&& other) noexcept : A(std::move(other.A)), B(std::move(other.B)), C(std::move(other.C)) {
    std::cout << "Triangle::Triangle(Triangle&&) move constructor\n";
}

Triangle::~Triangle() {
    std::cout << "~Triangle() destructor\n";
}

/* Write Function For Triangle Structure */
void Triangle::input() {
    cout << "Input point A!!\n";
    A.input();
    cout << "Input point B!!\n";
    B.input();
    cout << "Input point C!!\n";
    C.input();
}

void Triangle::output() {
    cout << "Triangle has 3 point!\n";
    cout << "A"; 
    A.output();
    cout << "B";
    B.output();
    cout << "C";
    C.output();
}

bool Triangle::isValidTriangle() {
    long double AB = A.distToPoint(B);
    long double AC = A.distToPoint(C);
    long double BC = B.distToPoint(C);
    return AB + BC > AC && AB + AC > BC && BC + AC > AB;
}

void Triangle::printType() {
    long double AB = A.distToPoint(B);
    long double AC = A.distToPoint(C);
    long double BC = B.distToPoint(C);
    // (deu: equilateral), (can: isoceles), (3 angle < 90: acute), (1 angle = 90: right), (1 angle > 90: obtuse)
    if (AB == AC || AB == BC || AC == BC) {
        if (AB != AC || AB != BC || AC != BC) {
            if (AB * AB + AC * AC == BC * BC || AB * AB + BC * BC == AC * AC || BC * BC + AC * AC == AB * AB)
                cout << "right ";
            cout << "isosceles triangle\n";
        }
        else cout << "equilateral triangle\n";
        return;
    }

    if (AB * AB + AC * AC == BC * BC || AB * AB + BC * BC == AC * AC || BC * BC + AC * AC == AB * AB) {
        cout << "right triangle\n";
        return;
    }

    if (AB * AB + AC * AC < BC * BC || AB * AB + BC * BC < AC * AC || BC * BC + AC * AC < AB * AB) {
        cout << "obtuse triangle\n";
        return;
    }

    cout << "acute triangle\n";
}

long double Triangle::getPerimeter() {
    long double AB = A.distToPoint(B);
    long double AC = A.distToPoint(C);
    long double BC = B.distToPoint(C);
    return AB + AC + BC;
}

long double Triangle::getArea() {
    long double semiPerimeter = getPerimeter() / 2.0;
    long double AB = A.distToPoint(B);
    long double AC = A.distToPoint(C);
    long double BC = B.distToPoint(C);
    return (long double)sqrt(semiPerimeter * (semiPerimeter - AB) * (semiPerimeter - AC) * (semiPerimeter - BC));
}

Point2D Triangle::getCenter() {
    Point2D res;
    res.setX((A.getX() + B.getX() + C.getX()) / 3.0);
    res.setY((A.getY() + B.getY() + C.getY()) / 3.0);
    return res;
}

std::string Triangle::toString() {
    std::string ret = "";
    ret += A.toString() + " ";
    ret += B.toString() + " ";
    ret += C.toString() + " ";
    return ret;
}

Triangle Triangle::clone() {
    Triangle ret(*this);
    return ret;
}

Triangle& Triangle::operator = (const Triangle& other) {
    this->A = other.A;
    this->B = other.B;
    this->C = other.C;
    return *this;
}
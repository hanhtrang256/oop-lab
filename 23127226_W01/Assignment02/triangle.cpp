#include "triangle.h"
#include <iostream>
#include "math.h"
using namespace std;

/* Write Function For Point Structure */
void Point::input() {
    cout << "x coord of point: ";
    cin >> x;
    cout << "y coord of point: ";
    cin >> y;
}

void Point::output() {
    cout << "(" << x << ", " << y << ")\n";
}

long double Point::distToPoint(const Point &other) {
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

long double Point::distToOX() {
    return y;
}

long double Point::distToOY() {
    return x;
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
    long long semiPerimeter = getPerimeter() / 2.0;
    long double AB = A.distToPoint(B);
    long double AC = A.distToPoint(C);
    long double BC = B.distToPoint(C);
    return sqrt(semiPerimeter * (semiPerimeter - AB) * (semiPerimeter - AC) * (semiPerimeter - BC));
}

Point Triangle::getCenter() {
    Point res;
    res.x = (A.x + B.x + C.x) / 3.0;
    res.y = (A.y + B.y + C.y) / 3.0;
    return res;
}
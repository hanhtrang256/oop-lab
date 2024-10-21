#include "point.h"
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
    return fabs(y);
}

long double Point::distToOY() {
    return fabs(x);
}

long double Point::getX() {
    return x;
}

long double Point::getY() {
    return y;
}

void Point::set(long double a, long double b) {
    x = a;
    y = b;
}
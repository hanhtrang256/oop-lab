#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "point.h"

class Triangle {
private:
    Point A, B, C;
public:
    void input();
    void output();
    bool isValidTriangle();
    void printType();
    long double getPerimeter();
    long double getArea();
    Point getCenter();
};

#endif
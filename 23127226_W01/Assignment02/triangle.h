#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

struct Point {
    long double x, y;
    void input(); 
    void output();
    long double distToPoint(const Point &other);
    long double distToOX(); 
    long double distToOY();
};

struct Triangle {
    Point A, B, C;
    void input();
    void output();
    bool isValidTriangle();
    void printType();
    long double getPerimeter();
    long double getArea();
    Point getCenter();
};

#endif
#ifndef _POINT_H_
#define _POINT_H_

class Point {
private:
    long double x, y;
public:
    void input(); 
    void output();
    long double distToPoint(const Point &other);
    long double distToOX(); 
    long double distToOY();
    long double getX();
    long double getY();
    void set(long double, long double);
};

#endif
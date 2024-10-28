#ifndef _POINT2D_H_
#define _POINT2D_H_

#include <string>

class Point2D {
private:
/** 
     * @brief attributes 
    **/
    double x, y;
public:
    /** 
     * @brief Constructors and destructor 
    **/
    Point2D();                              // Default constructor                  
    Point2D(double x);                      // Parameterized constructor
    Point2D(double x, double y);            // Parameterized constructor
    Point2D(const Point2D &other);          // Copy constructor
    Point2D(std::string s);                 // Parameterized constructor 
    Point2D(Point2D&& other) noexcept;      // Move constructor
    ~Point2D();                             // Destructor
    
    /** 
     * @brief methods 
    **/
    std::string toString();         // change Point2D to string
    Point2D clone();
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    void input();
    void output();
    double distToPoint(const Point2D &other);
    double distToOX(); 
    double distToOY();

    /**
     * @brief assignment operator
    **/
    Point2D& operator = (const Point2D& other);
};

#endif
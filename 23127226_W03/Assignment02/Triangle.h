#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Point2D.h"

class Triangle {
private:
    Point2D A, B, C;
public:
    /**
     * @brief Constructors and destructor
     */
    Triangle();                                                         // Default constructor
    Triangle(const Point2D &A);                                         // Parameterized constructor
    Triangle(const Point2D &A, const Point2D &B);                       // Parameterized constructor 
    Triangle(const Point2D &A, const Point2D &B, const Point2D &C);     // Parameterized constructor
    Triangle(const Triangle& other);                                    // Copy constructor
    Triangle(Triangle&& other) noexcept;                                         // Move constructor
    ~Triangle();                                                        // Destructor

    /**
     * @brief methods
     */
    void input();
    void output();
    bool isValidTriangle();
    void printType();
    long double getPerimeter();
    long double getArea();
    Point2D getCenter();
    std::string toString();
    Triangle clone();

    /**
     * @brief assignment operator
     */
    Triangle& operator = (const Triangle& other);
};

#endif
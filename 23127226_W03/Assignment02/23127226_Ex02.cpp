#include <iostream>
#include <algorithm>
#include <string>
#include "Triangle.h"

int main() {
    // Test triangle constructor
    std::cout << "[Triangle 0]\n";
    Triangle tri0 = Triangle();
    tri0.output();

    std::cout << "[Triangle 1]\n";
    Triangle tri1 = Triangle(Point2D(2, 5));
    tri1.output();

    std::cout << "[Triangle 2]\n";
    Triangle tri2 = Triangle(Point2D(2, 5), Point2D(2, 6));
    tri2.output();

    std::cout << "[Triangle 3]\n";
    Triangle tri3 = Triangle(Point2D(2, 5), Point2D(2, 6), Point2D(5, 6));
    tri3.output();

    std::cout << "[Triangle 4 (copy of 3)]\n";
    Triangle tri4 = Triangle(tri3);
    tri4.output();

    std::cout << "[Triangle 5 (clone of 4)]\n";
    Triangle tri5 = tri4.clone();
    tri5.output();

    std::cout << "[Triangle 6 (move from 1)]\n";
    Triangle tri6 = std::move(tri1);
    std::cout << "Triangle 1: ";
    tri1.output();
    std::cout << "Triangle 6: ";
    tri6.output();

    // Test triangle
    Triangle tri;
    std::cout << "[INPUT TRIANGLE]\n";
    tri.input();
    std::cout << "[OUTPUT TRIANGLE]\n";
    tri.output();
    std::cout << "[IS VALID TRIANGLE]\n";
    std::cout << "valid(): " << tri.isValidTriangle() << '\n';
    if (tri.isValidTriangle() == 1) {
        std::cout << "[TRIANGLE TYPE]\n";
        tri.printType();
        std::cout << "[PERIMETER]\n";
        std::cout << "Perimeter = " << tri.getPerimeter() << '\n';
        std::cout << "[AREA]\n";
        std::cout << "Area = " << tri.getArea() << '\n';
        std::cout << "[CENTER POINT]\n";
        Point2D cent = tri.getCenter(); 
        std::cout << "Center point: ";
        cent.output();
    }
    std::cout << "----[Destructor called]----\n";
    return 0;
}
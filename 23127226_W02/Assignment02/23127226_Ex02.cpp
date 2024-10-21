#include <iostream>
#include <vector>
#include <string>
#include "triangle.h"
using namespace std;

int main() {
    // Test triangle
    Triangle tri;
    cout << "[INPUT TRIANGLE]\n";
    tri.input();
    cout << "[OUTPUT TRIANGLE]\n";
    tri.output();
    cout << "[IS VALID TRIANGLE]\n";
    cout << "valid(): " << tri.isValidTriangle() << '\n';
    if (tri.isValidTriangle() == 1) {
        cout << "[TRIANGLE TYPE]\n";
        tri.printType();
        cout << "[PERIMETER]\n";
        cout << "Perimeter = " << tri.getPerimeter() << '\n';
        cout << "[AREA]\n";
        cout << "Area = " << tri.getArea() << '\n';
        cout << "[CENTER POINT]\n";
        Point cent = tri.getCenter(); 
        cout << "Center point: ";
        cent.output();
    }
    return 0;
}
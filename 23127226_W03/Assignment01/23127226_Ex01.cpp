#include <iostream>
#include <algorithm>
#include <string>
#include "Point2D.h"

int main() {
    std::cout << "[Create obj0]\n";
    Point2D obj0 = Point2D();
    obj0.output();

    std::cout << "[Create obj1]\n";
    Point2D obj1(2);
    obj1.output();
    
    std::cout << "[Create obj2]\n";
    Point2D obj2(5, 6);
    obj2.output();
    
    std::cout << "[Create obj3]\n";
    Point2D obj3(obj2);
    obj3.output();
    
    std::cout << "[Create obj4]\n";
    Point2D obj4("25.5, 6.25");
    obj4.output();

    std::cout << "[Create obj5 (clone from obj4)]\n";
    Point2D obj5 = obj4.clone();
    obj5.output();

    std::cout << "[Create obj6 move from obj1]\n";
    Point2D obj6 = std::move(obj1);
    std::cout << "Obj1: ";
    obj1.output(); 
    std::cout << "Obj6: ";
    obj6.output();
    std::cout << "----[Destructors Called]----\n";
    return 0;
}
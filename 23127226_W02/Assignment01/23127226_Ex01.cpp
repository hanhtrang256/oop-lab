#include <iostream>
#include "fraction.h"
using namespace std;

int main() {
    cout << "[INPUT]\n";
    Fraction a;
    a.input();
    Fraction b;
    b.input();

    cout << "[OUTPUT]\n";
    a.output();
    b.output();

    cout << "[FUNCTION]\n";
    Fraction addRes = a.add(b);
    cout << "add: "; 
    addRes.output();

    Fraction subRes = a.sub(b);
    cout << "sub: "; 
    subRes.output();
    
    Fraction mulRes = a.mul(b);
    cout << "mul: "; 
    mulRes.output();
    
    cout << "divide: ";
    try {
        Fraction diviRes = a.divi(b);
        diviRes.output();
    }
    catch(const char* msg) {
        cout << msg << '\n';
    }
    
    cout << "[CHECK]\n";
    a.reduce();
    cout << "reduce a: "; 
    a.output();

    b.reduce();
    cout << "reduce b: "; 
    b.output();

    cout << "isPositive() of frac a: " << a.isPositive() << '\n';
    cout << "isNegative() of frac a: " << a.isNegative() << '\n';
    cout << "isZero() of frac a: " << a.isZero() << '\n';

    return 0;
}
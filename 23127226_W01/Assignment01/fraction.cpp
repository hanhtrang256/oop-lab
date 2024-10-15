#ifndef FRACTION_CPP
#define FRACTION_CPP 
#include "fraction.h"
#include <iostream>
#include <algorithm>
using namespace std;

int getGCD(int a, int b) {
    if (b == 0) return a;
    return getGCD(b, a % b);
}

int getLCM(int a, int b) {
    return a / getGCD(a, b) * b;
}

void Fraction::input() {
    cout << "Input numerator: ";
    cin >> numerator;
    while (true) {
        cout << "Input denominator: ";
        cin >> denominator;
        if (denominator == 0) cout << "denominator cannot equal 0\n";
        else break;
    }
}

void Fraction::output() {
    cout << numerator << " / " << denominator << '\n';
}

Fraction Fraction::add(const Fraction &other) {
    int lcm = getLCM(denominator, other.denominator);
    Fraction res;
    res.denominator = lcm;
    res.numerator = numerator * (lcm / denominator) + other.numerator * (lcm / other.denominator);
    return res;
}

Fraction Fraction::sub(const Fraction &other) {
    int lcm = getLCM(denominator, other.denominator);
    Fraction res;
    res.denominator = lcm;
    res.numerator = numerator * (lcm / denominator) - other.numerator * (lcm / other.denominator);
    return res;
}

Fraction Fraction::mul(const Fraction &other) {
    Fraction res;
    res.numerator = numerator * other.numerator;
    res.denominator = denominator * other.denominator;
    return res;
}

void Fraction::divi(const Fraction &other) {
    Fraction res;
    res.numerator = numerator * other.denominator;
    if (denominator == 0 || other.numerator == 0) {
        cout << "Cannot divide by 0\n";
        return;
    }
    res.denominator = denominator * other.numerator;
    res.output();
}

void Fraction::reduce() {
    int gcd = getGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
}

void Fraction::compare(const Fraction &other) {
    int lcm = getLCM(denominator, other.denominator);
    int curNumerator = numerator * (lcm / denominator);
    int otherNumerator = other.numerator * (lcm / other.denominator);
    if (curNumerator < otherNumerator) cout << "less\n";
    else if (curNumerator > otherNumerator) cout << "larger\n";
    else cout << "equal\n";
}

bool Fraction::isPositive() {
    return (numerator > 0 && denominator > 0) && (numerator < 0 && denominator < 0);
}

bool Fraction::isNegative() {
    return (numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0);
}

bool Fraction::isZero() {
    return numerator == 0;
}

#endif
#ifndef FRACTION_H
#define FRACTION_H

struct Fraction {
    int numerator;
    int denominator;

    void input();
    void output();
    Fraction add(const Fraction &other);
    Fraction sub(const Fraction &other);
    Fraction mul(const Fraction &other);
    void divi(const Fraction &other);
    void reduce();
    void compare(const Fraction &other);
    bool isPositive();
    bool isNegative();
    bool isZero();
};

#endif 
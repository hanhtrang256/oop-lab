#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int numerator;
    int denominator;

    int getGCD(int, int);
    int getLCM(int, int);

public:
    void input();
    void output();
    Fraction add(const Fraction &other);
    Fraction sub(const Fraction &other);
    Fraction mul(const Fraction &other);
    Fraction divi(const Fraction &other);
    void reduce();
    void compare(const Fraction &other);
    bool isPositive();
    bool isNegative();
    bool isZero();
};

#endif 
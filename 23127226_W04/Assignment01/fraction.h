#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int getGCD(int, int);
    int getLCM(int, int);

public:
    Fraction();
    Fraction(int numerator, int denominator);
    Fraction(const Fraction& other);
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

    /**
     * @brief Arithmetic Operators
     */
    friend ostream& operator << (ostream& out, const Fraction& other);
    Fraction& operator = (const Fraction& other);
    Fraction operator + (const Fraction& other) const;
    Fraction operator + (const int& other) const;
    friend Fraction operator + (const int& num, const Fraction& other);
    Fraction& operator += (const Fraction& other);
    Fraction operator - (const Fraction& other) const;
    Fraction operator - (const int& other) const;
    friend Fraction operator - (const int& num, const Fraction& other);
    Fraction& operator -= (const Fraction& other);
    Fraction operator * (const Fraction& other) const;
    Fraction operator * (const int& other) const;
    friend Fraction operator * (const int& num, const Fraction& other);
    Fraction& operator *= (const Fraction& other);
    Fraction operator / (const Fraction& other) const;
    Fraction operator / (const int& other) const;
    friend Fraction operator / (const int& num, const Fraction& other);
    Fraction& operator /= (const Fraction& other);

    /**
     * @brief Relational Operators
     */
    bool operator == (const Fraction& other) const;
    bool operator != (const Fraction& other) const;
    bool operator >= (const Fraction& other) const;
    bool operator > (const Fraction& other) const;
    bool operator <= (const Fraction& other) const;
    bool operator < (const Fraction& other) const;

    /**
     * @brief Incremental, Decremental operators
     */
    Fraction& operator ++ (); 
    Fraction operator ++ (int); 
    Fraction& operator -- (); 
    Fraction operator -- (int); 
    
    /**
     * @brief Convert to float operator
     */
    operator float() const;
};

#endif // FRACTION_H
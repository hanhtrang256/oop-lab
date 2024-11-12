#include "fraction.h"
#include <iostream>
#include <algorithm>
using namespace std;

int Fraction::getGCD(int a, int b) {
    if (b == 0) return a;
    return getGCD(b, a % b);
}

int Fraction::getLCM(int a, int b) {
    return a / getGCD(a, b) * b;
}

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}

Fraction::Fraction(const Fraction &other)
{
    this->numerator = other.numerator;
    this->denominator = other.denominator;
}

void Fraction::input()
{
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

Fraction Fraction::divi(const Fraction &other) {
    Fraction res;
    res.numerator = numerator * other.denominator;
    if (denominator == 0 || other.numerator == 0) 
        throw "Cannot divide by 0";
    res.denominator = denominator * other.numerator;
    return res;
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
    return (numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0);
}

bool Fraction::isNegative() {
    return (numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0);
}

bool Fraction::isZero() {
    return numerator == 0;
}

Fraction& Fraction::operator=(const Fraction &other)
{
    // TODO: insert return statement here
    if (this == &other) return *this;

    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

Fraction Fraction::operator+(const Fraction &other) const
{
    return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

Fraction Fraction::operator+(const int &other) const
{
    return Fraction(this->numerator + other * this->denominator, this->denominator);
}

Fraction& Fraction::operator+=(const Fraction &other)
{
    // TODO: insert return statement here
    *this = *this + other;
    return *this;
}

Fraction Fraction::operator-(const Fraction &other) const
{
    return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}

Fraction Fraction::operator-(const int &other) const
{
    return Fraction(this->numerator - other * this->denominator, this->denominator);
}

Fraction &Fraction::operator-=(const Fraction &other)
{
    // TODO: insert return statement here
    *this = *this - other;
    return *this;
}

Fraction Fraction::operator*(const Fraction &other) const
{
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::operator*(const int &other) const
{
    return Fraction(numerator * other, denominator);
}

Fraction &Fraction::operator*=(const Fraction &other)
{
    // TODO: insert return statement here
    *this = *this * other;
    return *this;
}

Fraction Fraction::operator/(const Fraction &other) const
{
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

Fraction Fraction::operator/(const int &other) const
{
    return Fraction(numerator, denominator * other);
}

Fraction &Fraction::operator/=(const Fraction &other)
{
    // TODO: insert return statement here
    *this = *this / other;
    return *this;
}

bool Fraction::operator==(const Fraction &other) const
{
    return numerator * other.denominator == denominator * other.numerator;
}

bool Fraction::operator!=(const Fraction &other) const
{
    return numerator * other.denominator != denominator * other.numerator;
}

bool Fraction::operator>=(const Fraction &other) const
{
    return numerator * other.denominator >= other.numerator * denominator;
}

bool Fraction::operator>(const Fraction &other) const
{
    return numerator * other.denominator > other.numerator * denominator;
}

bool Fraction::operator<=(const Fraction &other) const
{
    return numerator * other.denominator <= other.numerator * denominator;
}

bool Fraction::operator<(const Fraction &other) const
{
    return numerator * other.denominator < other.numerator * denominator;
}

// prefix increment
Fraction &Fraction::operator++()
{
    // TODO: insert return statement here
    *this = *this + 1; 
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp = *this + 1;
    *this = *this + 1;
    return temp;
}

Fraction &Fraction::operator--()
{
    // TODO: insert return statement here
    *this = *this - 1; 
    return *this;
}

Fraction Fraction::operator--(int)
{
    // TODO: insert return statement here
    Fraction temp = *this;
    *this = *this - 1; 
    return temp;
}

Fraction::operator float() const
{
    return (float)numerator / (float)denominator;
}

ostream& operator<<(ostream &out, const Fraction &other)
{
    // TODO: insert return statement here
    out << other.numerator << "/" << other.denominator;
    return out;
}

Fraction operator+(const int &num, const Fraction &other)
{
    return other + num;
}

Fraction operator-(const int &num, const Fraction &other)
{
    return other - num;
}

Fraction operator*(const int &num, const Fraction &other)
{
    return other * num;
}

Fraction operator/(const int &num, const Fraction &other)
{
    return Fraction(num * other.denominator, other.numerator);
}

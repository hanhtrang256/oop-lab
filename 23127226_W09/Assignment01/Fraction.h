#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <algorithm>

class Fraction {
private:
    int nume, deno;
    int gcd(int a, int b);
public:
    Fraction();
    Fraction(int nume, int deno);
    Fraction(const Fraction &other);
    bool operator < (const Fraction &other) const;
    bool operator > (const Fraction &other) const;
    bool operator == (const Fraction &other) const;
    bool operator != (const Fraction &other) const;
    friend std::ostream &operator << (std::ostream &out, const Fraction &f);
    static std::string to_string(const Fraction &f);
    void setNume(int nume);
    int getNume() const;
    void setDeno(int deno);
    int getDeno() const;
    void reduce();
};

#endif // FRACTION_H
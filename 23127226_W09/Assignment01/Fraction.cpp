#include "Fraction.h"

int Fraction::gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

Fraction::Fraction() : nume(0), deno(1) {}

Fraction::Fraction(int nume, int deno) : nume(nume) {
    if (deno == 0) throw "divide by 0";
    this->deno = deno;
    this->reduce();
}

Fraction::Fraction(const Fraction &other) : nume(other.nume), deno(other.deno) {}

bool Fraction::operator<(const Fraction &other) const {
    return nume * other.deno < other.nume * deno;
}

bool Fraction::operator>(const Fraction &other) const {
    return nume * other.deno > other.nume * deno;
}

bool Fraction::operator==(const Fraction &other) const {
    return nume * other.deno == other.nume * deno;
}

bool Fraction::operator!=(const Fraction &other) const {
    return !(this->operator==(other));
}

std::string Fraction::to_string(const Fraction &f) {
    return std::to_string(f.nume) + "/" + std::to_string(f.deno);
}

void Fraction::setNume(int nume) { this->nume = nume; }

int Fraction::getNume() const { return nume; }

void Fraction::setDeno(int deno) { this->deno = deno; }
int Fraction::getDeno() const { return deno; }

void Fraction::reduce() {
    int _gcd = gcd(nume, deno);
    nume /= _gcd;
    deno /= _gcd;
}

std::ostream &operator<<(std::ostream &out, const Fraction &f) {
    out << f.nume << "/" << f.deno; 
    return out;
}

#include "BillInc.h"

BillInc::BillInc() : Bill(), rate(0.0f) {}

BillInc::BillInc(const std::string &id, const std::string &name) : Bill(id, name), rate(0.0f) {}

BillInc::BillInc(const std::string &id, const std::string &name, float rate) : Bill(id, name), rate(rate) {}

BillInc::BillInc(const BillInc &other) : Bill(other), rate(other.rate) {}

std::string BillInc::getType() const {
    return "inc";
}

float BillInc::getTotalPrice() const {
    float ret = Bill::getTotalPrice();
    return ret + ret * rate;
}

void BillInc::setRate(float rate) {
    this->rate = rate;
}

float BillInc::getRate() const {
    return rate;
}

void BillInc::input() {
    Bill::input();
    while (true) {
        std::cout << "Rate (from 0 to 1): ";
        std::cin >> rate;
        if (rate >= 0 && rate <= 1) break;
        std::cout << "Rate must be between 0 and 1. Please type again.\n";
    }
}

void BillInc::output() {
    Bill::output();
    std::cout << "Rate: " << rate << '\n';
}
#include "BillSingle.h"

BillSingle::BillSingle() : Bill() {}

BillSingle::BillSingle(const std::string &id, const std::string &name) : Bill(id, name) {}

BillSingle::BillSingle(const BillSingle &other) : Bill(other) {}

std::string BillSingle::getType() const {
    return "single";
}

float BillSingle::getTotalPrice() const {
    return Bill::getTotalPrice();
}

void BillSingle::input() {
    Bill::input();
}

void BillSingle::output() {
    Bill::output();
}

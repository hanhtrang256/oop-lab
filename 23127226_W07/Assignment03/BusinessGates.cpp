#include "BusinessGates.h"

BusinessGates::BusinessGates() : unitPrice(0.0f), quantity(0) {}

BusinessGates::BusinessGates(float unitPrice, int quantity) : unitPrice(unitPrice), quantity(quantity) {}

std::string BusinessGates::getKeeper() const { return "merchant"; }

std::string BusinessGates::getType() const { return "Business"; }

float BusinessGates::getCost() const { return unitPrice * (float)quantity; }

void BusinessGates::input() {
    std::cout << "Unit price: ";
    std::cin >> unitPrice;
    std::cout << "Quantity: ";
    std::cin >> quantity;
}

void BusinessGates::input(const std::string &info) {
    std::stringstream buffer(info);
    std::string type;
    buffer >> type >> unitPrice >> quantity;
}

void BusinessGates::output() const {
    Gates::output();
    std::cout << "Unit price: " << unitPrice << '\n';
    std::cout << "Prince must buy " << quantity << " products to pass!\n";
    std::cout << "Total cost of money: " << getCost() << '\n';
}

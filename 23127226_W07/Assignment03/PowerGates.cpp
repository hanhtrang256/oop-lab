#include "PowerGates.h"

PowerGates::PowerGates() : strength(0.0f) {}

PowerGates::PowerGates(float strength, float reduce) : strength(strength), reduce(reduce) {}

std::string PowerGates::getKeeper() const { return "warrior"; }

std::string PowerGates::getType() const { return "Power"; }

float PowerGates::getCost() const { return reduce; }

float PowerGates::getStrength() const { return strength; }

void PowerGates::input() {
    std::cout << "Required strength level: ";
    std::cin >> strength;
    std::cout << "Reduced strength: ";
    std::cin >> reduce;
}

void PowerGates::input(const std::string &info) {
    std::stringstream buffer(info);
    std::string type;
    buffer >> type >> strength >> reduce;
}

void PowerGates::output() const {
    Gates::output();
    std::cout << "Required strength: " << strength << '\n';
    std::cout << "Reduced strength: " << reduce << '\n';
    std::cout << "Prince must have current strength level equal to or greater than " << strength << " to win!\n";
    std::cout << "After the win, the Prince will lose " << getCost() << " amount of strength!\n";
}

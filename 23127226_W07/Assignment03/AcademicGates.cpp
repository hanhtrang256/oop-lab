#include "AcademicGates.h"

AcademicGates::AcademicGates() : IQ(0.0f){}

AcademicGates::AcademicGates(float IQ) : IQ(IQ) {}

std::string AcademicGates::getKeeper() const { return "sage"; }

std::string AcademicGates::getType() const { return "Academic"; }

float AcademicGates::getCost() const { return IQ; }

void AcademicGates::input() {
    std::cout << "Required IQ: ";
    std::cin >> IQ;
}

void AcademicGates::input(const std::string &info) {
    std::stringstream buffer(info);
    std::string type;
    buffer >> type >> IQ;
}

void AcademicGates::output() const {
    Gates::output();
    std::cout << "Required IQ: " << IQ << '\n';
    std::cout << "Prince's IQ level must be equal or greater than " << IQ << " to answer correctly!\n";
    std::cout << "Total cost of IQ: " << Gates::getCost() << '\n';
}

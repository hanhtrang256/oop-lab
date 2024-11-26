#include "Gates.h"

Gates::Gates() {}

float Gates::getCost() const { return 0.0f; }

void Gates::output() const {
    std::cout << "[" << getType() << " Gate]\n";
    std::cout << "Gatekeeper is a " << getKeeper() << '\n';
}

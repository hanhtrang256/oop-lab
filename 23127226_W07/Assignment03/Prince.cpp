#include "Prince.h"

Prince::Prince() : money(0.0f), IQ(0.0f), strength(0.0f) {}

Prince::Prince(float money, float IQ, float strength) : money(money), IQ(IQ), strength(strength) {}

void Prince::setMoney(float money) { this->money = money; }

float Prince::getMoney() const { return money; }

void Prince::setIQ(float IQ) { this->IQ = IQ; }

float Prince::getIQ() const { return IQ; }

void Prince::setStrength(float strength) { this->strength = strength; }

float Prince::getStrength() const { return strength; }

void Prince::input() {
    std::cout << "[Enter information of the Prince]\n";
    std::cout << "Money: ";
    std::cin >> money;
    std::cout << "IQ: ";
    std::cin >> IQ;
    std::cout << "Strength: ";
    std::cin >> strength;
}

void Prince::output() {
    std::cout << "[Current status of the Prince]\n";
    std::cout << "[Money: " << money << " | IQ: " << IQ << " | Strength: " << strength << "]\n";
}

void Prince::savePrincess(const std::vector<Gates *> &gates) {
    if (gates.empty()) {
        std::cout << "Successfully save the princess!\n";
        output();
        return;
    }

    bool saved = true;
    int index = 0;
    for (int i = 0; i < (int)gates.size(); ++i) {
        std::string type = gates[i]->getType();
        bool pass = false;
        if (type == "Business") {
            float payCost = gates[i]->getCost();
            if (money >= payCost) {
                money -= payCost;
                pass = true;
            }
        }
        else if (type == "Academic") {
            float reqIQ = gates[i]->getCost();
            if (IQ >= reqIQ) pass = true;
        }
        else if (type == "Power") {
            if (PowerGates *castPower = dynamic_cast<PowerGates *>(gates[i])) {
                if (strength >= castPower->getStrength()) {
                    strength -= castPower->getCost();
                    pass = true;
                }
            }
        }
        else {
            std::cout << "Undefined type!!!\n";
            break;
        }
        saved &= pass;
        if (pass) {
            std::cout << "Prince has successfully passed gate " << i + 1 << " [" << type << " Gate]\n";
        }
        else {
            std::cout << "Prince has failed in gate " << i + 1 << " [" << type << " Gate]\n";
            index = i;
            break;
        }
    }

    if (saved) {
        std::cout << "Prince has saved the princess!!!\n";
        output();
    }
    else {
        std::cout << "Prince cannot save the princess!!!\n";
        std::cout << "Remaining gates: \n";
        for (int i = index; i < (int)gates.size(); ++i) 
            gates[i]->output();
    }
}

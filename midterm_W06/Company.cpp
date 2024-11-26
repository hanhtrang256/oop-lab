#include "Company.h"

Company::Company() : bills({}) {}

Company::Company(std::vector<Bill *> bills) : bills(bills) {}

Company::~Company() {
    for (int i = 0; i < (int)bills.size(); ++i)
        delete bills[i];
}

void Company::setBills(const std::vector<Bill *> bills) {
    this->bills = bills;
}

void Company::addBill(Bill *bill) {
    bills.push_back(bill);
}

std::vector<Bill *> Company::getBills() const {
    return bills;
}

void Company::input() {
    std::string type;
    while (true) {
        std::cout << "Enter type of bill (single/inc): ";
        std::cin >> type;
        if (type != "single" && type != "inc") {
            std::cout << "Wrong type of bill! Please type again.\n";
            continue;
        }
        break;
    }
    Bill *bill;
    if (type == "single") bill = new BillSingle();
    else bill = new BillInc();
    bill->input();
    addBill(bill);
}

void Company::output() {
    for (int i = 0; i < (int)bills.size(); ++i)
        bills[i]->output();
}

void Company::output(const std::string &name) {
    bool has = false;
    for (int i = 0; i < (int)bills.size(); ++i) {
        if (bills[i]->getName() == name) {
            bills[i]->output();
            has = true;
        }
    }
    if (!has) {
        std::cout << "No buyer with name = " << name << '\n';
    }
}

int Company::countBillInc() const {
    int ret = 0;
    for (int i = 0; i < (int)bills.size(); ++i) 
        if (bills[i]->getType() == "inc")
            ++ret;
    return ret;
}

float Company::getTotalPrice() const {
    float ret = 0.0f;
    for (int i = 0; i < (int)bills.size(); ++i) 
        ret += bills[i]->getTotalPrice();
    return ret;
}

void Company::sortBill() {
    std::sort(bills.begin(), bills.end(), [](Bill* b1, Bill* b2){
        if (b1->getTotalPrice() != b2->getTotalPrice())
            return b1->getTotalPrice() < b2->getTotalPrice();
        return b1->getName() < b2->getName();
    });
}

#include "BankAccount.h"

BankAccount::BankAccount() : accNum(0), name(""), socialID(""), balance(0.0f) {}

BankAccount::BankAccount(int accNum, std::string name, std::string socialID, float balance) : accNum(accNum), name(name), socialID(socialID), balance(balance) {}

BankAccount::BankAccount(const BankAccount &other) : accNum(other.accNum), name(other.name), socialID(other.socialID), balance(other.balance) {}

void BankAccount::setAccNum(int accNum) { this->accNum = accNum; }

int BankAccount::getAccNum() const { return accNum; }

void BankAccount::setName(std::string name) { this->name = name; }

std::string BankAccount::getName() const { return name; }

void BankAccount::setSocialID(std::string socialID) { this->socialID = socialID; }

std::string BankAccount::getSocialID() const { return socialID; }

void BankAccount::setBalance(float balance) { this->balance = balance; }

float BankAccount::getBalance() const { return balance; }

void BankAccount::input() {
    std::cout << "[Input account information]\n";
    std::cout << "Account number: "; 
    std::cin >> accNum;
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Social ID: ";
    std::cin >> socialID;
    std::cout << "Balance: "; 
    std::cin >> balance;
}

void BankAccount::output() {
    std::cout << "[Output account information]\n";
    std::cout << "Account number: " << accNum << '\n';
    std::cout << "Name: " << name << '\n';
    std::cout << "Social ID: " << socialID << '\n';
    std::cout << "Balance: " << balance << '\n';
}

void BankAccount::deposit(int money) { this->balance += money; }

void BankAccount::withdraw(int money) {
    if (balance - money < 50000) {
        std::cout << "Balance after withdrawing should be >= 50000 VND\n";
        return;
    }
    balance -= money;
}

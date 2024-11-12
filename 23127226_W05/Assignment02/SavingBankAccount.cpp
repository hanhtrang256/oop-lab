#include "SavingBankAccount.h"

SavingBankAccount::SavingBankAccount() : BankAccount(), interestRate(0.0f),  period(period), numSave(numSave) {}

SavingBankAccount::SavingBankAccount(int accNum, std::string name, std::string socialID, int balance, float interestRate, int period, int numSave) : 
BankAccount(accNum, name, socialID, balance), interestRate(interestRate), period(period), numSave(numSave) {}

SavingBankAccount::SavingBankAccount(const SavingBankAccount &other) : BankAccount(other.getAccNum(), other.getName(), other.getSocialID(), other.getBalance()), interestRate(other.interestRate), period(other.period), numSave(other.numSave) {}

void SavingBankAccount::setInterestRate(float interestRate) { this->interestRate = interestRate; }

float SavingBankAccount::getInterestRate() const { return interestRate; }

void SavingBankAccount::setPeriod(int period) { this->period = period; }

int SavingBankAccount::getPeriod() const { return period; }

void SavingBankAccount::setNumSave(int numSave) { this->numSave = numSave; }

int SavingBankAccount::getNumSave() const { return numSave; }

void SavingBankAccount::deposit(int money) {
    if (numSave < period) {
        std::cout << "Cannot deposit since numSave(" << numSave << ") is < than period(" << period << ")\n";
        std::cout << "Create a new saving account to store new amount of money\n";
        return;
    }
    BankAccount::deposit(money);
}

void SavingBankAccount::withdraw(int money) {
    if (numSave < period) {
        std::cout << "Cannot withdraw since numSave(" << numSave << ") is < than period(" << period << ")\n";
        return;
    }
    BankAccount::withdraw(money);
}

float SavingBankAccount::getBalance() const {
    return BankAccount::getBalance() * (1.0 + interestRate / 12.0 * (float)period);
}

void SavingBankAccount::withdrawNow(int money) {
    BankAccount::withdraw(money);
    std::cout << "Your account is now free-period with interest rate = 2%\n";
    interestRate = 0.02f;
    period = 0;
}

void SavingBankAccount::input() {
    BankAccount::input();
    std::cout << "Interest rate: "; 
    std::cin >> interestRate;
    std::cout << "Period: ";
    std::cin >> period;
    std::cout << "Number of save months: ";
    std::cin >> numSave;
}

void SavingBankAccount::output() {
    BankAccount::output();
    std::cout << "Interest rate: " << interestRate << '\n';
    std::cout << "Period: " << period << '\n';
    std::cout << "Number of save months: " << numSave << '\n';
}

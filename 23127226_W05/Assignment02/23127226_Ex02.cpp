#include "BankAccount.h"
#include "SavingBankAccount.h"

int main() {
    BankAccount *acc = new SavingBankAccount(); 
    acc->input();
    acc->output();
    acc->deposit(100000);
    acc->withdraw(50000); 
    static_cast<SavingBankAccount *>(acc)->withdrawNow(10000);
    std::cout << "Current balance: " << static_cast<SavingBankAccount *>(acc)->getBalance() << '\n';
    std::cout << "Current interest: " << static_cast<SavingBankAccount *>(acc)->getInterestRate() << '\n'; 
    delete acc;
    return 0;
}
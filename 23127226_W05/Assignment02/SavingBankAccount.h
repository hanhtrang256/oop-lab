#ifndef SAVING_BANK_ACCOUNT_H
#define SAVING_BANK_ACCOUNT_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "BankAccount.h"

class SavingBankAccount : public BankAccount {
private:
    float interestRate;
    int period;
    int numSave;
public:
    /**
     * @brief Default constructor
     */
    SavingBankAccount(); 

    /**
     * @brief Parameterized constructor
     */
    SavingBankAccount(int accNum, std::string name, std::string socialID, int balance, float interestRate, int period, int numSave);

    /**
     * @brief Copy constructor
     */
    SavingBankAccount(const SavingBankAccount &other);

    /**
     * @brief Set interest rate
     * @param interestRate new interest rate
     */
    void setInterestRate(float interestRate);
    
    /**
     * @brief Get interest rate
     * @note This function doesn't change any attributes
     */
    float getInterestRate() const;

    /**
     * @brief Set period
     * @param period new period
     */
    void setPeriod(int period);
    
    /**
     * @brief Get period
     * @note This function doesn't change any attributes
     */
    int getPeriod() const;

    /**
     * @brief Set amount of save months
     * @param numSave new number of months saved
     */
    void setNumSave(int numSave);
    
    /**
     * @brief Get number of save months
     * @note This function doesn't change any attributes
     */
    int getNumSave() const;

    /**
     * @brief Deposit an amount of money
     * @note This function is override
     */
    void deposit(int money) override;

    /**
     * @brief Withdraw an amount of money
     * @note This function is override
     */
    void withdraw(int money) override;

    /**
     * @brief Get current balance (adding amount of interest)
     * @note This function is override
     */
    float getBalance() const override;

    /**
     * @brief Withdraw immediately
     * @note Interest rate is then 2%
     * @note The account is considered as free-period one
     */
    void withdrawNow(int money);

    /**
     * @brief Input
     * @note This function is override
     */
    void input() override;

    /**
     * @brief Output
     * @note This function is override
     */
    void output() override;
};

#endif // SAVING_BANK_ACCOUNT_H
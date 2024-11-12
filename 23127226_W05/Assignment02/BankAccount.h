#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class BankAccount {
private:
    int accNum;
    std::string name;
    std::string socialID;
    float balance;
public:
    /**
     * @brief Default constructor
     */
    BankAccount(); 

    /**
     * @brief Parameterized constructor
     */
    BankAccount(int accNum, std::string name, std::string socialID, float balance);

    /**
     * @brief Copy constructor
     */
    BankAccount(const BankAccount &other);

    /**
     * @brief Set new account number
     */
    void setAccNum(int accNum);

    /**
     * @brief Get account number
     */
    int getAccNum() const;


    /**
     * @brief Set new name
     */
    void setName(std::string name);

    /**
     * @brief Get name
     */
    std::string getName() const;

    /**
     * @brief Set new social id
     */
    void setSocialID(std::string socialID);

    /**
     * @brief Get social id
     */
    std::string getSocialID() const;

    /**
     * @brief Set new balance
     */
    void setBalance(float balance);

    /**
     * @brief Get balance
     */
    virtual float getBalance() const;

    /**
     * @brief Input
     */
    virtual void input();

    /**
     * @brief Output
     */
    virtual void output();

    /**
     * @brief Deposit an amount of money
     * @note This function can be overrided
     */
    virtual void deposit(int money);

    /**
     * @brief Withdraw an amount of money
     * @note This function can be overrided
     */
    virtual void withdraw(int money);
};

#endif // BANK_ACCOUNT_H
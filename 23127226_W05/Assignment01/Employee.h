#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Employee {
private:
    std::string id, fullName, hireDate, address;
public:
    /**
     * @brief Default constructor
     * @note All default to empty string
     */
    Employee();

    /**
     * @brief Parameterized constructor all employee's information saved into string info
     */
    Employee(std::string info);

    /**
     * @brief Full-parameterized constructor
     */
    Employee(std::string id, std::string fullName, std::string hireDate, std::string address);

    /**
     * @brief Copy constructor
     */
    Employee(const Employee &other);

    /**
     * @brief Move constructor
     */
    Employee(Employee&& other) noexcept;

    /**
     * @brief Input information of an employee
     */
    virtual void input(); 

    /**
     * @brief Output information of an employee
     */
    virtual void output() const;

    /**
     * @brief Get salaray of employee in a month
     * @note This is a pure virtual function
     */
    virtual double getSalary() const = 0;

    /**
     * @brief Set id 
     */
    void setID(const std::string &id);

    /**
     * @brief Get id 
     */
    std::string getID() const;

    /**
     * @brief Set full name 
     */
    void setFullName(const std::string &fullName);

    /**
     * @brief Get full name
     */
    std::string getFullName() const;

    /**
     * @brief Set hire date
     */
    void setHireDate(const std::string &hireDate);

    /**
     * @brief Get hireDate
     */
    std::string getHireDate() const;

    /**
     * @brief Set address
     */
    void setAddress(const std::string &address);

    /**
     * @brief Get address
     */
    std::string getAddress() const;
};

#endif
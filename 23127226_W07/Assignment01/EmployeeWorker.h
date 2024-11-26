#ifndef EMPLOYEE_WORKER_H
#define EMPLOYEE_WORKER_H

#include <iostream>
#include <string>
#include "Employee.h"

class EmployeeWorker : public Employee {
private:
    int item;
    double payRate;
public:
    /**
     * @brief Default constructor
     * @note All default to empty string
     */
    EmployeeWorker();

    /**
     * @brief Parameterized constructor all employee's information saved into string info
     */
    EmployeeWorker(std::string info);

    /**
     * @brief Full-parameterized constructors
     */
    EmployeeWorker(std::string id, std::string fullName, std::string hireDate, std::string address, int workDay, double payRate);

    /**
     * @brief Copy constructor
     */
    EmployeeWorker(const EmployeeWorker &other);

    /**
     * @brief Move constructor
     */
    EmployeeWorker(EmployeeWorker&& other) noexcept;

    /**
     * @brief Input information of an employee
     */
    void input() override;

    /**
     * @brief Output information of an employee
     */
    void output() const override;

    /**
     * @brief Get salary of office employee
     */
    double getSalary() const override;

    std::string getType() const override;
};

#endif 
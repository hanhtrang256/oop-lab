#ifndef EMPLOYEE_OFFICE_H
#define EMPLOYEE_OFFICE_H

#include "Employee.h"

class EmployeeOffice : public Employee {
private:
    int workDay;
    double payRate; // per day
public:
    /**
     * @brief Default constructor
     * @note All default to empty string
     */
    EmployeeOffice();

    /**
     * @brief Parameterized constructor all employee's information saved into string info
     */
    EmployeeOffice(std::string info);

    /**
     * @brief Full-parameterized constructors
     */
    EmployeeOffice(std::string id, std::string fullName, std::string hireDate, std::string address, int workDay, double payRate);

    /**
     * @brief Copy constructor
     */
    EmployeeOffice(const EmployeeOffice &other);

    /**
     * @brief Move constructor
     */
    EmployeeOffice(EmployeeOffice&& other) noexcept;

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
};

#endif
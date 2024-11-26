#ifndef COMPANY_H
#define COMPANY_H

#include "Employee.h"
#include "EmployeeOffice.h"
#include "EmployeeWorker.h"

class Company {
private:
    std::vector<Employee *> employees;
public:
    Company();
    Company(const std::vector<Employee *> &employees);
    ~Company();
    void input();
    void output(bool onlyLargest) const;
    double totalSalary() const;
};

#endif // COMPANY_H
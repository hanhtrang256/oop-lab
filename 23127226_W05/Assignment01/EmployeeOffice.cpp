#include "EmployeeOffice.h"

EmployeeOffice::EmployeeOffice() : Employee(), workDay(0), payRate(0.0) {}

EmployeeOffice::EmployeeOffice(std::string info) {
    std::stringstream buffer(info);
    std::string id, fullName, hireDate, address;
    buffer >> id >> fullName >> hireDate >> address >> this->workDay >> this->payRate;
    setID(id); 
    setFullName(fullName);
    setHireDate(hireDate);
    setAddress(address);
}

EmployeeOffice::EmployeeOffice(std::string id, std::string fullName, std::string hireDate, std::string address, int workDay, double payRate)
                              : Employee(id, fullName, hireDate, address), workDay(workDay), payRate(payRate) {}

EmployeeOffice::EmployeeOffice(const EmployeeOffice &other) : EmployeeOffice(other.getID(), other.getFullName(), other.getHireDate(), 
                                                              other.getAddress(), other.workDay, other.payRate) {}
                                                              

EmployeeOffice::EmployeeOffice(EmployeeOffice &&other) noexcept : Employee(std::move(other)), workDay(std::__exchange(other.workDay, 0)),
                                                                  payRate(std::__exchange(other.payRate, 0)) {}

double EmployeeOffice::getSalary() const {
    return (double)workDay * payRate;
}

void EmployeeOffice::input() {
    Employee::input();
    std::cout << "Work day: ";
    std::cin >> workDay;
    std::cout << "Pay rate: ";
    std::cin >> payRate;
}

void EmployeeOffice::output() const {
    Employee::output();
    std::cout << "Work day: " << workDay << '\n';
    std::cout << "Pay rate: " << payRate << '\n';
}
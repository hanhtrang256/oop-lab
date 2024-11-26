#include "EmployeeWorker.h"

EmployeeWorker::EmployeeWorker() : Employee(), item(0), payRate(0.0) {}

EmployeeWorker::EmployeeWorker(std::string info) {
    std::stringstream buffer(info);
    std::string id, fullName, hireDate, address;
    buffer >> id >> fullName >> hireDate >> address >> this->item >> this->payRate;
    setID(id); 
    setFullName(fullName);
    setHireDate(hireDate);
    setAddress(address);
}

EmployeeWorker::EmployeeWorker(std::string id, std::string fullName, std::string hireDate, std::string address, int item, double payRate)
                              : Employee(id, fullName, hireDate, address), item(item), payRate(payRate) {}

EmployeeWorker::EmployeeWorker(const EmployeeWorker &other) : EmployeeWorker(other.getID(), other.getFullName(), other.getHireDate(), 
                                                              other.getAddress(), other.item, other.payRate) {}
                                                              

EmployeeWorker::EmployeeWorker(EmployeeWorker &&other) noexcept : Employee(std::move(other)), item(std::__exchange(other.item, 0)),
                                                                  payRate(std::__exchange(other.payRate, 0)) {}

void EmployeeWorker::input() {
    Employee::input();
    std::cout << "Number of items: ";
    std::cin >> item;
    std::cout << "Pay rate: ";
    std::cin >> payRate;
}

void EmployeeWorker::output() const {
    Employee::output();
    std::cout << "Number of items: " << item << ", ";
    std::cout << "Pay rate: " << payRate << "}\n";
}

double EmployeeWorker::getSalary() const {
    return (double)item * payRate;
}

std::string EmployeeWorker::getType() const { return "worker"; }
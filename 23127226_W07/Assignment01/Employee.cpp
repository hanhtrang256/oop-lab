#include "Employee.h"

Employee::Employee() : id(""), fullName(""), hireDate(""), address("") {}

Employee::Employee(std::string info) {
    std::stringstream buffer(info);
    buffer >> id >> fullName >> hireDate >> address;
}

Employee::Employee(std::string id, std::string fullName, std::string hireDate, std::string address) : id(id), fullName(fullName), 
                                                                                                      hireDate(hireDate), address(address) {}

Employee::Employee(const Employee &other) : id(other.id), fullName(other.fullName), hireDate(other.hireDate), address(other.address) {}

Employee::Employee(Employee &&other) noexcept {
    id = std::move(other.id);
    fullName = std::move(other.fullName);
    hireDate = std::move(other.hireDate); 
    address = std::move(other.address);
}

void Employee::input() {
    std::cout << "ID: "; 
    std::cin >> id;
    std::cout << "Full name: "; 
    std::cin >> fullName;
    std::cout << "Hire date: ";
    std::cin >> hireDate;
    std::cout << "Address: ";
    std::cin >> address;
}

void Employee::output() const {
    std::cout << "{ID: " << id << ", ";
    std::cout << "Full name: " << fullName << ", ";
    std::cout << "Hire date: " << hireDate << ", ";
    std::cout << "Address: " << address << ", ";
    std::cout << "Salary: " << getSalary() << ", ";
}

void Employee::setID(const std::string &id) { this->id=id; }

std::string Employee::getID() const { return id; }

void Employee::setFullName(const std::string &fullName) { this->fullName = fullName; }

std::string Employee::getFullName() const { return fullName; }

void Employee::setHireDate(const std::string &hireDate) { this->hireDate = hireDate; }

std::string Employee::getHireDate() const { return hireDate; }

void Employee::setAddress(const std::string &address) { this->address = address; }

std::string Employee::getAddress() const { return address; }

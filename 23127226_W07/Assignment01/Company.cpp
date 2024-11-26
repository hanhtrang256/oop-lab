#include "Company.h"

Company::Company() : employees({}) {}

Company::Company(const std::vector<Employee *> &employees) : employees(employees) {}

Company::~Company() {
    for (auto &employee : employees)
        delete employee;
}

void Company::input() {
    std::cout << "Number of employees: ";
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string type, id, fullName, hireDate, address;
        Employee *employee = nullptr;
        std::cout << "[Input employee " << i + 1 << "]\n";
        std::cout << "Type of employee: ";
        while (true) {
            std::cin >> type;
            for (char &c : type) c = tolower(c);
            if (type != "office" && type != "worker") {
                std::cout << "Wrong type. Please type again!!!\n";
                continue;
            }
            break;
        }
        if (type == "office") employee = new EmployeeOffice();
        else employee = new EmployeeWorker();
        employee->input();
        if (employee != nullptr)
            employees.push_back(employee);
        else 
            std::cout << "Null employee found!!!\n";
    }
}

void Company::output(bool onlyLargest) const {
    double maxx = 0.0;
    if (!onlyLargest) {
        for (int i = 0; i < (int)employees.size(); ++i) {
            std::cout << i + 1 << ". "; 
            employees[i]->output();
        }
    }
    else {
        for (int i = 0; i < (int)employees.size(); ++i) maxx = std::max(maxx, employees[i]->getSalary());
        std::cout << "Max salary: " << maxx << '\n';
        int id = 0;
        for (int i = 0; i < (int)employees.size(); ++i) {
            if (employees[i]->getSalary() == maxx) {
                std::cout << ++id << ". ";
                employees[i]->output();
            }
        }
    }
}

double Company::totalSalary() const
{
    double ret = 0.0;
    for (int i = 0; i < (int)employees.size(); ++i)
        ret += employees[i]->getSalary();
    return ret;
}

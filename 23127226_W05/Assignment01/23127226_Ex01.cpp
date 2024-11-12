#include "Employee.h"
#include "EmployeeOffice.h"
#include "EmployeeWorker.h"

int main() {
    std::cout << "[EMPLOYEE 1 (already filled)]\n";
    Employee* employee1 = new EmployeeOffice("FAECIU23030", "Duong Trang", "25/6/24", "hcmiu", 10, 5.0);
    employee1->output();
    delete employee1;

    std::cout << "\n[EMPLOYEE 2 (already filled)]\n";
    Employee* employee2 = new EmployeeWorker("23127226", "Nguyen Dang Minh", "6/11/24", "hcmus", 26, 5.0);
    employee2->output();
    delete employee2;

    std::cout << "\n[EMPLOYEE 3 (input)]\n";
    std::cout << "Input type of employee: ";
    std::string type; 
    std::cin >> type;
    Employee* employee3;
    if (type == "office") {
        employee3 = new EmployeeOffice();
        employee3->input();
    }
    else {
        employee3 = new EmployeeWorker();
        employee3->input();
    }
    employee3->output();
    return 0;
}
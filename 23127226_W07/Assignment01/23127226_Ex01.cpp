#include "Employee.h"
#include "EmployeeOffice.h"
#include "EmployeeWorker.h"
#include "Company.h"

void printOpt() {
    std::cout << "   ------------- [COMPANY ABC MANAGEMENT] -------------   \n";
    std::cout << "1. Enter information of employess                         \n";
    std::cout << "2. Print information of all employess                     \n";
    std::cout << "3. Print total salary of company to pay                   \n";
    std::cout << "4. Print information of all employess with highest salary \n";
    std::cout << "5. Exit                                                   \n";
}

int main() {
    bool programLoop = true;
    Company company;
    while (programLoop) {
        printOpt();
        std::cout << "Enter opt: ";
        int opt;
        while (true) {
            std::cin >> opt;
            if (opt < 1 || opt > 5) {
                std::cout << "Invalid option. Please type again!!!\n";
                continue;
            }
            break;
        }
        if (opt == 1) {
            company.input();
        }
        else if (opt == 2) {
            company.output(false);
        }
        else if (opt == 3) {
            std::cout << "Total salary company has to pay: ";
            std::cout << company.totalSalary() << '\n';
        }
        else if (opt == 4) {
            company.output(true);
        }
        else if (opt == 5) {
            programLoop = false;
        }
    }
    return 0;
}
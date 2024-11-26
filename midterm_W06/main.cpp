#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "Company.h"

void printOpt() {
    std::cout << "1. Input a bill\n";
    std::cout << "2. Print all bills\n";
    std::cout << "3. Print all bills with specific buyer's name\n";
    std::cout << "4. Sort all bills\n";
    std::cout << "5. Calculate total price\n";
    std::cout << "6. Count number of inc-type bill\n";
    std::cout << "7. Exit\n";
}

int main() {
    Company company;
    bool programLoop = true;
    while (programLoop) {
        printOpt();

        int opt;
        while (true) {
            std::cout << "Enter opt: "; 
            std::cin >> opt;
            if (opt < 1 || opt > 7) {
                std::cout << "Invalid! Type again\n";
                continue;
            }
            break;
        }

        std::string name;
        switch(opt) {
            case 1:
                company.input();
                break;
            case 2:
                company.output();
                break;
            case 3:
                std::cout << "Buyer's name: ";
                std::cin >> name;
                company.output(name);
                break;
            case 4:
                company.sortBill();
                break;
            case 5:
                std::cout << "Total price: " << company.getTotalPrice() << '\n';
                break;
            case 6:
                std::cout << "Number of inc-type bill: " << company.countBillInc() << '\n';
                break;
            case 7:
                programLoop = false;
                break;
            default:
                break;
        }
        std::cout << "----------------------------\n";
    }   
    return 0;
}
#ifndef COMPANY_H
#define COMPANY_H

#include "Bill.h"
#include "BillSingle.h"
#include "BillInc.h"
#include <algorithm>

class Company {
private:
    std::vector<Bill *> bills;
public:
    // Default constructor
    Company();

    // Parameterized constructor
    Company(std::vector<Bill *> bills); 

    // Destructor to delete allocated memory (Bill)
    ~Company();

    // Set the set of bills for company
    void setBills(const std::vector<Bill *> bills); 

    // Add a bill
    void addBill(Bill* bill);

    // Get all the bills
    std::vector<Bill *> getBills() const;

    // Enter a bill information and add it
    void input(); 

    // Print information of all bills
    void output(); 

    // Print information of all bills with buyer's name = name
    void output(const std::string &name);

    // Count number of inc-type bill
    int countBillInc() const;

    // Calculate total price of all bills
    float getTotalPrice() const;

    // Sort bills based on total price. If same total price, sort based on buyer's name.
    void sortBill();
};

#endif 
#ifndef BILL_SINGLE_H
#define BILL_SINGLE_H

#include "Bill.h"

class BillSingle : public Bill {
private:

public:
    // Default constructor
    BillSingle();

    // Parameterized constructor
    BillSingle(const std::string &id, const std::string &name);

    // Copy constructor
    BillSingle(const BillSingle &other);

    // getType() override function from Bill. Return "single"
    std::string getType() const override;

    // Same calculation as the Base class: Bill
    float getTotalPrice() const override;

    // Input single-type bill. Same implementation as the Base class
    void input() override;

    // Output single-type bill. Same implementation as the Base class
    void output() override;
};

#endif 
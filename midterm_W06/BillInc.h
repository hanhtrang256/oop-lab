#ifndef BILL_INC_H
#define BILL_INC_H

#include "Bill.h"

class BillInc : public Bill {
private:
    float rate;
public:
    // Default constructor
    BillInc();

    // Parameterized constructor without rate
    BillInc(const std::string &id, const std::string &name);

    // Parameterized constructor with rate
    BillInc(const std::string &id, const std::string &name, float rate);

    // Copy constructor
    BillInc(const BillInc &other);

    // getType() override function from Bill. Return "inc"
    std::string getType() const override;

    // calculate total price with rate
    float getTotalPrice() const override;

    // Input information including rate
    void input() override;

    // Output information including rate
    void output() override;

    // Set the rate for the bill
    void setRate(float rate);

    // Get the rate of the bill
    float getRate() const;
};

#endif 
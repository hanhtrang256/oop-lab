#ifndef BUSINESS_GATES_H
#define BUSINESS_GATES_H

#include "Gates.h"

class BusinessGates : public Gates {
private:
    float unitPrice;
    int quantity;
public:
    BusinessGates();
    BusinessGates(float unitPrice, int quantity);
    std::string getKeeper() const override;
    std::string getType() const override;
    float getCost() const override;
    void input() override;
    void input(const std::string &info) override;
    void output() const override;
};

#endif // BUSINESS_GATES_H
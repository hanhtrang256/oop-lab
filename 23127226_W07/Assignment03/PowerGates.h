#ifndef POWER_GATES_H
#define POWER_GATES_H

#include "Gates.h"

class PowerGates : public Gates {
private:
    float strength;
    float reduce;
public:
    PowerGates();
    PowerGates(float strength, float reduce);
    std::string getKeeper() const override;
    std::string getType() const override;
    float getCost() const override;
    float getStrength() const;
    void input() override;
    void input(const std::string &info) override;
    void output() const override;
};

#endif // POWER_GATES_H
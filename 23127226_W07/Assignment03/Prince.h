#ifndef PRINCE_H
#define PRINCE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Gates.h"
#include "BusinessGates.h"
#include "AcademicGates.h"
#include "PowerGates.h"

class Prince {
private:
    float money, IQ, strength;
public:
    Prince();
    Prince(float money, float IQ, float strength);
    void setMoney(float money);
    float getMoney() const;
    void setIQ(float IQ);
    float getIQ() const;
    void setStrength(float strength);
    float getStrength() const;
    void input();
    void output();
    void savePrincess(const std::vector<Gates *> &gates);
};

#endif // PRINCE_H
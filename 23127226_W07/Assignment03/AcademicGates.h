#ifndef ACADEMIC_GATES_H
#define ACADEMIC_GATES_H

#include "Gates.h"

class AcademicGates : public Gates {
private:
    float IQ;
public:
    AcademicGates();
    AcademicGates(float IQ);
    std::string getKeeper() const override;
    std::string getType() const override;
    float getCost() const override;
    void input() override;
    void input(const std::string &info) override;
    void output() const override;
};

#endif // ACADEMIC_GATES_H
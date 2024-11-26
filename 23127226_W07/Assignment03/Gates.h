#ifndef GATE_H
#define GATE_H

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

class Gates {
public:
    Gates();
    virtual ~Gates() = default;
    virtual std::string getKeeper() const = 0;
    virtual std::string getType() const = 0;
    virtual float getCost() const;
    virtual void input() = 0; // types by user
    virtual void input(const std::string &info) = 0; // get information from a string
    virtual void output() const;
};

#endif // GATE_H
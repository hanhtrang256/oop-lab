#ifndef CITEMS_H
#define CITEMS_H

#include <iostream>
#include <string>
#include <algorithm>

class CItems {
private:
    std::string name;
    bool isHidden;
    int itemSize;
public:
    CItems();
    CItems(const std::string &name);
    CItems(const std::string &name, int itemSize);
    CItems(const std::string &name, int itemSize, bool isHidden);
    virtual ~CItems() = default;
    virtual std::string getType() const = 0;
    virtual void print(bool printHidden, int padding = 0) const = 0;
    void setName(const std::string &name);
    std::string getName() const;
    virtual void setHidden(bool isHidden, bool applyToChildren);
    bool getHidden() const;
    void setItemSize(int itemSize);
    virtual int getItemSize() const;
};

#endif // CITEMS_H
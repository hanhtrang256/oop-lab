#ifndef CFOLDER_H
#define CFOLDER_H

#include "CItems.h"
#include <vector>

class CFolder : public CItems {
private:
    std::vector<CItems *> items;
public:
    CFolder();
    CFolder(const std::string &name);
    std::string getType() const override;
    void setHidden(bool isHidden, bool applyToChildren) override;
    void print(bool printHidden, int padding = 0) const override;
    int getItemSize() const override;
    void add(CItems *pItem);
    CItems *removeByName(const std::string &itemName);
    CItems *findByName(const std::string &itemName);
};

#endif // CFOLDER_H
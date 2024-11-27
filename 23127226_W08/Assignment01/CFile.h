#ifndef CFILE_H
#define CFILE_H

#include "CItems.h"

class CFile : public CItems {
private:
    std::string readOnly;
    std::string hiddenData;
public:
    CFile();
    CFile(const std::string &name, int itemSize);
    CFile(const std::string &name, int itemSize, const std::string &readOnly, const std::string &hiddenData);
    std::string getType() const override;
    void print(bool printHidden, int padding = 0) const override;
    void setHidden(bool isHidden, bool applyToChildren) override;
    int getItemSize() const override;
};

#endif // CFILE_H
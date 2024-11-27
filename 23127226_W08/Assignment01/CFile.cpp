#include "CFile.h"

CFile::CFile() : CItems(), readOnly(""), hiddenData("") {}

CFile::CFile(const std::string &name, int itemSize) : CItems(name, itemSize), readOnly(""), hiddenData("") {}

CFile::CFile(const std::string &name, int itemSize, const std::string &readOnly, const std::string &hiddenData) : CItems(name, itemSize), readOnly(readOnly), hiddenData(hiddenData) {}

std::string CFile::getType() const { return "File"; }

void CFile::print(bool printHidden, int padding) const {
    for (int i = 0; i < padding; ++i) std::cout << " ";
    std::cout << getType() << " " << getName() << " (" << getItemSize() << " bytes) | ";
    std::cout << "Read only: " << readOnly;
    if (printHidden) std::cout << " | Data: " << hiddenData;
    std::cout << '\n';
}

void CFile::setHidden(bool isHidden, bool applyToChildren) {
    CItems::setHidden(isHidden, applyToChildren);
}

int CFile::getItemSize() const { return CItems::getItemSize(); }

#include "CItems.h"

CItems::CItems() : name(""), itemSize(0), isHidden(false) {}

CItems::CItems(const std::string &name) : name(name), itemSize(0), isHidden(false) {}

CItems::CItems(const std::string &name, int itemSize) : name(name), itemSize(itemSize), isHidden(false) {}

CItems::CItems(const std::string &name, int itemSize, bool isHidden) : name(name), itemSize(itemSize), isHidden(isHidden) {}

void CItems::setName(const std::string &name) { this->name = name; }

std::string CItems::getName() const { return name; }

bool CItems::getHidden() const { return isHidden; }

void CItems::setItemSize(int itemSize) { this->itemSize = itemSize; }

void CItems::setHidden(bool isHidden, bool applyToChildren) { this->isHidden = isHidden; }

int CItems::getItemSize() const { return itemSize; }

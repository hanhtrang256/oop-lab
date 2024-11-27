#include "CFolder.h"

CFolder::CFolder() : items({}) {}

CFolder::CFolder(const std::string &name) : CItems(name), items({}) {}

std::string CFolder::getType() const { return "Folder"; }

void CFolder::setHidden(bool isHidden, bool applyToChildren) {
    CItems::setHidden(isHidden, applyToChildren);
    if (applyToChildren && !items.empty())
        for (auto &item : items)
            item->setHidden(isHidden, applyToChildren); 
}

void CFolder::print(bool printHidden, int padding) const {
    for (int i = 0; i < padding; ++i) std::cout << " ";
    std::cout << getType() << " " << getName() << " (" << getItemSize() << " bytes)\n";
    for (auto &item : items) {
        if (printHidden || !item->getHidden()) {
            item->print(printHidden, padding + 2);
        }
    }
}

int CFolder::getItemSize() const {
    int ret = 0;
    for (auto &item : items) ret += item->getItemSize();
    return ret;
}

void CFolder::add(CItems *pItem) { 
    items.push_back(pItem); 
}

CItems *CFolder::removeByName(const std::string &itemName) {
    for (int i = 0; i < (int)items.size(); ++i) {
        if (items[i]->getName() == itemName) {
            CItems *temp = items[i];
            for (int j = i; j < (int)items.size() - 1; ++j) items[j] = items[j + 1];
            items.pop_back();
            return temp;
        }
        if (items[i]->getType() == "Folder") {
            CItems *trySubFolder = dynamic_cast<CFolder *>(items[i])->removeByName(itemName);
            if (trySubFolder != nullptr) return trySubFolder;
        }
    }
    return nullptr;
}

CItems *CFolder::findByName(const std::string &itemName) {
    for (auto item : items) {
        if (item->getName() == itemName) 
            return item;
        if (item->getType() == "Folder") {
            CItems *trySubFolder = dynamic_cast<CFolder *>(item)->findByName(itemName);
            if (trySubFolder != nullptr) return trySubFolder;
        }
    }
    return nullptr;
}

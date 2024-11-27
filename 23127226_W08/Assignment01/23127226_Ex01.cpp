#include "CItems.h"
#include "CFolder.h"
#include "CFile.h"

int main() {
    CFolder C("C"); // (1)
    CFolder System("System");
    CFolder Windows("Windows");
    CFolder Downloads("Downloads");

    CFile a_txt("a.txt", 123); // (2)
    CFile b_doc("b.doc", 456);
    CFile bmw_svg("bmw.svg", 17000, "An svg file of bmw", "<svg?>");
    CFile racoon_svg("racoon.svg", 17000, "An svg file of racoon", "<svg?>");

    System.add(&a_txt); // (3)
    Windows.add(&b_doc);
    Downloads.add(&bmw_svg);
    Downloads.add(&racoon_svg);

    C.add(&System); // (4)
    C.add(&Windows);
    C.add(&Downloads);
    std::cout << "Content of folder C ->" << '\n';
    bool isPrintHiddenItems = false;
    C.print(isPrintHiddenItems); // print hidden items or not? 1/0 (5)
    std::cout << '\n';

    CItems* p = C.removeByName("System"); // (6)
    if (p == nullptr) {
        std::cout << "Folder System does not exist in folder C!\n";
    }
    else {
        std::cout << "Content of folder C afer removing folder System ->" << '\n';
        C.print(false);
    }
    std::cout << '\n';
    
    p = C.findByName("b.doc"); // (7)
    if (p != NULL) {
        std::cout << "b.doc is found in folder C" << '\n';
    }
    else {
        std::cout << "b.doc is not found in folder C" << '\n';
    }
    std::cout << '\n';

    p = C.findByName("a.txt");
    if (p != NULL) {
        std::cout << "a.txt is found in folder C" << '\n';
    }
    else {
        std::cout << "a.txt is not found in folder C" << '\n';
    }
    std::cout << '\n';

    p = C.findByName("racoon.svg");
    if (p != NULL) {
        std::cout << "racoon.svg is found in folder C" << '\n';
    }
    else {
        std::cout << "racoon.svg is not found in folder C" << '\n';
    }
    std::cout << '\n';

    p = C.findByName("bmw_racoon.svg");
    if (p != NULL) {
        std::cout << "bmw_racoon.svg is found in folder C" << '\n';
    }
    else {
        std::cout << "bmw_racoon.svg is not found in folder C" << '\n';
    }
    std::cout << '\n';


    p = C.findByName("Windows"); // (8)
    bool isHidden;
    bool isAlsoApplyToChildren;
    if (p != NULL) {
        std::cout << "Folder Windows is found. Content of folder Windows ->" << '\n';
        isHidden = true; 
        isAlsoApplyToChildren = false;
        // set HIDDEN to folder p and do not change hidden attributes of its sub-items
        p->setHidden(isHidden, isAlsoApplyToChildren); // (9)
        p->print(false);
        std::cout << '\n';

        // set HIDDEN to folder p and all its items
        isHidden = true; isAlsoApplyToChildren = true;
        p->setHidden(isHidden, isAlsoApplyToChildren); // (10)
        p->print(false);
        std::cout << '\n';
    }
    else {
        std::cout << "Folder Windows is not found" << '\n';
    }

    int CSize = C.getItemSize();
    std::cout << "Size of folder C finally is " << CSize << '\n';
    
    return 0;
}

#include "User.h"

/**
 * @brief Print all user's option
 */
void printUserOption() {
    std::cout << "---------       [USER OPTION]      ---------\n";
    std::cout << "1. Display all products                     \n";
    std::cout << "2. Add new product                          \n";
    std::cout << "3. Delete a product                         \n";
    std::cout << "4. Increase quantity of a product           \n";
    std::cout << "5. Decrease quantity of a product           \n";
    std::cout << "6. Select a product                         \n";
    std::cout << "7. Unselect a product                       \n";
    std::cout << "8. Display total prices of selected product \n"; 
    std::cout << "9. Display user options                     \n";
    std::cout << "10. Load products from file                 \n";
    std::cout << "11. Save orders in a file                   \n";
    std::cout << "12. Add 50% discount to a product           \n";
    std::cout << "13. Exit                                    \n";
}

int getUserInput() {
    int opt; 
    while (true) {
        std::cout << "Enter option: ";
        std::cin >> opt;
        if (opt < 0 || opt > 13) {
            std::cout << "Invalid option. Please type again!!!\n";
            continue;
        }
        break;
    }
    return opt;
}

int main() {
    User user;
    bool programLoop = true;
    while (programLoop) {
        printUserOption(); 
        int opt = getUserInput(); 
        int id;
        std::string filename; 
        switch (opt) {
            case 1: 
                user.output(); 
                std::cout << "Price to pay: " << user.getSelectedPrice() << '\n';
                break;
            case 2:
                user.addProduct();
                break;
            case 3: 
                std::cout << "Enter id of product to delete: ";
                std::cin >> id;
                user.delProduct(id);
                break;
            case 4: 
                std::cout << "Enter id of product to increase quantity: ";
                std::cin >> id;
                user.adjustQuantity(id, +1);
                break;
            case 5: 
                std::cout << "Enter id of product to decrease quantity: ";
                std::cin >> id;
                user.adjustQuantity(id, -1);
                break;
            case 6: 
                std::cout << "Enter id of product to select: ";
                std::cin >> id;
                user.adjustSelect(id, true);
                break;
            case 7: 
                std::cout << "Enter id of product to unselect: ";
                std::cin >> id;
                user.adjustSelect(id, false);
                break;
            case 8: 
                std::cout << "Price to pay: " << user.getSelectedPrice() << '\n';
                break;
            case 13:
                programLoop = false;
                break;
            case 9:
                break;
            case 10:
                std::cout << "Enter file name to load: "; 
                std::cin >> filename;
                std::cout << "Filename is " << filename << '\n';
                user.loadFile(filename);
                break;
            case 11:
                std::cout << "Orders will be saved into orders.txt file!\n";
                user.saveOrders();
                break;
            case 12:
                std::cout << "Enter id of a product to apply promotion: ";
                std::cin >> id;
                user.applyPromotion(id);
                break;
        }
    }
    std::cout << "[PROGRAM IS CLOSED]\n";
    return 0;
}
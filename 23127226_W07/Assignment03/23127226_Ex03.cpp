#include "Game.h"

void printOpt() {
    std::cout << " -------- [SAVING THE PRINCESS] --------\n";
    std::cout << " 1. Play the game                       \n";
    std::cout << " 2. Print out all gates                 \n";
    std::cout << " 3. Exit                                \n";
}

int main() {
    bool gameLoop = true;
    Game game;
    game.inputGate("gates.txt");
    while (gameLoop) {
        printOpt();
        int opt;
        while (true) {
            std::cout << "Enter option: ";
            std::cin >> opt;
            if (opt < 1 || opt > 3) {
                std::cout << "Option must be 1 or 2!\n";
                continue;
            }
            break;
        }
        if (opt == 1) game.savePrincess();
        else if (opt == 3) gameLoop = false; 
        else if (opt == 2) game.outputGate();
    }
    return 0;
}
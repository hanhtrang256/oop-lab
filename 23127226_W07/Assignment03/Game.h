#ifndef GAME_H
#define GAME_H

#include "Gates.h"
#include "BusinessGates.h"
#include "AcademicGates.h"
#include "PowerGates.h"
#include "Prince.h"
#include <vector>
#include <fstream>

class Game {
private:
    std::vector<Gates *> gates;
    Prince *prince; // To optimize memory because it's a game loop
public:
    Game(); 
    Game(const std::vector<Gates *> &gates);
    ~Game();
    void inputGate(); // input by hand
    void inputGate(const std::string &fileName);
    void outputGate() const;
    void savePrincess();
};

#endif // GAME_H
#include "Game.h"

Game::Game() : gates({}), prince(nullptr) {}

Game::Game(const std::vector<Gates *> &gates) : gates(gates), prince(nullptr) {}

Game::~Game() {
    for (int i = 0; i < (int)gates.size(); ++i) 
        delete gates[i];
    delete prince;
}

void Game::inputGate() {
    std::cout << "Number of gates: "; 
    int numGates;
    std::cin >> numGates;
    for (int i = 0; i < numGates; ++i) {
        Gates *gate = nullptr;
        std::cout << "Gate type (bussiness: 0, academic: 1, power: 2): ";
        int type;
        while (true) {
            std::cin >> type;
            if (type < 0 || type > 2) {
                std::cout << "Type must be between 0 and 2. Please type again!!!\n";
                continue;
            }
            break;
        }
        if (type == 0) gate = new BusinessGates();
        else if (type == 1) gate = new AcademicGates();
        else gate = new PowerGates();

        if (gate == nullptr) {
            std::cout << "Gate is nullptr when input by hand!!!\n";
            break;
        }

        gate->input();
        gates.push_back(gate);
    }
}

void Game::inputGate(const std::string &fileName) {
    std::ifstream fin(fileName);
    if (!fin.is_open()) {
        std::cout << "Error opening file " << fileName << '\n';
        return;
    }

    std::string headerLine;
    getline(fin, headerLine); // skip header line

    std::string info;
    std::stringstream buffer;
    while (getline(fin, info)) {
        if (info.empty()) continue; // skip empty line
        Gates *gate = nullptr;

        // Formatting info string to later use stringstream
        for (int i = 0; i < (int)info.size(); ++i) 
            if (info[i] == '|') info[i] = ' ';

        // Check gate type
        buffer.clear();
        buffer.str(info);

        std::string type;
        buffer >> type;

        if (type == "Business") gate = new BusinessGates();
        else if (type == "Academic") gate = new AcademicGates();
        else gate = new PowerGates();

        if (gate == nullptr) {
            std::cout << "Gate is nullptr when input by file!!!\n";
            break;
        }
        gate->input(info);
        gates.push_back(gate);
    }

    fin.close();
}

void Game::outputGate() const {
    std::cout << "[List of Gates]\n";
    for (auto &gate : gates) gate->output();
}

void Game::savePrincess() {
    delete prince; // delete previous prince
    prince = new Prince();
    prince->input();
    prince->savePrincess(gates);
}

#include "Game.h"
#include <algorithm>

Game::Game(std::map<std::string, char> players) {
    dice = std::make_shared<Dice>;
    board = nullptr;
    
    for (auto n : players) {
        players.emplace_back(std::make_shared<Player>(n.first, n.second, 0, dice));
    }
    currentPlayer = players.begin();
    
    
}

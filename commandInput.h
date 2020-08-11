#ifndef COMMAND_INPUT_H
#define COMMAND_INPUT_H

#include "Game.h"
#include <iostream>

class CommandInput {
    std::shared_ptr<Game> game;
  public:
    CommandInput(std::shared_ptr<Game> game);
    void readInput(std::istream & in);
    void purchaseOrNot(std::istream & in, std::string building);
    void auction(std::istream & in, std::string building);
    void notEnoughMoney(std::istream & in, int amount);
    void TimHortons(std::istream & in, shared_ptr<Player> p);
};

#endif

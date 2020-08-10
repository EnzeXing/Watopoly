#ifndef COMMAND_INPUT_H
#define COMMAND_INPUT_H

#include "game.h"
#include <iostream>

class CommandInput {
    std::shared_ptr<Game> game;
  public:
    CommandInput(std::shared_ptr<Game> game);
    void readInput(std::istream in);
    void purchaseOrNot(std::istream in);
    void auction(std::istream in);
    void notEnoughMoney(std::istream in);
};

#endif

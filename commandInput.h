#ifndef COMMAND_INPUT_H
#define COMMAND_INPUT_H

#include "game.h"
#include <iostream>

class commandInput {
    std::shared_ptr<Game> game;
  public:
    void readInput(std::istream in);
    void purchaseOrNot(std::istream in);
    void auction(std::istream in);
    void notEnoughMoney(std::istream in);
};

#endif

#ifndef _BOARD_H_
#define _BOARD_H_

#include <string>
#include <memory>
#include <vector>
#include <map>
#include <iostream>
#include <iomanip>
#include "Property.h"

class commandInput;

class Board {
  std::vector<std::vector<std::string>> board;
  std::shared_ptr<CommandInput> command;

  public:
  Board();
  void Board::setCommand(std::shared_ptr<CommandInput> c);
  void updateImprovement(std::shared_ptr<Academic> academic);
  void updatePlayer(int oldPosition, int newPosition, std::string playerName);
  void printMessage(std::string message, std::ostream & out);
  void drawBoard(std::ostream & out);
};

#endif

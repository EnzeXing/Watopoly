#ifndef _BOARD_H_
#define _BOARD_H_

#include <string>
#include <memory>
#include <vector>
#include <map>
#include <iostream>
#include <iomanip>

class Board {
  std::vector<std::vector<std::string>> board;

  public:
  Board();
  void updateImprovement(std::shared_ptr<Building> building);
  void updatePlayer(int oldPosition, int newPosition, std::string playerName);
  void drawBoard(std::ostream & out);
};

#endif

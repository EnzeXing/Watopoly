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
  void updateImprovement(int position, int improvementNumber);
  void updatePlayer(int position, std::string playerName);
  void drawBoard(std::ostream & out);
};

#endif

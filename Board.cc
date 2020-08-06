#include "Board.h"

class Board {
  std::vector<40, std::vector<7, std::string>> board;
  
  public:
  Board(std::vector<std::shared_ptr<40, Buildings>> b);
};

Board::Board(std::vector<std::shared_ptr<40, Buildings>> b) {
  vector<40, std::vector<7, std::string>>

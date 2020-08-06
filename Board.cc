#include "Board.h"

class Board {
  std::vector<40, std::vector<7, std::string>> board;
  
  public:
  Board(std::vector<std::shared_ptr<40, Buildings>> b);
};

Board::Board(std::vector<std::shared_ptr<40, Buildings>> b) {
  for (int i = 0; i < 40; i++) {
    board[i][0] = "------";
    board[i][1] = 
    
    for (int a = 0; a < 7; a++) {
      board[i][a]
  

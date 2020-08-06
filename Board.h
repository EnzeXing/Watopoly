#include <string>
#include <memory>
#include <vector>

class Board {
  std::vector<40, std::vector<7, std::string>> board;
  
  public:
  Board(std::vector<std::shared_ptr<40, Buildings>> b);
  void updateImprovement(int position, int improvementNumber);
  void updatePlayer(int position, std::string playerName);
  void drawBoard();
};

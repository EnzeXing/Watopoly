#include "commandInput.h"

CommandInput::CommandInput(std::shared_ptr<Game> game) : game{game} {}

void CommandInput::readInput(std::istream in) {
  std::string s;
  while (!in.fail()) {
    in >> s;
    if (s == "roll") {
      game->roll();
    } else if (s == "next") {
      game->nextPlayer();
    } else if (s == "trade") {
      std::string name;
      std::string give;
      std::string get;
      in >> name;
      in >> give;
      in >> get;
      if (!in.fail()) {
        try {
          int giveMoney = std::stoi(give);
          try {
            int getMoney = std::stoi(get);
            std::shared_ptr<Board> board = game->getBoard();
            board->printMessage("Cannot trade money for money!", std::cout);
            continue;
          } catch (std::invalid_argument) {
            
          } catch (std::out_of_range) {
          
          }
        } catch (std::invalid_argument) {
          try {
            int getMoney = std::stoi(get);
            
          } catch (std::invalid_argument) {
          
          } catch (std::out_of_range) {
          
          }
        } catch (std::out_of_range) {
          
        }
      }
    }
  }
}

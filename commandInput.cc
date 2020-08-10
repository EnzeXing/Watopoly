#include "commandInput.h"

CommandInput::CommandInput(std::shared_ptr<Game> game) : game{game} {}

void CommandInput::readInput(std::istream in) {
  std::string s;
  while (!in.fail()) {
    in >> s;
    if (s == "roll") {
      std::shared_ptr<Player> currPlayer = game->currPlayer();
      int dice = currPlayer->roll();
      dice += currPlayer->roll();
      game->movePlayer(dice);
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
          int getMoney = std::stoi(get);
          std::shared_ptr<Board> board = game->getBoard();
          board->printMessage("Cannot trade money for money!", std::cout);
          continue;
        } catch (std::invalid_argument) {
          
        } catch (std::out_of_range) {
          
        }
      }
    }
  }
}

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
      
      in >> name;
    }
  }
}

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
      if (in.fail()) {
        game->printMessage("Not enough arguments.");
        break;
      }
      if (!in.fail()) {
        try {
          int giveMoney = std::stoi(give);
          try {
            int getMoney = std::stoi(get);
            game->printMessage("Cannot trade money for money!");
            continue;
          } catch (std::invalid_argument) {
            game->printMessage("Does " + name + " accept the trade of giving " + get + " in exchange for $" + give + " ?");
            std::string response;
            std::cin >> response;
            if (response == "accept") {
              // do the trade
            } else if (response == "reject") {
              continue;
            } else {
              game->printMessage("Invalid response, trade cancelled.");
              continue;
            }
          } catch (std::out_of_range) {
            game->printMessage("Cannot trade money for money and invalid amount of money to receive.");
            continue;
          }
        } catch (std::invalid_argument) {
          try {
            int getMoney = std::stoi(get);
            game->printMessage("Does " + name + " accept the trade of giving $" + get + " in exchange for " + give + " ?");
            std::string response;
            std::cin >> response;
            if (response == "accept") {
              // do the trade
            } else if (response == "reject") {
              continue;
            } else {
              game->printMessage("Invalid response, trade cancelled.");
              continue;
            }
          } catch (std::invalid_argument) {
            game->printMessage("Does " + name + " accept the trade of giving " + get + " in exchange for " + give + " ?");
            std::string response;
            std::cin >> response;
            if (response == "accept") {
              // do the trade
            } else if (response == "reject") {
              continue;
            } else {
              game->printMessage("Invalid response, trade cancelled.");
              continue;
            }
          } catch (std::out_of_range) {
            game->printMessage("Invalid amount of money to receive.");
            continue;
          }
        } catch (std::out_of_range) {
          game->printMessage("Invalid amount of money to give.");
          continue;
        }
      }
    } else if (s == "improve") {
      std::string buildingName;
      std::string op;
      in >> buildingName;
      in >> op;
      if (in.fail()) {
        game->printMessage("Not enough arguments.");
        break;
      }
      if (op == "sell") {
        try{
          //sellImprovement(buildingName);
        } catch(/*to be added*/) {
          game->printMessage("Cannot sell.");
          continue;
        }
      } else if (op == "buy") {
        try{
          //buyImprovement(buildingName);
        } catch (/*to be added*/) {
          game->printMessage("Cannot buy.");
          continue;
        }
      } else {
        game->printMessage("Invalid operation.");
      }
    } else if (s == "mortgage") {
      std::string buildingName;
      in >> buildingName;
      if (in.fail()) {
        game->printMessage("Not enough arguments.");
        break;
      }
      try {
        //mortgage(buildingName);
      } catch (/*to be added*/) {
        game->printMessage("Cannot mortgage.");
      }
    } else if (s == "unmortgage") {
      std::string buildingName;
      in >> buildingName;
      if (in.fail()) {
        game->printMessage("Not enough arguments.");
        break;
      }
      try {
        //unmortgage(buildingName);
      } catch (/*to be added*/) {
        game->printMessage("Cannot unmortgage.");
      }
    } else if (s == "bankrupt") {
      //to be added;
    } else if (s == "assets") {
      //game->printAssets();
    } else if (s == "all") {
      //game->printAllAssets();
    } else if (s == "save") {
      std::string fileName;
      std::ofstream realFile {fileName};
      game->saveGame(realFile);
    } else if (s == "yes") {
      //game->purchase();
    } else if (s == "no") {
      game->printMessage("Not purchased.");
      game->auction();
    }
  }
}


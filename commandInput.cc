#include "commandInput.h"

CommandInput::CommandInput(std::shared_ptr<Game> game) : game{game} {}

void CommandInput::readInput(std::istream & in) {
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
        } catch(ImprovementException & e) {
          game->printMessage("Cannot sell.");
          continue;
        }
      } else if (op == "buy") {
        try{
          //buyImprovement(buildingName);
        } catch (ImprovementException & e) {
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
      } catch (MortgageException & e) {
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
      } catch (MortgageException & e) {
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
    } else {
      game->printMessage("Invalid input.");
      continue;
    }
  }
}

void CommandInput::purchaseOrNot(std::istream & in, std::string building) {
  std::string option;
  in >> option;
  if (in.fail()) {
    game->printMessage("No option is given, auction activated.");
    auction(std::cin, building);
  }
  if (option == "yes") {
    game->purchase(building);
  } eles if (option == "no") {
    game->printMessage("Not purchased, auction activated.");
    auction(std::cin, building);
  } else {
    game->printMessage("Invalid input, auction activated.");
    auction(std::cin, building);
  }
}

void CommandInput::auction(std::istream & in, std::string building) {
  std::string buyer;
  int price;
  int highestPrice = 0;
  std::string currBuyer;
  
  while(!in.fail()) {
    in >> buyer;
    if (in.fail()) {
      game->printMessage("No more input.");
      if (currBuyer.length() != 0) {
        try {
          game->findPlayer(currBuyer)->giveMoney(nullptr, highestPrice);
          game->tradeBuilding(building, currBuyer);
          break;
        } catch (NoEnoughMoney & e) {
          game->printMessage(currBuyer + " needs $" + e.needAmount + " more to complete purchase");
          in.clear();
          game->printMessage("Redo the auction round, please enter your price again.");
          continue;
        } catch (giveMoneyAlert) {}
      } else {
        in.clear();
        game->printMessage("Redo the auction round, please enter your price again.");
        continue;
      }
    }
    if (game->findPlayer(buyer) == nullptr) {
      game->printMessage("Invalid buyer name, please re-enter.");
      continue;
    }
    
    in >> price;
    if (in.fail()) {
      game->printMessage("Invalid input for price.");
      in.clear();
      continue;
    }
    if (price > highestPrice) {
      highestPrice = price;
      currBuyer = buyer;
    } else {
      game->printMessage("Need to spend more money than $" + highestPrice);
      continue;
    }
  }
}

void CommandInput::notEnoughMoney(std::istream & in, int amount) {
  int currAmount = amount;
  std::string option;
  while (!in.fail() && amount > 0) {
    in >> option;
    if (in.fail()) {
      
    }
  }
}

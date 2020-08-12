#include "commandInput.h"

CommandInput::CommandInput(std::shared_ptr<Game> game) : game{game} {
  game->getBoard()->setCommand(this);
}

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
              try {
                // do the trade give money, receive building
                game->trade(name, giveMoney, get);
              } catch (WrongBuildingException) { 
                continue; 
              } catch (NoEnoughMoney n) {
                game->printMessage("You total worth is not enough!");
                continue;
              }
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
              // do the trade give building receive money
              try {
                game->trade(name, give, getMoney); 
              } catch (WrongBuildingException) { 
                continue;
              } catch (NoEnoughMoney n) {
                game->printMessage("You total worth is not enough!");
                continue;
              }
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
              try {
                // do the trade give building, receive building
                game->trade(name, give, get);
              } catch (WrongBuildingException) { 
                continue; 
              } catch (NoEnoughMoney n) {
                game->printMessage("You total worth is not enough!");
                continue;
              }
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
          game->sellImprovement(buildingName);
        } catch(WrongBuildingException & e) {
          continue;
        }
      } else if (op == "buy") {
        try{
          game->buyImprovement(buildingName);
        } catch (WrongBuildingException & e) {
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
        game->mortgage(buildingName);
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
        game->unmortgage(buildingName);
      } catch (MortgageException & e) {
        game->printMessage("Cannot unmortgage.");
      }
    } else if (s == "bankrupt") {
      game->printMessage("Your total worth is positive so bankruptcy cannot be declared!");
    } else if (s == "assets") {
      //game->printAssets();
    } else if (s == "all") {
      //game->printAllAssets();
    } else if (s == "save") {
      std::string fileName;
      in >> fileName;
      if (in.fail()) {
        game->printMessage("Need a file to store the information.");
        break;
      }
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
  } else if (option == "no") {
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
          game->printMessage(currBuyer + " needs $" + std::to_string(e.needAmount) + " more to complete purchase");
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
      game->printMessage("Need to spend more money than $" + std::to_string(highestPrice));
      continue;
    }
  }
}

bool CommandInput::NotEnoughMoney(std::istream & in, int amount, std::string playerName) {
  if (game->totalAsset() < amount) {
    //game->bankrupt(playerName);
    return false;
  }
  int currAmount = amount;
  std::string option;
  in >> option;
  while (!in.fail() && currAmount > 0) {
    if (option == "improve") {
      // sell improvement
      std::string buildingName;
      std::string m;
      in >> buildingName;
      in >> m;
      if (m == "sell") {
        try {
          int temp = game->sellImprovement(buildingName);
          currAmount -= temp;
        } catch (WrongBuildingException & w1) {
          continue;
        }
      } else {
        continue;
      }
    } else if (option == "mortgage") {
      // do mortgage
      std::string buildingName;
      in >> buildingName;
      try {
        int temp = game->mortgage(buildingName);
        currAmount -= temp;
      } catch (WrongBuildingException & w1) {
        continue;
      }
    } else if (option == "trade") {
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
            game->printMessage("Currently You can only exchange building for money ...");
            continue;
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
              // do the trade give building receive money
              game->trade(name, give, getMoney);
              continue;
            } else if (response == "reject") {
              continue;
            } else {
              game->printMessage("Invalid response, trade cancelled.");
              continue;
            }
          } catch (std::invalid_argument) {
            game->printMessage("Currently You can only exchange building for money ...");
            continue;
          } catch (std::out_of_range) {
            game->printMessage("Invalid amount of money to receive.");
            continue;
          }
        } catch (std::out_of_range) {
          game->printMessage("Invalid amount of money to give.");
          continue;
        }
      }
    } else {
      game->printMessage("Invalid option!");
      continue;
    }
  }
  return true;
}


void CommandInput::TimHortons(std::istream & in) {
  
  // player has been in the line for 3 rounds
  // ...
  
    game->printMessage("You are in the DC Tims Line :(\nDo you want to roll dice, pay $50 or use a Roll Up the Rim Cup?");
    std::string command;
    in >> command;
    if (command == "roll") {
      if (game->rollDouble()) {
        game->printMessage("Your rolled doubles!\nYou are out of the line!");
        game->leaveLine();
      } else {
        game->printMessage("Your didn't roll doubles...\nYou are still in the line ...");
        game->stayInLine();
      }
    } else if (command == "pay") {
      game->buyCoffee();
      game->printMessage("You payed $50!\nYou are out of the line!");
    } else if (command == "use") {
      game->useRimCup();
      game->printMessage("You used a Roll Up the Rim Cup!\nYou are out of the line!");
    }
}

void CommandInput::payTuition(std::istream & in) {
  game->printMessage("You need to pay tuition :(\nDo you want to pay $300(A) or 10% of your total worth(B)?");
  std::string command;
  game->howToPayTuition(command);
}
    
    
  
  
  
  

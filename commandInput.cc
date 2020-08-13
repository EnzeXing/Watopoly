#include "commandInput.h"
#include <fstream>
#include <algorithm>

CommandInput::CommandInput(std::shared_ptr<Game> game) : game{game} {
  game->getBoard()->setCommand(this);
}

void CommandInput::readInput(std::istream & in, bool testing) {
  bool roll = false;
  std::string s;
  std::string line;
  while (getline(in, line)) {
    std::istringstream s1{line};
    s1 >> s;
    if (s == "roll") {
      if (!roll) {
        if (!testing) {
            int dice1 = game->roll();
            int dice2 = game->roll();
            game->movePlayer(dice1 + dice2);
            roll = true;
        } else {
            int dice1;
            int dice2;
            if (!(s1 >> dice1)) {
                dice1 = game->roll();
                dice2 = game->roll();
                game->movePlayer(dice1 + dice2);
                roll = true;
            } else if (!(s1 >> dice2)) {
                dice2 = game->roll();
                game->movePlayer(dice1 + dice2);
                roll = true;
            } else {
                game->movePlayer(dice1 + dice2);
                roll = true;
            }
        }
        
      } else {
        game->printMessage("You have already rolled!");
      }
    } else if (s == "next") {
      game->nextPlayer();
      roll = false;
    } else if (s == "trade") {
      std::string name;
      std::string give;
      std::string get;
      s1 >> name;
      s1 >> give;
      s1 >> get;
      if (s1.fail()) {
        game->printMessage("Not enough arguments.");
        break;
      }
      if (!s1.fail()) {
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
      s1 >> buildingName;
      s1 >> op;
      if (s1.fail()) {
        game->printMessage("Not enough arguments.");
        break;
      }
      if (op == "sell") {
        try{
          game->sellImprovement(playerName, buildingName);
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
      s1 >> buildingName;
      if (s1.fail()) {
        game->printMessage("Not enough arguments.");
        break;
      }
      try {
        game->mortgage(playerName, buildingName);
      } catch (MortgageException & e) {
        game->printMessage("Cannot mortgage.");
      }
    } else if (s == "unmortgage") {
      std::string buildingName;
      s1 >> buildingName;
      if (s1.fail()) {
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
      s1 >> fileName;
      if (s1.fail()) {
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
  std::string secondOp;
  int price;
  int highestPrice = 0;
  std::string currBuyer;
  std::vector<std::string> playerNames = game->getPlayerNames();
  
  while(!in.fail()) {
    in >> buyer;
    in >> secondOp;
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
    
    if (secondOp == "withdraw") {
      if (currBuyer != buyer) {
        playerNames.erase(std::find(playerNames.begin(), playerNames.end(), buyer));
      } else {
        game->printMessage("You are the hightest bidder, cannot withdraw.");
        continue;
      }
    } else {
      try {
        price = stoi(secondOp);
      } catch (std::invalid_argument) {
        game->printMessage("Invalid input, type again.");
        continue;
      } catch (std::out_of_range) {
        game->printMessage("Invalid number of money.");
        continue;
      }      
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

bool CommandInput::NotEnoughMoney(std::istream & in, int amount, std::string playerName, std::string toPlayer) {
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
          int temp = game->sellImprovement(playerName, buildingName);
          currAmount -= temp;
        } catch (WrongBuildingException & w1) {
          game->printMessage("You don't own the building" + buildingName);
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
        int temp = game->mortgage(playerName, buildingName);
        currAmount -= temp;
      } catch (WrongBuildingException & w1) {
        continue;
      }
    } else {
      game->printMessage("Invalid option!");
      continue;
    }
  }
  if (game->totalAsset(playerName) < currAmount) {
    game->printMessage("You do not have enough money to pay the money, type \"bankrupt\" to declare bankruptcy.");
    std::string bkrpt;
    in >> bkrpt;
    if (bkrpt == "bankrupt") {
      game->bankrupt(playerName, toPlayer);
    } else {
      game->printMessage("Invalid input, forced bankruptcy.");
      game->bankrupt(playerName, toPlayer);
    }
    return false;
  }
  return true;
}


void CommandInput::TimHortons(std::istream & in, int currentRound) {
  
  // player has been in the line for 3 rounds
  // ...
    if (currentRound == 3) {
        game->printMessage("It is your third turn in the DC Tims line. If you do not roll doubles, you must leave the line by either paying $50 or using a Roll Up the Rim cup.\nDo you want to roll dice, pay $50 or use a Roll Up the Rim Cup?");
        std::string command;
        in >> command;
        if (command == "roll") {
            game->leaveLine();
            int dice1 = game->roll();
            int dice2 = game->roll();
            if (dice1 == dice2) {
                game->printMessage("Your rolled doubles!\nYou are out of the line!");
            } else {
                game->printMessage("Your didn't roll doubles...\nYou need to pay $50 or using a Roll Up the Rim Cup.");
                while (true) {
                    in >> command;
                    if (command == "pay") {
                        try {
                            game->buyCoffee();
                        } catch (NoEnoughMoney & e) {
                            if (NotEnoughMoney(std::cin, e.needAmount, e.playerName, "Bank")) {
                                game->buyCoffee();
                            } else break;
                        }
                        
                        game->printMessage("You payed $50!\nYou are out of the line!");
                        game->movePlayer(dice1 + dice2);
                        break;
                    } else {
                        try {
                            game->useRimCup();
                            game->printMessage("You used a Roll Up the Rim Cup!\nYou are out of the line!");
                            game->movePlayer(dice1 + dice2);
                        } catch (NoEnoughCup & e) {
                            game->printMessage(e.message);
                            continue;
                        }
                    }
                }
            }
       }
    } else if (command == "pay") {
      try {
           game->buyCoffee();
      } catch (NoEnoughMoney & e) {
           if (NotEnoughMoney(std::cin, e.needAmount, e.playerName, "Bank")) {
                game->buyCoffee();
           } else return;
      }
                        
      game->printMessage("You payed $50!\nYou are out of the line!");
    } else if (command == "use") {
      try {
          game->useRimCup();
      } catch (NoEnoughCup & e) {
          game->printMessage(e.message);
          TimHortons(in, currentRound);
      }
      
      game->printMessage("You used a Roll Up the Rim Cup!\nYou are out of the line!");
    }
    
    game->printMessage("You are in the DC Tims Line :(\nDo you want to roll dice, pay $50 or use a Roll Up the Rim Cup?");
    std::string command;
    in >> command;
    if (command == "roll") {
      if (game->rollDouble()) {
        game->printMessage("Your rolled doubles!\nYou are out of the line!");
      } else {
        game->printMessage("Your didn't roll doubles...\nYou are still in the line ...");
        game->stayInLine();
      }
    } else if (command == "pay") {
      try {
           game->buyCoffee();
      } catch (NoEnoughMoney & e) {
           if (NotEnoughMoney(std::cin, e.needAmount, e.playerName, "Bank")) {
                game->buyCoffee();
           } else return;
      }
      game->printMessage("You payed $50!\nYou are out of the line!");
    } else if (command == "use") {
      try {
          game->useRimCup();
      } catch (NoEnoughCup & e) {
          game->printMessage(e.message);
          TimHortons(in, currentRound);
      }
      game->printMessage("You used a Roll Up the Rim Cup!\nYou are out of the line!");
    }
}
    
    
  
  
  
  

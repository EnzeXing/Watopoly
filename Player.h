#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "Dice.h"

class Player {
  private:
    std::string name;
    std::string symbol;
    int money;
    std::map<std::string, int> properties;
    int position;
    int rimCup;
    int TimRound;
    std::shared_ptr<Dice> dice;
  public:
    Player(std::string name, std::string symbol, int position, std::shared_ptr<Dice> dice, int TimCup, int money, int TimRound);
    std::string getName();
    std::string getSymbol();
    int getMoney();
    void giveMoney(std::shared_ptr<Player> other, int amount); // if other is nullptr, give money to bank, note exception
    void addMoney(int amount);
    unsigned int getProperties(std::string type);
    void addBuilding(std::string type);
    void loseBuilding(std::string type);
    bool hasFullMonopoly(std::string type);
    void move(int position);
    void visit(Building & b); // call b.accept(*this)
    int getCup();
    void addCup();
    void removeCup(); // Note exception
    int getTimRound();
    void stayInLine();
    void leaveLine();
    int roll();
};

#endif

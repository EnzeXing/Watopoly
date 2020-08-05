#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <vector>
#include <map>
#include <memory>

class Player {
  private:
    std::string name;
    char symbol;
    int money;
    std::map<std::string, int> properties;
    int position;
    int rimCup;
  public:
    std::string getName();
    char getSymbol();
    int getMoney();
    void giveMoney(std::shared_ptr<Player> other, int amount); // if other is nullptr, give money to bank, note exception
    void addMoney(int amount);
    void visit(Building & b); // call b.accept(*this)
    void addCup();
    void removeCup(); // Note exception
};

#endif

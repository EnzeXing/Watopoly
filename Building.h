#ifndef _BUILDING_H_
#define _BUILDING_H_
#include <string>
#include <memory>
#include <algorithm>
#include <iostream>

class Player;

class Building {
  private:
    std::string name;
    int position;
  public:
    Building(std::string name, int position);
    std::string getName();
    int getPosition();
    virtual void accept(Player & p) = 0;
};

#endif

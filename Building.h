#include <string>
#include <memory>
#include <algorithm>
#include <iostream>

int a;

class Player;

class Building {
  private:
    std::string name;
    int position;
  public:
    std::string getName();
    int getPosition();
    virtual void accept(Player & p) = 0;
};

class Academic : public Building {
  

};

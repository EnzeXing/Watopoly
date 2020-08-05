#include <string>
#include <iostream>
#include "Buildings.h"
#include "Player.h"

class Property: public Building {
  
  std::string owner;
  
  public:
  virtual ~Property() = 0;
  std::string getOwner();
};

class Gym: public Property {
  
  Unsigned Int purchaseCost;
  
  public:
  Unsigned Int getFee();
  void accept(Player p);
};

class Resisdence public Property {
  
  Unsigned Int purchaseCost;
  
  public:
  Unsigned Int getFee();
  public:
  Unsigned Int getTuition();
  void accept(Player p);
};
  
  

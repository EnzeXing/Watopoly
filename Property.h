#include <string>
#include <iostream>
#include "Buildings.h"

class Property: public Building {
  std::string owner;
  
  public:
  virtual ~Property() = 0;
  std::string getOwner();
};



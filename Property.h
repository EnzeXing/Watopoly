#ifndef _PROPERTY_H_
#define _PROPERTY_H_

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Buildings.h"
#include "Player.h"

class Property: public Building {
  std::shared_ptr<Player> owner;
  
  public:
  virtual ~Property() = 0;
  std::shared_ptr<Player> getOwner();
};

class AcademicBuilding : public Property {
  private:
    std::string monopoly;
    unsigned int improvement;
    unsigned int purchaseCost;
    unsigned int improvementCost;
    std::vector<6, unsigned int> tuition;
  public:
    std::string getMonopoly();
    unsigned int getImprovement();
    unsigned int getPurchaseCost();
    unsigned int getImprovementCost();
    unsigned int getTuition();
    virtual void accept(Player & p) override;
    void improve();
};

class Gym: public Property {
  unsigned int purchaseCost;
  
  public:
  unsigned int getFee();
  virtual void accept(Player & p) override;
};
  
class Residence: public Property {
  unsigned int purchaseCost;
  
  public:
  unsigned int getPurchaseCost();
  unsigned int getRent();
  virtual void accept(Player & p) override;
};
  


#endif

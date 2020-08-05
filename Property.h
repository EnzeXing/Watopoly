#include <string>
#include <iostream>
#include <vector>
#include "Buildings.h"

class Property: public Building {
  std::string owner;
  
  public:
  virtual ~Property() = 0;
  std::string getOwner();
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
    virtual void accept(Player & player) override;
    void improve();
};

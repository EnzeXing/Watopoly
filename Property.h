#ifndef _PROPERTY_H_
#define _PROPERTY_H_

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Building.h"
#include "Player.h"
#include "Exception.h"

class Property: public Building {
  std::shared_ptr<Player> owner;
  unsigned int purchaseCost;
  std::string monopoly;
  bool mortgage;
  
  public:
    Property(std::string name, int position, std::shared_ptr<Player> owner, unsigned int p, std::string monopoly);
    virtual ~Property() = 0;
    std::shared_ptr<Player> getOwner();
    void setOwner(std::shared_ptr<Player> owner);
    unsigned int getPurchaseCost();
    std::string getMonopoly();
    bool mortgage();
};

class Academic : public Property {
  private:
    
    unsigned int improvement;
    unsigned int improvementCost;
    std::vector<unsigned int> tuition;
  public:
    Academic(std::string name, int position, std::shared_ptr<Player> owner, std::string monopoly, 
                     unsigned int p, unsigned int improvementCost, std::vector<unsigned int > tuition);
    unsigned int getImprovement();
    unsigned int getImprovementCost();
    unsigned int getTuition();
    virtual void accept(Player & p) override;
    void improve(std::string s);
    void setImprovement(int improvement);
};

class Gym: public Property {
  public:
  Gym(std::string name, int position, std::shared_ptr<Player> owner);
  unsigned int getFee(Player & p);
  virtual void accept(Player & p) override;
};
  
class Residence: public Property {
  public:
  Residence(std::string name, int position, std::shared_ptr<Player> owner);
  unsigned int getRent();
  virtual void accept(Player & p) override;
};
  


#endif

#ifndef NONPROPERTY_H
#define NONPROPERTY_H
#include "Building.h"
#include "Player.h"
#include <vector>
#include <memory>

class NonProperty : public Building {
  public:
    virtual ~NonProperty() = 0;
};

class Tuition : public NonProperty {
  public:
    Tuition(std::string name, int position);
    virtual ~Tuition() override;
    virtual accept(Player & p) override;
};

class TimHortons : public NonProperty {
  public:
    TimHortons(std::string name, int position);
    virtual ~TimHortons() override;
    virtual accept(Player & p) override;
};

class GoToTims : public NonProperty {
  public:
    GoToTims(std::string name, int position);
    virtual ~GoToTims() override;
    virtual accept(Player & p) override;
};

class SLC : public NonProperty {
  shared_ptr<RimCup> rimCup;
  public:
    SLC(std::string name, int position);
    virtual ~SLC() override;
    virtual accept(Player & p) override;
};

class OSAP : public NonProperty {
  public:
    OSAP(std::string name, int position);
    virtual ~OSAP() override;
    virtual accept(Player & p) override;
};

class CoopFee : public NonProperty {
  public:
    CoopFee(std::string name, int position);
    virtual ~CoopFee() override;
    virtual accept(Player & p) override;
};

class Goose : public NonProperty {
  public:
    Goose(std::string name, int position);
    virtual ~Goose() override;
    virtual accept(Player & p) override;
};

class NeedlesHall : public NonProperty {
  shared_ptr<RimCup> rimCup;
  public:
    NeedlesHall(std::string name, int position);
    virtual ~NeedlesHall() override;
    virtual accept(Player & p) override;
};

class RimCup {
  int ActiveCup;
  public:
  void giveCup(Player & p);
  void receiveCup(Player & p);
};
  
  
  
  

#endif

#ifndef NONPROPERTY_H
#define NONPROPERTY_H
#include "Building.h"
#include "Player.h"
#include <vector>
#include <memory>

class RimCup {
  int ActiveCup;
  public:
  void giveCup(Player & p);
  void receiveCup(Player & p);
};

class NonProperty : public Building {
  public:
    NonProperty(std::string name, int position);
    virtual ~NonProperty() = 0;
};

class Tuition : public NonProperty {
  public:
    Tuition(std::string name, int position);
    virtual ~Tuition() override;
    virtual void accept(Player & p) override;
};

class TimHortons : public NonProperty {
  public:
    TimHortons(std::string name, int position);
    virtual ~TimHortons() override;
    virtual void accept(Player & p) override;
};

class GoToTims : public NonProperty {
  public:
    GoToTims(std::string name, int position);
    virtual ~GoToTims() override;
    virtual void accept(Player & p) override;
};

class SLC : public NonProperty {
  std::shared_ptr<RimCup> rimCup;
  public:
    SLC(std::string name, int position, std::shared_ptr<RimCup> r);
    virtual ~SLC() override;
    virtual void accept(Player & p) override;
};

class OSAP : public NonProperty {
  public:
    OSAP(std::string name, int position);
    virtual ~OSAP() override;
    virtual void accept(Player & p) override;
};

class CoopFee : public NonProperty {
  public:
    CoopFee(std::string name, int position);
    virtual ~CoopFee() override;
    virtual void accept(Player & p) override;
};

class Goose : public NonProperty {
  public:
    Goose(std::string name, int position);
    virtual ~Goose() override;
    virtual void accept(Player & p) override;
};

class NeedlesHall : public NonProperty {
  std::shared_ptr<RimCup> rimCup;
  public:
    NeedlesHall(std::string name, int position, std::shared_ptr<RimCup> r);
    virtual ~NeedlesHall() override;
    virtual void accept(Player & p) override;
};
  
  
  

#endif

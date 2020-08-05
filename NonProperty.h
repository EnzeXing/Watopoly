#ifndef NONPROPERTY_H
#define NONPROPERTY_H
#include "Building.h"
#include <vector>

class NonProperty : public Building {
  public:
    virtual ~NonProperty() = 0;
};

class Tuition : public NonProperty {
  public:
    virtual ~Tuition() override;
    virtual accept(Player & p) override;
};

class TimHortons : public NonProperty {
  public:
    virtual ~TimHortons() override;
    virtual accept(Player & p) override;
};

class GoToTims : public NonProperty {
  public:
    virtual ~GoToTims() override;
    virtual accept(Player & p) override;
};

class SLC : public NonProperty {
  public:
    virtual ~SLC() override;
    virtual accept(Player & p) override;
};

class OSAP : public NonProperty {
  public:
    virtual ~OSAP() override;
    virtual accept(Player & p) override;
};

class CoopFee : public NonProperty {
  public:
    virtual ~CoopFee() override;
    virtual accept(Player & p) override;
};

class Goose : public NonProperty {
  public:
    virtual ~Goose() override;
    virtual accept(Player & p) override;
};

class NeedlesHall : public NonProperty {
  public:
    virtual ~NeedlesHall() override;
    virtual accept(Player & p) override;
};

#endif

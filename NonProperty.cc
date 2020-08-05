#include "NonProperty.h"

Tuition::~Tuition() {}

Tuition::accept(Player & p) {
  throw WatopolyException("Tuition");
}

TimHortons::~TimHortons() {}

TimHortons::accept(Player & p) {
  //to be added
}

GoToTims::~GoToTims() {}

GoToTims::accept(Player & p) {
  throw WatopolyException("Move");
}

SLC::~SLC(){}

SLC::accept(Player & p) {
  throw WatopolyException("SLC");
}

OSAP::~OSAP(){}

OSAP::accept(Player & p) {
  p->addMoney(200);
}

CoopFee::~CoopFee(){}

CoopFee::accept(Player & p) {
  p->giveMoney(nullptr, 150);
}

Goose::~Goose(){}

Goose::accept(Player & p) {
  throw WatopolyException("Attacked by geese!");
}

NeedlesHall::~NeedlesHall(){}

NeedlesHall::accept(Player & p) {
  //to be added, check the probability and change the amount of money
}

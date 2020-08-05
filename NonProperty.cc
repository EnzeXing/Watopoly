#include "NonProperty.h"
#include <cstdlib>

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
  int num = rand() % 24;
  if (num >= 0 && num <= 2) {
    p->move(-3);
  } else if (num >= 3 && num <= 6) {
    p->move(-2);
  } else if (num >= 7 && num <= 10) {
    p->move(-1);
  } else if (num >= 11 && num <= 13) {
    p->move(1);
  } else if (num >= 14 && num <= 17) {
    p->move(2);
  } else if (num >= 18 && num <= 21) {
    p->move(3);
  } else if (num == 22) {
    p->move(8);
  } else {
    p->move(-2);
  }
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

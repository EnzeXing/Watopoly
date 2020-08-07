#include "NonProperty.h"
#include <cstdlib>
#include <time.h>

Tuition::Tuition(std::string name, int position) : Building{name, positon} {}
Tuition::~Tuition() {}

Tuition::accept(Player & p) {
  throw WatopolyException("Tuition");
}

TimHortons::TimHortons(std::string name, int position) : Building{name, positon} {}

TimHortons::~TimHortons() {}

TimHortons::accept(Player & p) {
  throw WatopolyException("Waiting in the line!");
}

GoToTims::GoToTims(std::string name, int position) : Building{name, positon} {}

GoToTims::~GoToTims() {}

GoToTims::accept(Player & p) {
  p->move(20);
}

SLC::SLC(std::string name, int position) : Building{name, positon} {}

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

OSAP::OSAP(std::string name, int position) : Building{name, positon} {}

OSAP::~OSAP(){}

OSAP::accept(Player & p) {
  p->addMoney(200);
}

CoopFee::CoopFee(std::string name, int position) : Building{name, positon} {}

CoopFee::~CoopFee(){}

CoopFee::accept(Player & p) {
  p->giveMoney(nullptr, 150);
}

Goose::Goose(std::string name, int position) : Building{name, positon} {}

Goose::~Goose(){}

Goose::accept(Player & p) {
  throw WatopolyException("Attacked by geese!");
}

NeedlesHall::NeedlesHall(std::string name, int position) : Building{name, positon} {}

NeedlesHall::~NeedlesHall(){}

NeedlesHall::accept(Player & p) {
  srand (time(NULL));
  int num = rand() % 18;
  if (num == 0) {
    p->addMoney(-200);
  } else if (num >= 1 && num <= 2) {
    p->addMoney(-100);
  } else if (num >= 3 && num <= 5) {
    p->addMoney(-50);
  } else if (num >= 6 && num <= 11) {
    p->addMoney(25);
  } else if (num >= 12 && num <= 14) {
    p->addMoney(50);
  } else if (num >= 15 && num <= 16) {
    p->addMoney(100);
  } else {
    p->addMoney(200);
  }
}

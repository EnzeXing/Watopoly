#include "NonProperty.h"

Tuition::~Tuition() {}

Tuition::accept(Player p) {
  throw WatopolyException("Tuition");
}

TimHortons::TimHortons() {}

TimHortons::~TimHortons() {}

TimHortons::accept(Player & p) {
  
}

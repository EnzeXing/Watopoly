#include "Dice.h"


int Dice::roll() {
  int a;
  strand (time(NULL));
  a = rand() % 6 + 1;
  return a;
  }

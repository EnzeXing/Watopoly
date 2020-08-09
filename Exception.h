#include <string>

class WatopolyException {
  public:
    std::string message;
};

class NotEnoughMoney : public WatopolyException {
  public:
    int needAmount;
};

class NotEnoughCup : public WatopolyException {};

class TuitionException : public WatopolyException {};

class TimHortonsException : public WatopolyException {};

class getRimCup : public WatopolyException {};

class SLCException : public WatopolyException {
  public:
    int steps;
};

class GooseException : public WatopolyException {};

class NeedlesHallException : public WatopolyException {
  public:
    int amount;
};

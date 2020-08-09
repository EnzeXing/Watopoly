#include <string>

class WatopolyException {
  public:
  std::string message;
  WatopolyException(std::string m);
};

class NoOwner : public Watopoly {
  public:
  NoOwner(std::string m);
};

class NoEnoughMoney : public WatopolyException {
  public:
  int needAmount;
  NoEnoughMoney(std::string m, int a);
};

class NoEnoughCup : public WatopolyException {
  public:
  NoEnoughCup(std::string m);
};

class TuitionException : public WatopolyException {
  public:
  TuitionException(std::string m);
};

class TimHortonsException : public WatopolyException {
  public:
  TimHortonsException(std::string m);
};

class getRimCup : public WatopolyException {
  public:
  getRimCup(std::string m);
};

class SLCException : public WatopolyException {
  public:
  int steps;
  SLCException(std::string m, int s);
};

class GooseException : public WatopolyException {
  public:
  GooseException(std::string m);
};

class NeedlesHallException : public WatopolyException {
  public:
  int amount;
  NeedlesHallException(std::string m);
};

#ifndef _Exception_H_
#define _Exception_H_

#include <string>

class WatopolyException {
  public:
  std::string message;
  WatopolyException(std::string m);
};

class NoOwner : public WatopolyException {
  public:
  NoOwner(std::string m);
};

class NoEnoughMoney : public WatopolyException {
  public:
  int needAmount;
  NoEnoughMoney(std::string m, int a);
};

class giveMoneyAlert : public WatopolyException {
  public:
  giveMoneyAlert(std::string m);
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
  NeedlesHallException(std::string m, int a);
};

class ImprovementException : public WatopolyException {
  public:
  ImprovementException(std::string m);
};

class WrongBuildings : public WatopolyException {
  public:
  WrongBuildings(std::string m);
};

#endif

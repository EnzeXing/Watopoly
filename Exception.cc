#include "Exception.h"

WatopolyException::WatopolyException(std::string m) : message{m} {}

NoOwner::NoOwner(std::string m) : WatopolyException(m) {}

NoEnoughMoney::NoEnoughMoney(std::string m, int a) : WatopolyException(m), needAmount{a} {}

NoEnoughCup::NoEnoughCup(std::string m) : WatopolyException(m) {}

TuitionException::TuitionException(std::string m): WatopolyException(m) {}

TimHortonsException::TimHortonsException(std::string m) : WatopolyException(m) {}

getRimCup::getRimCup(std::string m) : WatopolyException(m) {}

SLCException::SLCException(std::string m, int s) : WatopolyException(m), steps{s} {}

GooseException::GooseException(std::string m) : WatopolyException(m) {}

NeedlesHallException::NeedlesHallException(std::string m) : WatopolyException(m) {}

ImprovementException::ImprovementException(std::string m, int amount) : WatopolyException(m), amount{amount} {}


#include "Exception.h"

WatopolyException::WatopolyException(std::string m) : message{m} {}

NoOwner::NoOwner(std::string m) : WatopolyExeption(m) {}

NoEnoughMoney::NoEnoughMoney(std::string m, int a) : WatopolyExeption(m), needAmount{a} {}

NoEnoughCup::NoEnoughCup(std::string m) : WatopolyExeption(m) {}

TuitionException::TuitionException(std::string m): WatopolyExeption(m) {}

TimHortonsException::TimHortonsException(std::string m) : WatopolyExeption(m) {}

getRimCup::getRimCup(std::string m) : WatopolyExeption(m) {}

SLCException::SLCException(std::string m, int s) : WatopolyExeption(m), steps{s} {}

GooseException::GooseException(std::string m) : WatopolyExeption(m) {}

NeedlesHallException::NeedlesHallException(std::string m) : WatopolyExeption(m) {}


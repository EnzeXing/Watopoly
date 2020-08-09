#include "Exception.h"

WatopolyException::WatopolyExeption(std::string m) : message{m} {}

NoOwner::NoOwner(std::string m) : WatopolyExeption(m) {}

NotEnoughMoney::NotEnoughMoney(std::string m, int a) : WatopolyExeption(m), needAmount{a} {}




#include <string>

class WatopolyException {
  public:
    std::string message;
};

class NotEnoughMoney : public WatopolyException {
  public:
    int needAmount;
};

class NotEnoughCup : public WatopolyException

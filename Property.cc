#include "Property.h"
#include <string>

std::string Property::getOwner() {
    return Owner;
}

void Property::setOwner(std::string p) {
    Owner = p;
}

unsigned int Gym::getFee() {
}

void Gym::accept(Player & p) {
    unsigned int fee = getFee();
    p.addMoney(fee);
}

unsigned int Residence::getPurchaseCost() {
    return purchaseCost;
}

unsigned int Resisdence::getRent() {
}

void Residence::accept(Player p) {
    unsigned int rent = getRent();
    p.addMoney(rent);
}


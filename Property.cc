#include "Property.h"

shared_ptr<Player> Property::getOwner() {
    return Owner;
}

void Property::setOwner(shared_ptr<Player> p) {
    Owner = p;
}

unsigned int Gym::getFee() {
    //under construction
}

void Gym::accept(Player & p) {
    if (owner != &p) {
        unsigned int fee = getFee();
        p.giveMoney(*owner, fee);
    }
}

unsigned int Residence::getPurchaseCost() {
    return purchaseCost;
}

unsigned int Resisdence::getRent() {
    unsigned int residence = owner->getProperties("Residence");
    unsigned int rent = residence * 50;
    return rent;
}

void Residence::accept(Player & p) {
    if (owner != &p) {
        unsigned int rent = getRent();
        p.giveMoney(*owner, rent);
    }
}


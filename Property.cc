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


std::string Academic::getMonopoly() {
    return monopoly;
}

unsigned int Academic::getImprovement() {
    return improvement;
}

unsigned int Academic::getPurchaseCost() {
    return purchaseCost;
}

unsigned int Academic::getImprovementCost() {
    return ImprovementCost;
}

unsigned int Academic::getTuition() {
    int fee = tuition[improvement];
    if ((improvement == 0) && (owner->hasFullMonopoly(monopoly))) {
        return 2 * fee;
    } else {
        return fee;
    }
}

void Academic::improve(std::string s) {
    if (s == "buy") && (improvement < 5){
        improvement++;
        owner->giveMoney(nullptr, improvementCost);
    } else if (s == "sell") && (improvement > 0) {
        improvement--;
        owner->addMoney(improvementCost / 2);
    } else {
        throw WatopolyException("invalid improvement command!");
    }
}

void Academic::accept(Player p) {
    if (owner != &p) {
        unsigned int tuition = getTuition();
        p.giveMoney(*owner, tuition);
    }
}



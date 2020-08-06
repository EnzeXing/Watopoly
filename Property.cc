#include "Property.h"

Property::Property(std::string name, int position, std::shared_ptr<Player> owner) : Building(name, position), owner{owner} {}

shared_ptr<Player> Property::getOwner() {
    return Owner;
}

void Property::setOwner(shared_ptr<Player> p) {
    Owner = p;
}

Gym::Gym(std::string name, int position, std::shared_ptr<Player> owner, unsigned int purchaseCost) : Property(name, position, owner), purchaseCost{purchaseCost} {}

unsigned int Gym::getFee() {
    //under construction
}

void Gym::accept(Player & p) {
    if (owner != &p) {
        unsigned int fee = getFee();
        p.giveMoney(*owner, fee);
    }
}

Residence::Residence(std::string name, int position, std::shared_ptr<Player> owner, unsigned int purchaseCost) : Property(name, position, owner), purchaseCost{purchaseCost} {}

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

Academic::Academic(std::string name, int position, std::shared_ptr<Player> owner, 
         std::string monopoly, int purchaseCost, int improvementCost, 
         std::vector<6, unsigned int > tuition) : Property(name, position, owner), monopoly{monopoly}, improvement{0}, purchaseCost{purchaseCost}, improvementCost{improvementCost}, tuition{tuition} {}

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



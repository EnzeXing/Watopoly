#include "Property.h"

Property::Property(std::string name, int position, std::shared_ptr<Player> owner) : Building(name, position), owner{owner} {}

Property::~Property() {}

std::shared_ptr<Player> Property::getOwner() {
    return owner;
}

void Property::setOwner(std::shared_ptr<Player> p) {
    owner = p;
}

Gym::Gym(std::string name, int position, std::shared_ptr<Player> owner) : Property(name, position, owner), purchaseCost{150} {}

unsigned int Gym::getFee(Player & p) {
    unsigned int diceSum = p.roll() + p.roll();
    if (this->getOwner()->getProperties("Gym") == 1) {
        return diceSum * 4;
    } else {
        return diceSum * 10;
    }
}


void Gym::accept(Player & p) {
    if (this->getOwner() == nullptr) {
        throw NoOwner("This property has no owner yet!");
    }
    if (this->getOwner()->getName() != p.getName()) {
        unsigned int fee = getFee(p);
        p.giveMoney(this->getOwner(), fee);
    }
}


Residence::Residence(std::string name, int position, std::shared_ptr<Player> owner) : Property(name, position, owner), purchaseCost{200} {}

unsigned int Residence::getPurchaseCost() {
    return purchaseCost;
}


unsigned int Residence::getRent() {
    unsigned int residence = this->getOwner()->getProperties("Residence");
    unsigned int rent = residence * 50;
    return rent;
}

void Residence::accept(Player & p) {
    if (this->getOwner() == nullptr) {
        throw NoOwner("This property has no owner yet!");
    }
    if (this->getOwner()->getName() != p.getName()) {
        unsigned int rent = getRent();
        p.giveMoney(this->getOwner(), rent);
    }
}

Academic::Academic(std::string name, int position, std::shared_ptr<Player> owner, 
         std::string monopoly, unsigned int purchaseCost, unsigned int improvementCost, 
         std::vector<unsigned int> tuition) : Property(name, position, owner), monopoly{monopoly}, improvement{0}, purchaseCost{purchaseCost}, improvementCost{improvementCost}, tuition{tuition} {}

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
    return improvementCost;
}

unsigned int Academic::getTuition() {
    int fee = tuition[improvement];
    if ((improvement == 0) && (this->getOwner()->hasFullMonopoly(monopoly))) {
        return 2 * fee;
    } else {
        return fee;
    }
}

void Academic::improve(std::string s) {
    if ((s == "buy") && (improvement < 5)) {
        improvement++;
        this->getOwner()->giveMoney(nullptr, improvementCost);
    } else if ((s == "sell") && (improvement > 0)) {
        improvement--;
        this->getOwner()->addMoney(improvementCost / 2);
    } else {
        //throw WatopolyException("invalid improvement command!");
    }
}

void Academic::setImprovement(int improve) {
    improvement = improve;
}

void Academic::accept(Player & p) {
    if (this->getOwner() == nullptr) {
        throw NoOwner("This property has no owner yet!");
    }
    if (this->getOwner()->getName() != p.getName()) {
        unsigned int tuition = getTuition();
        p.giveMoney(this->getOwner(), tuition);
    }
}


